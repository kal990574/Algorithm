import hashlib
import secrets

# 타원 곡선에서의 점 덧셈
def point_addition(p, q, a, b, p_val):
    if p is None:
        return q
    if q is None:
        return p

    if p[0] == q[0] and p[1] != q[1]:
        return None

    if p == q:
        m = (3 * p[0] * p[0] + a) * pow(2 * p[1], -1, p_val)
    else:
        m = (q[1] - p[1]) * pow(q[0] - p[0], -1, p_val)

    x = (m * m - p[0] - q[0]) % p_val
    y = (m * (p[0] - x) - p[1]) % p_val

    return x, y

# 타원 곡선에서의 점 배수 곱
def point_multiply(k, point, a, b, p_val):
    result = None
    addend = point

    while k:
        if k & 1:
            result = point_addition(result, addend, a, b, p_val)
        addend = point_addition(addend, addend, a, b, p_val)
        k >>= 1

    return result

# 비대칭 키 교환 (ECDH)
def ECDH_key_exchange(private_key, public_key, a, b, p_val):
    shared_secret = point_multiply(private_key, public_key, a, b, p_val)
    return shared_secret[0]  # x 좌표만 반환

# AES 대칭 키 암호화
def AES_encrypt(key, plaintext):
    # 구현해야 함
    pass

# AES 대칭 키 복호화
def AES_decrypt(key, ciphertext):
    # 구현해야 함
    pass

# HMAC을 이용한 메시지 인증 코드 생성
def generate_HMAC(key, message):
    hmac = hashlib.sha256(key + message.encode()).digest()
    return hmac

# ECIES 암호화
def ECIES_encrypt(a, b, p_val, private_key, public_key, plaintext):
    # ECDH를 통해 공유 키 생성
    shared_key = ECDH_key_exchange(private_key, public_key, a, b, p_val)
    
    # 대칭 키 생성 (여기서는 간단히 하기 위해 공유 키를 사용)
    symmetric_key = hashlib.sha256(shared_key.to_bytes(32, 'big')).digest()

    # 대칭 키로 AES 암호화 수행
    ciphertext = AES_encrypt(symmetric_key, plaintext)

    # HMAC 생성
    hmac = generate_HMAC(shared_key, ciphertext)

    return ciphertext, hmac

# ECIES 복호화
def ECIES_decrypt(a, b, p_val, private_key, public_key, ciphertext, hmac):
    # ECDH를 통해 공유 키 생성
    shared_key = ECDH_key_exchange(private_key, public_key, a, b, p_val)
    
    # 대칭 키 생성 (여기서는 간단히 하기 위해 공유 키를 사용)
    symmetric_key = hashlib.sha256(shared_key.to_bytes(32, 'big')).digest()

    # HMAC 검증
    if hmac != generate_HMAC(shared_key, ciphertext):
        raise ValueError("HMAC verification failed. The message may have been tampered with.")

    # 대칭 키로 AES 복호화 수행
    plaintext = AES_decrypt(symmetric_key, ciphertext)

    return plaintext

# 메인 함수
def main():
    # 타원 곡선 파라미터 입력
    a = int(input("Enter the value of 'a' for the elliptic curve: "))
    b = int(input("Enter the value of 'b' for the elliptic curve: "))
    p = int(input("Enter the prime number 'p' for the finite field Fp: "))

    # 사용자의 개인키 및 공개키 생성
    private_key = secrets.randbelow(p)
    public_key = point_multiply(private_key, (0, 1), a, b, p)

    print("Your public key:", public_key)

    # 평문 입력
    plaintext = input("Enter the message to be encrypted: ")

    # 암호화 수행
    ciphertext, hmac = ECIES_encrypt(a, b, p, private_key, public_key, plaintext)
    print("Encrypted message:", ciphertext)
    print("HMAC:", hmac)

    # 복호화 수행
    decrypted_message = ECIES_decrypt(a, b, p, private_key, public_key, ciphertext, hmac)
    print("Decrypted message:", decrypted_message)

if __name__ == "__main__":
    main()
