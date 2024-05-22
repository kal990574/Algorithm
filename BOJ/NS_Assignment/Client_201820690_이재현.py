import socket
from Crypto.PublicKey import RSA
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes
from Crypto.Protocol.KDF import scrypt
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256

# RSA 서명 검증
def rsa_verify(data, signature, public_key):
    key = RSA.import_key(public_key)
    h = SHA256.new(data)
    try:
        pkcs1_15.new(key).verify(h, signature)
        print("서명 검증 성공")
    except (ValueError, TypeError):
        print("서명 검증 실패")

# AES 암호화
def aes_encrypt(data, key):
    cipher = AES.new(key, AES.MODE_CBC)
    ct_bytes = cipher.encrypt(pad(data, AES.block_size))
    iv = cipher.iv
    return iv + ct_bytes

# AES 복호화
def aes_decrypt(ct, key):
    iv = ct[:AES.block_size]
    ct = ct[AES.block_size:]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ct), AES.block_size)
    return pt

# 데이터 전송 함수
def send_data(sock, data):
    length = len(data)
    sock.sendall(length.to_bytes(4, 'big'))
    sock.sendall(data)

# 데이터 수신 함수
def recv_data(sock):
    length = int.from_bytes(sock.recv(4), 'big')
    return sock.recv(length)

# 클라이언트 소켓 설정
def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('localhost', 9999))

    # 서버로부터 RSA 공개키 수신
    server_public_key = recv_data(client)
    print("RSA 공개키 수신")

    # 서버로부터 DHE 파라미터, 서버의 DHE 공개키, RSA 기반 Digital Signature 수신
    G = int.from_bytes(recv_data(client), 'big')
    print("g 수신")
    N = int.from_bytes(recv_data(client), 'big')
    print("n 수신")
    server_dhe = int.from_bytes(recv_data(client), 'big')
    print("dhe 공개키 수신")
    signature = recv_data(client)
    print("RSA 서명 수신")

    # 수신한 데이터와 디지털 서명의 무결성 검증을 통한 안전한 통로 확인
    data_to_verify = f"{G}, {N}, {server_dhe}".encode()
    rsa_verify(data_to_verify, signature, server_public_key)
    
    # 클라이언트의 DHE 공개키 생성
    client_private = get_random_bytes(32)
    client_dhe = pow(G, int.from_bytes(client_private, 'big'), N)
    client_dhe_bytes = client_dhe.to_bytes(256, 'big')

    # 클라이언트의 DHE 공개키 전송
    send_data(client, client_dhe_bytes)

    # AES 암호화에 사용될 공유 비밀키 생성
    shared_key = pow(server_dhe, int.from_bytes(client_private, 'big'), N)
    shared_key = shared_key.to_bytes(32, 'big')

    # AES 기반 암호화 이후 서버에 메시지 송신
    aes_key = scrypt(shared_key, b'salt', 32, N=2**14, r=8, p=1)
    message = input("서버에 보낼 메시지를 입력하세요: ").encode()
    encrypted_msg = aes_encrypt(message, aes_key)
    send_data(client, encrypted_msg)

    # 소켓 종료
    client.close()

if __name__ == '__main__':
    start_client()
