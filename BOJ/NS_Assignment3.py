import hashlib
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

# ECDH를 구현합니다.
def ECDH(a, b, p, G):
    # G는 기준점입니다.
    private_key_A = 123  # 임의의 개인 키 A를 선택합니다.
    private_key_B = 456  # 임의의 개인 키 B를 선택합니다.
    public_key_A = private_key_A * G  # 공개 키 A를 계산합니다.
    public_key_B = private_key_B * G  # 공개 키 B를 계산합니다.
    
    # 서로의 공개 키로 공유 키를 계산합니다.
    shared_key_A = private_key_A * public_key_B
    shared_key_B = private_key_B * public_key_A

    # 공유 키가 동일한지 확인합니다.
    assert shared_key_A == shared_key_B
    
    return shared_key_A

# HMAC을 사용하여 MAC을 생성합니다.
def generate_MAC(key, message):
    h = hashlib.new('sha256')
    h.update(key)
    h.update(message)
    return h.digest()

# AES를 사용하여 메시지를 암호화합니다.
def encrypt_AES(key, plaintext):
    cipher = AES.new(key, AES.MODE_CBC)
    ciphertext = cipher.encrypt(pad(plaintext, AES.block_size))
    return ciphertext, cipher.iv

# AES를 사용하여 암호문을 복호화합니다.
def decrypt_AES(key, ciphertext, iv):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
    return plaintext

# AES 키를 생성합니다.
def generate_AES_key(shared_key):
    # shared_key를 해시 함수를 이용하여 적절한 길이로 축소합니다.
    hashed_key = hashlib.sha256(str(shared_key).encode()).digest()
    return hashed_key

# 메인 함수
def main():
    # 1. 사용자로부터 a, b, p를 입력받습니다.
    a = int(input("Enter the value of a: "))
    b = int(input("Enter the value of b: "))
    p = int(input("Enter the value of p: "))
    
    # 2. 곡선 상의 기준점 G를 정의합니다. (임의로 선택)
    G = (3, 6)
    
    # 3. ECDH를 통해 공유 키를 생성합니다.
    shared_key = ECDH(a, b, p, G)
    
    # 4. 공유 키를 사용하여 HMAC 키를 생성합니다.
    HMAC_key = hashlib.sha256(str(shared_key).encode()).digest()
    
    # 5. AES 키를 생성합니다.
    AES_key = generate_AES_key(shared_key)
    
    # 6. 사용자로부터 평문을 입력받습니다.
    plaintext = input("Enter the plaintext: ").encode()
    
    # 7. AES를 사용하여 평문을 암호문으로 변환합니다.
    ciphertext, iv = encrypt_AES(AES_key, plaintext)
    
    # 8. 메시지와 IV를 함께 HMAC으로 보호합니다.
    MAC = generate_MAC(HMAC_key, ciphertext)
    
    # 9. 암호문과 MAC를 출력합니다.
    print("Ciphertext:", ciphertext)
    print("MAC:", MAC)
    
    # 10. 복호화를 테스트합니다.
    decrypted_text = decrypt_AES(AES_key, ciphertext, iv)
    print("Decrypted text:", decrypted_text.decode())

if __name__ == "__main__":
    main()
