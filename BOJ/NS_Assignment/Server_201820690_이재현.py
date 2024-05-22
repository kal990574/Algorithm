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

# DHE 파라미터 생성
def generate_dhe_params():
    n = int('FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD1'
            '29024E088A67CC74020BBEA63B139B22514A08798E3404DD'
            'EF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245'
            'E485B576625E7EC6F44C42E9A63A3620FFFFFFFFFFFFFFFF', 16)
    g = 2
    return n, g

# 서버 소켓 설정
def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', 9999))
    server.listen(1)
    print("서버가 시작되었습니다. 클라이언트를 기다리는 중...")

    while True:
        client_socket, client_address = server.accept()
        print(f"클라이언트 연결됨: {client_address}")

        # RSA 키 생성
        private_key, public_key = generate_rsa_keys()

        # DHE 파라미터 생성
        n, g = generate_dhe_params()

        # 서버의 DHE 공개키 생성
        server_private = get_random_bytes(32)
        server_dhe = pow(g, int.from_bytes(server_private, 'big'), n)


        # DHE 파라미터 및 공개키를 RSA로 암호화하여 클라이언트에게 전송
        data_to_encrypt = f"{n},{g},{server_dhe}".encode()
        cipher_rsa = PKCS1_OAEP.new(RSA.import_key(private_key))
        encrypted_data = cipher_rsa.encrypt(data_to_encrypt)

        # RSA 공개키, DHE 파라미터, DHE 공개키를 클라이언트에게 전송
        client_socket.send(public_key)
        client_socket.send(str(n).encode())
        client_socket.send(str(g).encode())
        client_socket.send(str(server_dhe).encode())
        client_socket.send(encrypted_data)

        # 클라이언트로부터 RSA 암호화된 DHE 공개키 수신
        encrypted_client_dhe = client_socket.recv(256)
        client_dhe = int.from_bytes(cipher_rsa.decrypt(encrypted_client_dhe), 'big')

        # 공유 비밀키 생성
        shared_key = pow(client_dhe, int.from_bytes(server_private, 'big'), n)
        shared_key = shared_key.to_bytes(32, 'big')

        # 클라이언트로부터 암호화된 메시지 수신 및 복호화
        client_encrypted_msg = client_socket.recv(2048)
        aes_key = scrypt(shared_key, b'salt', 32, N=2**14, r=8, p=1)
        decrypted_msg = aes_decrypt(client_encrypted_msg, aes_key)
        print("클라이언트로부터 받은 메시지: ", decrypted_msg.decode())

        client_socket.close()

if __name__ == '__main__':
    start_server()
