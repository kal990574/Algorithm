# 1. a,b,p 입력받기
# 2. a,b,p 활용하여 ECC 생성
# 3. ECC를 활용해 shared_secret_key 생성
# 4. ssk를 KDF를 통해 MAC key와 ENC key를 생성
# 5. ENC key를 통해 메시지 AES 기반 암호화
# 6. MAC key를 통해 MAC 생성

# 문제점
    ## ECDH 계산 부분 재 구현하기
    ## AES 암/복호화 재 구현하기
import hashlib
import random

# Elliptic Curve Point 클래스 정의
# 다시 볼 부분
class ECPoint:
    def __init__(self, x, y, a, b, p):
        self.x = x
        self.y = y
        self.a = a
        self.b = b
        self.p = p

    def __add__(self, other):
        if self.x is None:
            return other
        if other.x is None:
            return self
        if self.x == other.x and self.y != other.y:
            return ECPoint(None, None, self.a, self.b, self.p)

        if self.x == other.x:
            m = (3 * self.x ** 2 + self.a) * pow(2 * self.y, -1, self.p)
        else:
            m = (other.y - self.y) * pow(other.x - self.x, -1, self.p)
        x3 = (m ** 2 - self.x - other.x) % self.p
        y3 = (m * (self.x - x3) - self.y) % self.p
        return ECPoint(x3, y3, self.a, self.b, self.p)

    def __mul__(self, n):
        result = ECPoint(None, None, self.a, self.b, self.p)
        addend = self
        while n:
            if n & 1:
                result += addend
            addend += addend
            n >>= 1
        return result

# ECDH 키 생성 함수
def ECDH_key_generation(a, b, p, G, private_key):  # Generator Point
    public_key = G * private_key
    print(public_key)
    return public_key

# ECDH 공유 비밀키 계산 함수
def ECDH_shared_key(private_key, public_key):
    print(public_key)
    print(private_key)
    shared_key = public_key * private_key
    print(shared_key)
    return shared_key

######################################################################
"""
# S-box
Sbox = (
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16,
)

# Rcon
Rcon = (
    (0x00, 0x00, 0x00, 0x00),
    (0x01, 0x00, 0x00, 0x00),
    (0x02, 0x00, 0x00, 0x00),
    (0x04, 0x00, 0x00, 0x00),
    (0x08, 0x00, 0x00, 0x00),
    (0x10, 0x00, 0x00, 0x00),
    (0x20, 0x00, 0x00, 0x00),
    (0x40, 0x00, 0x00, 0x00),
    (0x80, 0x00, 0x00, 0x00),
    (0x1b, 0x00, 0x00, 0x00),
    (0x36, 0x00, 0x00, 0x00),
)

# AES 라운드 키 확장 함수
def key_expansion(key):
    word = [0] * 44
    for i in range(4):
        word[i] = key[i * 4:i * 4 + 4]

    for i in range(4, 44):
        temp = word[i - 1]
        if i % 4 == 0:
            temp = [temp[1], temp[2], temp[3], temp[0]]
            temp = [Sbox[x] for x in temp]
            temp[0] ^= Rcon[i // 4][0]
        word[i] = [word[i - 4][j] ^ temp[j] for j in range(4)]

    return word

# AES 바이트 서브스트래이션 함수
def sub_bytes(state):
    return [[Sbox[x] for x in row] for row in state]

# AES 쉬프트 로우 함수
def shift_rows(state):
    return [state[i][i:] + state[i][:i] for i in range(4)]

# AES 믹스 컬럼 함수
def mix_columns(state):
    def mul2(x):
        return ((x << 1) ^ 0x1B) if x & 0x80 else (x << 1)

    def mul3(x):
        return mul2(x) ^ x

    def mix_single_column(column):
        tmp = column[:]
        column[0] = mul2(tmp[0]) ^ mul3(tmp[1]) ^ tmp[2] ^ tmp[3]
        column[1] = tmp[0] ^ mul2(tmp[1]) ^ mul3(tmp[2]) ^ tmp[3]
        column[2] = tmp[0] ^ tmp[1] ^ mul2(tmp[2]) ^ mul3(tmp[3])
        column[3] = mul3(tmp[0]) ^ tmp[1] ^ tmp[2] ^ mul2(tmp[3])

    for i in range(4):
        mix_single_column(state[i])

    return state

# AES 키 추가 함수
def add_round_key(state, round_key):
    return [[state[i][j] ^ round_key[i][j] for j in range(4)] for i in range(4)]

# AES 대칭 키 암호화
def AES_encrypt(key, plaintext):
    # 평문을 4x4 상태 배열로 변환
    state = [[plaintext[i + j * 4] for i in range(4)] for j in range(4)]

    # 키 확장
    round_keys = key_expansion(key)

    # 초기 라운드 키 추가
    state = add_round_key(state, [round_keys[i][:4] for i in range(4)])

    # 9 라운드 진행
    for round_key in round_keys[4:-1]:
        state = sub_bytes(state)
        state = shift_rows(state)
        state = mix_columns(state)
        state = add_round_key(state, round_key)

    # 마지막 라운드 진행
    state = sub_bytes(state)
    state = shift_rows(state)
    state = add_round_key(state, round_keys[-1])

    # 암호문을 1차원 배열로 변환하여 반환
    return [state[i][j] for j in range(4) for i in range(4)]

###############################################################

# AES 역 바이트 서브스트래이션을 위한 역 S-box
inv_Sbox = [
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d,
]

# AES 역 바이트 서브스트래이션 함수
def inv_sub_bytes(state):
    return [[inv_Sbox[x] for x in row] for row in state]

# AES 역 쉬프트 로우 함수
def inv_shift_rows(state):
    return [state[i][-i:] + state[i][:-i] for i in range(4)]

# AES 역 믹스 컬럼 함수
def inv_mix_columns(state):
    def mul2(x):
        return ((x << 1) ^ 0x1B) if x & 0x80 else (x << 1)
    
    def mul9(x):
        return mul2(mul2(mul2(x))) ^ x

    def mul11(x):
        return mul2(mul2(mul2(x)) ^ x) ^ x

    def mul13(x):
        return mul2(mul2(mul2(x)) ^ x) ^ mul2(x)

    def mul14(x):
        return mul2(mul2(mul2(x)) ^ x) ^ mul2(mul2(x))

    def inv_mix_single_column(column):
        tmp = column[:]
        column[0] = mul14(tmp[0]) ^ mul11(tmp[1]) ^ mul13(tmp[2]) ^ mul9(tmp[3])
        column[1] = mul9(tmp[0]) ^ mul14(tmp[1]) ^ mul11(tmp[2]) ^ mul13(tmp[3])
        column[2] = mul13(tmp[0]) ^ mul9(tmp[1]) ^ mul14(tmp[2]) ^ mul11(tmp[3])
        column[3] = mul11(tmp[0]) ^ mul13(tmp[1]) ^ mul9(tmp[2]) ^ mul14(tmp[3])

    for i in range(4):
        inv_mix_single_column(state[i])

    return state

# AES 대칭 키 복호화
def AES_decrypt(key, ciphertext):
    # 암호문을 4x4 상태 배열로 변환
    state = [[ciphertext[i + j * 4] for i in range(4)] for j in range(4)]

    # 키 확장
    round_keys = key_expansion(key)

    # 초기 라운드 키 추가
    state = add_round_key(state, round_keys[-1])

    # 9 라운드 역 진행
    for round_key in reversed(round_keys[4:-1]):
        state = inv_shift_rows(state)
        state = inv_sub_bytes(state)
        state = add_round_key(state, round_key)
        state = inv_mix_columns(state)

    # 마지막 라운드 역 진행
    state = inv_shift_rows(state)
    state = inv_sub_bytes(state)
    state = add_round_key(state, round_keys[0])

    # 평문을 1차원 배열로 변환하여 반환
    return [state[i][j] for j in range(4) for i in range(4)]
"""
####################################################################################
# HMAC 함수
def HMAC(key, message):
    h = hashlib.sha256()
    h.update(key)
    h.update(message)
    return h.digest()

