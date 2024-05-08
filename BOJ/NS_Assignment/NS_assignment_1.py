# 암호화 프로그래밍을 위한 Crypto 모듈 임포트
from Crypto.Cipher import DES
# 랜덤 바이트 생성을 위한 모듈 임포트
from Crypto.Random import get_random_bytes

# PKCS5 방식을 통한 패딩 함수 정의
def pad(data):
    # 8byte 블록 단위, 패딩에 필요한 바이트 계산
    padding_length = 8 - (len(data) % 8)
    # 패딩 길이 만큼 패딩 바이트 생성
    padding = bytes([padding_length] * padding_length)
    # 데이터에 패딩 추가
    return data + padding

# PKCS5 패딩 제거 함수 정의
def unpad(data):
    # 복호화 데이터 마지막 바이트를 통해 패딩 길이 확인
    padding_length = data[-1]
    # 패딩 제외 원래 데이터 반환
    return data[:-padding_length]

# 암호화 함수 정의
def encrypt(message, key):
    # DES 객체를 ECB 모드로 생성
    cipher = DES.new(key, DES.MODE_ECB)
    # 메시지에 패딩 추가
    padded_message = pad(message)
    # 패딩된 메시지 암호화
    encrypted_message = cipher.encrypt(padded_message)
    return encrypted_message

# 복호화 함수 정의
def decrypt(ciphertext, key):
    # DES 객체를 ECB 모드로 생성
    cipher = DES.new(key, DES.MODE_ECB)
    # 암호문 복호화
    decrypted_message = cipher.decrypt(ciphertext)
    # 복호화된 메시지, 패딩 제거
    unpadded_message = unpad(decrypted_message)
    return unpadded_message

# 랜덤 키 생성
key = get_random_bytes(8)

# 암호화할 메시지
message = b"Network Security Assignment 1"

# 메시지 암호화
encrypted_message = encrypt(message, key)
print("Encrypted:", encrypted_message)

# 암호화된 메시지 복호화
decrypted_message = decrypt(encrypted_message, key)
print("Decrypted:", decrypted_message.decode())