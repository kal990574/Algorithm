# 난수 생성을 위한 random 라이브러리 import
import random

# 유클리드 알고리즘 활용 최대 공약수 계산 함수 gcd() 정의
def gcd(num1, num2):
    while num2 != 0:
        num1, num2 = num2, num1 % num2
    return num1

# 소수 판별 함수 is_prime() 정의
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

# 소수 p,q 입력 함수 input_primes() 정의
def input_primes():
    while True:
        p = int(input("소수 p를 입력하세요: "))
        if is_prime(p):
            break
        else:
            print("입력한 수가 소수가 아닙니다. 소수를 다시 입력해주세요.")

    while True:
        q = int(input("소수 q를 입력하세요: "))
        if is_prime(q) and q != p:
            break
        else:
            print("입력한 수가 소수가 아니거나 p와 동일합니다. 소수를 다시 입력해주세요.")
    return p, q

# 확장 유클리드 알고리즘 활용 모듈러 역수 계산 함수 mod_inverse() 정의
def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 + m0 if x1 < 0 else x1

# 오일러 피 함수값 계산 함수 euler_phi() 정의
def euler_phi(n):
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1
    if n > 1:  # n이 소수인 경우
        result -= result // n
    return result

# RSA 키 쌍 생성 함수 generate_keys() 정의
def generate_keys(p, q):
    n = p * q
    phi = euler_phi(n)

    e = random.randrange(1, phi)
    g = gcd(e, phi)

    while g != 1:
        e = random.randrange(1, phi)
        g = gcd(e, phi)

    d = mod_inverse(e, phi)
    return ((e, n), (d, n))

# RSA 알고리즘 암호화 함수 정의
def encrypt(plaintext, public_key):
    key, n = public_key
    encrypted = [pow(ord(char), key, n) for char in plaintext]
    return encrypted

# RSA 알고리즘 복호화 함수 정의
def decrypt(ciphertext, private_key):
    key, n = private_key
    decrypted = [chr(pow(char, key, n)) for char in ciphertext]
    return ''.join(decrypted)

# 메인 함수 정의
def main():
    print("RSA 알고리즘 활용 암호화/복호화 프로그램")
    p, q = input_primes()
    public_key, private_key = generate_keys(p, q)

    plaintext = input("암호화할 메시지를 입력하세요: ")
    encrypted_message = encrypt(plaintext, public_key)
    print("암호화된 메시지:", ''.join(map(lambda x: str(x), encrypted_message)))

    decrypted_message = decrypt(encrypted_message, private_key)
    print("복호화된 메시지:", decrypted_message)

if __name__ == "__main__":
    main()
