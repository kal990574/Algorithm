import random
import hashlib

# 엘리프틱 곡선 클래스
class EllipticCurve:
    def __init__(self, a, b, p):
        self.a = a
        self.b = b
        self.p = p

    def is_on_curve(self, point):
        x, y = point
        return (y**2 - x**3 - self.a*x - self.b) % self.p == 0

    def random_point(self):
        while True:
            x = random.randint(0, self.p - 1)
            y_squared = (x**3 + self.a*x + self.b) % self.p
            if legendre_symbol(y_squared, self.p) == 1:
                y = modular_sqrt(y_squared, self.p)
                return (x, y)

# 확장 유클리드 호제법
def extended_gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        d, x, y = extended_gcd(b, a % b)
        return (d, y, x - (a // b) * y)

# 모듈러 역수
def modinv(a, m):
    d, x, y = extended_gcd(a, m)
    if d != 1:
        raise ValueError('모듈러 역수가 존재하지 않음')
    else:
        return x % m

# 레전드르 심볼
def legendre_symbol(a, p):
    ls = pow(a, (p - 1) // 2, p)
    return -1 if ls == p - 1 else ls

# 모듈러 제곱근
def modular_sqrt(a, p):
    if legendre_symbol(a, p) != 1:
        raise ValueError('모듈러 제곱근이 존재하지 않음')
    else:
        return pow(a, (p + 1) // 4, p)

# ECDH 키 교환
def ecdh_key_exchange(curve):
    # 엘리프틱 곡선 위의 랜덤한 점 선택
    base_point = curve.random_point()
    private_key = random.randint(1, curve.p - 1)
    public_key = scalar_multiply(base_point, private_key, curve)
    return private_key, public_key

# 점의 스칼라 곱
def scalar_multiply(point, scalar, curve):
    if scalar == 0:
        return (0, 0)
    elif scalar == 1:
        return point
    else:
        result = (0, 0)
        addend = point
        while scalar:
            if scalar & 1:
                result = curve.add_points(result, addend)
            addend = curve.add_points(addend, addend)
            scalar >>= 1
        return result

# HMAC 계산
def hmac_sha256(key, message):
    return hashlib.sha256(key + message).digest()

# ECIES 암호화
def ecies_encrypt(curve, public_key, plaintext):
    # ECDH 키 교환
    private_key, shared_secret = ecdh_key_exchange(curve)

    # 대칭키 생성
    symmetric_key = hashlib.sha256(shared_secret).digest()

    # AES 암호화
    # (실제로는 여기에 패딩, 초기화 백터 등의 보안 기능을 추가해야 합니다.)
    cipher_text = aes_encrypt(symmetric_key, plaintext)

    # MAC 계산
    mac = hmac_sha256(shared_secret, cipher_text)

    return cipher_text, mac

# AES 암호화
def aes_encrypt(key, plaintext):
    # (실제로는 여기에 AES 암호화 코드를 추가해야 합니다.)
    return plaintext[::-1]  # 임시로 역순으로 만듭니다.

# ECIES 복호화
def ecies_decrypt(curve, private_key, cipher_text, mac):
    # ECDH 키 교환
    _, shared_secret = ecdh_key_exchange(curve)

    # 대칭키 생성
    symmetric_key = hashlib.sha256(shared_secret).digest()

    # MAC 검증
    expected_mac = hmac_sha256(shared_secret, cipher_text)
    if not hmac.compare_digest(expected_mac, mac):
        raise ValueError('메시지가 변경되었을 수 있습니다.')

    # AES 복호화
    # (실제로는 여기에 패딩, 초기화 백터 등의 보안 기능을 추가해야 합니다.)
    decrypted_text = aes_decrypt(symmetric_key, cipher_text)

    return decrypted_text

# AES 복호화
def aes_decrypt(key, cipher_text):
    # (실제로는 여기에 AES 복호화 코드를 추가해야 합니다.)
    return cipher_text[::-1]  # 임시로 역순으로 만듭니다.

# 메인 함수
def main():
    # 엘리프틱 곡선 파라미터
    a = int(input("a를 입력하세요: "))
    b = int(input("b를 입력하세요: "))
    p = int(input("p를 입력하세요: "))

    curve = EllipticCurve(a, b, p)
    private_key_A, public_key_A = ecdh_key_exchange(curve)
    private_key_B, public_key_B = ecdh_key_exchange(curve)

    # 공유 비밀키 생성
    shared_secret_A = scalar_multiply(public_key_B, private_key_A, curve)
    shared_secret_B = scalar_multiply(public_key_A, private_key_B, curve)

    # 공유 비밀키 검증
    assert shared_secret_A == shared_secret_B

    # 암호화 및 복호화 테스트
    plaintext = b"Hello, world!"
    cipher_text, mac = ecies_encrypt(curve, public_key_A, plaintext)
    decrypted_text = ecies_decrypt(curve, private_key_A, cipher_text, mac)

    print("Original:", plaintext)
    print("Decrypted:", decrypted_text.decode())

if __name__ == "__main__":
    main()
