# 함수: 소수 판별
def is_prime(num):
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True

# 함수: 두 소수(p, q) 입력받기
def input_primes():
    while True:
        p = int(input("소수 p를 입력하세요: "))
        if is_prime(p):
            break
        else:
            print("입력한 수가 소수가 아닙니다. 다시 입력하세요.")
    while True:
        q = int(input("소수 q를 입력하세요: "))
        if is_prime(q) and q != p:
            break
        else:
            print("입력한 수가 소수가 아니거나 p와 동일합니다. 다시 입력하세요.")
    return p, q

# 함수: 최대공약수 구하기
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# 함수: 모듈러 역원 구하기
def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 + m0 if x1 < 0 else x1

# 함수: 키 쌍 생성
def generate_keys(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 65537  # 공개키
    d = mod_inverse(e, phi)  # 개인키
    return ((e, n), (d, n))

# 함수: 암호화
def encrypt(plaintext, public_key):
    e, n = public_key
    encrypted = [pow(ord(char), e, n) for char in plaintext]
    return encrypted

# 함수: 복호화
def decrypt(ciphertext, private_key):
    d, n = private_key
    decrypted = [chr(pow(char, d, n)) for char in ciphertext]
    return ''.join(decrypted)

# 메인 함수
def main():
    print("RSA 알고리즘을 이용한 암호화/복호화 프로그램")
    p, q = input_primes()
    public_key, private_key = generate_keys(p, q)

    plaintext = input("암호화할 메시지를 입력하세요: ")
    encrypted_message = encrypt(plaintext, public_key)
    print("암호화된 메시지:", encrypted_message)

    decrypted_message = decrypt(encrypted_message, private_key)
    print("복호화된 메시지:", decrypted_message)

if __name__ == "__main__":
    main()