# ECIES 암호화 함수
def ECIES_encrypt(private_key_A, public_key_B, plaintext):
    # 1. ECDH를 사용하여 공유 비밀키 계산
    shared_key = ECDH_shared_key(private_key_A, public_key_B)

    # 2. AES, MAC 키 생성
    AES_key = hashlib.sha256(str(shared_key).encode()).digest()
    HMAC_key = hashlib.sha256(str(shared_key).encode()).digest()

    # 3. AES로 평문 암호화
    ciphertext = AES_encrypt(AES_key, plaintext)

    # 4. MAC 생성
    mac = HMAC(HMAC_key, ciphertext)
    return ciphertext, mac

# ECIES 복호화 함수
def ECIES_decrypt(private_key_B, public_key_A, ciphertext, mac):
    # 1. ECDH를 사용하여 공유 비밀키 계산
    shared_key = ECDH_shared_key(private_key_B, public_key_A)

    # 2. AES 키 생성
    AES_key = hashlib.sha256(str(shared_key).encode()).digest()
    HMAC_key = hashlib.sha256(str(shared_key).encode()).digest()

    # 3. MAC 생성 및 검증
    expected_mac = HMAC(HMAC_key, ciphertext)
    if mac != expected_mac:
        raise ValueError("MAC verification failed")

    # 4. AES로 암호문 복호화
    plaintext = AES_decrypt(AES_key, ciphertext)

    return plaintext

# 메인 함수
def main():
    # 타원 곡선 파라미터 입력
    a = int(input("Enter the value of 'a' for the elliptic curve: "))
    b = int(input("Enter the value of 'b' for the elliptic curve: "))
    p = int(input("Enter the prime number 'p' for the finite field Fp: "))

    # 사용자의 개인키 및 공개키 생성
    # ECDH 키 생성 함수 문제 발생
    G = ECPoint(3, 3, a, b, p)
    private_key_A = random.randint(1, p-1)
    print(private_key_A)
    public_key_A = ECDH_key_generation(a, b, p, G, private_key_A)
    print(public_key_A)
    private_key_B = random.randint(1, p-1)
    print(private_key_B)
    public_key_B = ECDH_key_generation(a, b, p, G, private_key_B)
    print(public_key_B)

    k = ECDH_shared_key(private_key_A, public_key_B)
    j = ECDH_shared_key(private_key_B, public_key_A)
    print (k.x, k.y, k.a, k.b, k.p)
    print (j.x, j.y, j.a, j.b, j.p)
    assert (k.x == j.x and k.y == j.y)

    # print("Your public key:", public_key_A)

    # 평문 입력
    #plaintext = input("Enter the message to be encrypted: ")

    # ECIES 암호화
    #ciphertext, mac = ECIES_encrypt(private_key_A, public_key_B, plaintext.encode())

    # ECIES 복호화
    #decrypted_plaintext = ECIES_decrypt(private_key_B, public_key_A, ciphertext, mac)
    
    #print("Plaintext:", plaintext)
    #print("Decrypted Plaintext:", decrypted_plaintext.decode())

if __name__ == "__main__":
    main()
