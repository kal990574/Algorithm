import socket
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP, AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes
from Crypto.Protocol.KDF import scrypt

# RSA 키 생성
def generate_rsa_keys():
    key = RSA.generate(2048)
    private_key = key.export_key()
    public_key = key.publickey().export_key()
    return private_key, public_key

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
    server_public_key = RSA.import_key(recv_data(client))
    #server_public_key = RSA.import_key(client.recv(1024))
    print("RSA 공개키 수신")

    # 서버로부터 DHE 파라미터 및 공개키 수신
    G = int.from_bytes(recv_data(client), 'big')
    #g = int(client.recv(2048).decode())
    print("g 수신")
    N = int.from_bytes(recv_data(client), 'big')
    #n = int(client.recv(2048).decode())
    print("n 수신")
    server_dhe = int.from_bytes(recv_data(client), 'big')
    #server_dhe = int(client.recv(2048).decode())
    print("dhe 공개키 수신")

    # 서버로부터 RSA 암호화된 DHE 파라미터 및 공개키 수신
    encrypted_data = recv_data(client)
    cipher_rsa = PKCS1_OAEP.new(server_public_key)
    decrypted_data = cipher_rsa.decrypt(encrypted_data)
    decrypted_data_str = decrypted_data.decode()
    G_dec, N_dec, server_dhe_dec = map(int, decrypted_data_str.split(','))
    print("rsa 서명 데이터 수신")

    # DHE 파라미터 및 공개키의 무결성 검증
    if G == G_dec and N == N_dec and server_dhe == server_dhe_dec:
        print("서버로부터 받은 DHE 파라미터 및 공개키가 검증되었습니다.")
    else:
        print("서버로부터 받은 DHE 파라미터 및 공개키가 일치하지 않습니다.")
        client.close()
        return
    

    # 클라이언트의 DHE 공개키 생성
    client_private = get_random_bytes(32)
    client_dhe = pow(G, int.from_bytes(client_private, 'big'), N)
    client_dhe_bytes = client_dhe.to_bytes(256, 'big')

    # RSA로 클라이언트의 DHE 공개키 암호화 및 전송
    send_data(client, client_dhe_bytes)
    #encrypted_client_dhe = cipher_rsa.encrypt(client_dhe_bytes)
    #client.send(encrypted_client_dhe)

    # 공유 비밀키 생성
    shared_key = pow(server_dhe, int.from_bytes(client_private, 'big'), N)
    shared_key = shared_key.to_bytes(32, 'big')

    # AES 키 생성 및 메시지 암호화 후 전송
    aes_key = scrypt(shared_key, b'salt', 32, N=2**14, r=8, p=1)
    message = input("서버에 보낼 메시지를 입력하세요: ").encode()
    encrypted_msg = aes_encrypt(message, aes_key)
    send_data(client, encrypted_msg)

    client.close()

if __name__ == '__main__':
    start_client()
