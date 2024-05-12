# ECIES 활용 암호화 및 복호화 프로그램
# 비대칭키 알고리즘 : ECDH 사용
# 대칭키 알고리즘 : AES 사용
# MAC 생성 알고리즘 : hashlib.sha256 사용
import hashlib
import random

# Elliptic Curve 클래스 정의
class ECurve(object):
    # 초기화 함수
    def __init__(self, a, b, p):
        self.a = a
        self.b = b
        self.p = p
        
    # 타원 곡선 상의 무한 원소 반환
    def inf(self):
        return ECPoint(curve=self, x=None, y=None)

    # 두 타원 곡선이 같은지 비교
    def __eq__(self, other):
        return self.a == other.a and self.b == other.b and self.p == other.p

# Elliptic Curve Point 클래스 정의
class ECPoint(object):
    # 초기화 함수
    def __init__(self, curve, x, y):
        self.curve = curve
        self.x = x
        self.y = y

    # 현재 점의 복사본 반환
    def copy(self):
        return ECPoint(curve=self.curve, x=self.x, y=self.y)

    # 무한 원소인지 확인
    def is_inf(self):
        return self == self.curve.inf()

    # 두 점이 같은지 비교
    def __eq__(self, other):
        return self.curve == other.curve and self.x == other.x and self.y == other.y

    # Point 곱셈 함수
    def __mul__(self, s):
        # 점과 값이 곱해졌을 때 결과 반환
        bits = [s & (1 << i) for i in range(s.bit_length()-1, -1, -1)]
        res = self.curve.inf()
        for bit in bits:
            res = res + res
            if bit:
                res = res + self
        return res

    # Point 덧셈 함수
    def __add__(self, other):
        # 무한 원소 연산 시 복사본 반환
        if self.is_inf():
            return other.copy()
        if other.is_inf():
            return self.copy()
        
        # 두 점 좌표 및 유한 체 크기 가져오기
        x1, y1 = self.x, self.y
        x2, y2 = other.x, other.y
        p = self.curve.p

        # 두 점 동일한 경우
        if x1 % p == x2 % p and y1 % p == (-y2) % p:
            return self.curve.inf()
        
        # 두 점 다른 경우
        if self != other:
            # 기울기 계산
            s = (y2 - y1) * pow(x2 - x1, -1, p) % p

        else:
            # Point Doubling
            s = (3 * pow(x1, 2) + self.curve.a) * pow(2 * y1, -1, p) % p
        
        # 새로운 점의 x,y 좌표 계산
        x3 = (pow(s, 2) - x1 - x2) % p
        y3 = (s * (x1 - x3) - y1) % p

        # 계산된 좌표의 새로운 ECPoint 객체를 반환
        return ECPoint(curve=self.curve, x=x3, y=y3)

# S-box 정의
s_box_string = '63 7c 77 7b f2 6b 6f c5 30 01 67 2b fe d7 ab 76' \
               'ca 82 c9 7d fa 59 47 f0 ad d4 a2 af 9c a4 72 c0' \
               'b7 fd 93 26 36 3f f7 cc 34 a5 e5 f1 71 d8 31 15' \
               '04 c7 23 c3 18 96 05 9a 07 12 80 e2 eb 27 b2 75' \
               '09 83 2c 1a 1b 6e 5a a0 52 3b d6 b3 29 e3 2f 84' \
               '53 d1 00 ed 20 fc b1 5b 6a cb be 39 4a 4c 58 cf' \
               'd0 ef aa fb 43 4d 33 85 45 f9 02 7f 50 3c 9f a8' \
               '51 a3 40 8f 92 9d 38 f5 bc b6 da 21 10 ff f3 d2' \
               'cd 0c 13 ec 5f 97 44 17 c4 a7 7e 3d 64 5d 19 73' \
               '60 81 4f dc 22 2a 90 88 46 ee b8 14 de 5e 0b db' \
               'e0 32 3a 0a 49 06 24 5c c2 d3 ac 62 91 95 e4 79' \
               'e7 c8 37 6d 8d d5 4e a9 6c 56 f4 ea 65 7a ae 08' \
               'ba 78 25 2e 1c a6 b4 c6 e8 dd 74 1f 4b bd 8b 8a' \
               '70 3e b5 66 48 03 f6 0e 61 35 57 b9 86 c1 1d 9e' \
               'e1 f8 98 11 69 d9 8e 94 9b 1e 87 e9 ce 55 28 df' \
               '8c a1 89 0d bf e6 42 68 41 99 2d 0f b0 54 bb 16'.replace(" ", "")

# S-box 생성
s_box = bytearray.fromhex(s_box_string)

# S-box에 따라 치환한 배열을 반환
def sub_word(word: [int]) -> bytes: # type: ignore
    substituted_word = bytes(s_box[i] for i in word)
    return substituted_word

# 라운드 상수 값 생성
def rcon(i: int) -> bytes:
    rcon_lookup = bytearray.fromhex('01020408102040801b36')
    rcon_value = bytes([rcon_lookup[i-1], 0, 0, 0])
    return rcon_value

# XOR 연산을 통해 새로운 바이트 배열을 반환
def xor_bytes(a: bytes, b: bytes) -> bytes:
    return bytes([x ^ y for (x, y) in zip(a, b)])

# Byte 회전 함수
def rot_word(word: [int]) -> [int]: # type: ignore
    return word[1:] + word[:1]

# 키를 확장하여 라운드 키 생성
def key_expansion(key: bytes, nb: int = 4) -> [[[int]]]: # type: ignore

    nk = len(key) // 4

    key_bit_length = len(key) * 8

    if key_bit_length == 128:
        nr = 10
    elif key_bit_length == 192:
        nr = 12
    else:  # 256-bit keys
        nr = 14

    w = state_from_bytes(key)

    for i in range(nk, nb * (nr + 1)):
        temp = w[i-1]
        if i % nk == 0:
            temp = xor_bytes(sub_word(rot_word(temp)), rcon(i // nk))
        elif nk > 6 and i % nk == 4:
            temp = sub_word(temp)
        w.append(xor_bytes(w[i - nk], temp))

    return [w[i*4:(i+1)*4] for i in range(len(w) // 4)]

# 라운드 키 덧셈 함수
def add_round_key(state: [[int]], key_schedule: [[[int]]], round: int): # type: ignore
    round_key = key_schedule[round]
    for r in range(len(state)):
        state[r] = [state[r][c] ^ round_key[r][c] for c in range(len(state[0]))]

# 각 byte를 S-box에 따라 치환
def sub_bytes(state: [[int]]): # type: ignore
    for r in range(len(state)):
        state[r] = [s_box[state[r][c]] for c in range(len(state[0]))]

# 행을 왼쪽으로 Shift
def shift_rows(state: [[int]]): # type: ignore
    state[0][1], state[1][1], state[2][1], state[3][1] = state[1][1], state[2][1], state[3][1], state[0][1]
    state[0][2], state[1][2], state[2][2], state[3][2] = state[2][2], state[3][2], state[0][2], state[1][2]
    state[0][3], state[1][3], state[2][3], state[3][3] = state[3][3], state[0][3], state[1][3], state[2][3]

# byte * 2 연산 수행
def xtime(a: int) -> int:
    if a & 0x80:
        return ((a << 1) ^ 0x1b) & 0xff
    return a << 1

# MixColumn 단계 수행 함수 1
def mix_column(col: [int]): # type: ignore
    c_0 = col[0]
    all_xor = col[0] ^ col[1] ^ col[2] ^ col[3]
    col[0] ^= all_xor ^ xtime(col[0] ^ col[1])
    col[1] ^= all_xor ^ xtime(col[1] ^ col[2])
    col[2] ^= all_xor ^ xtime(col[2] ^ col[3])
    col[3] ^= all_xor ^ xtime(c_0 ^ col[3])

# MixColumn 단계 수행 함수 2
def mix_columns(state: [[int]]): # type: ignore
    for r in state:
        mix_column(r)

# byte를 state화
def state_from_bytes(data: bytes) -> [[int]]: # type: ignore
    state = [data[i*4:(i+1)*4] for i in range(len(data) // 4)]
    return state

# state를 byte화
def bytes_from_state(state: [[int]]) -> bytes: # type: ignore
    return bytes(state[0] + state[1] + state[2] + state[3])

# AES 알고리즘 기반의 데이터 암호화 수행
def aes_encryption(data: bytes, key: bytes) -> bytes:
    # 키 비트 길이 계산
    key_bit_length = len(key) * 8

    # 128-bit keys
    if key_bit_length == 128:
        nr = 10
    # 192-bit keys    
    elif key_bit_length == 192:
        nr = 12
    else:  # 256-bit keys
        nr = 14

    # 4x4 행렬 변환
    state = state_from_bytes(data)

    # 키 확장을 통해 라운드 키 스케줄 생성
    key_schedule = key_expansion(key)

    # 첫 번째 라운드 키를 평문에 추가
    add_round_key(state, key_schedule, round=0)

    # 라운드를 반복하여 수행
    for round in range(1, nr):
        sub_bytes(state)
        shift_rows(state)
        mix_columns(state)
        add_round_key(state, key_schedule, round)

    # SubBytes 변환
    sub_bytes(state)
    # ShiftRows 변환
    shift_rows(state)
    # 마지막 라운드 키 추가
    add_round_key(state, key_schedule, round=nr)

    # 암호문, state에서 byte로 변환
    cipher = bytes_from_state(state)
    return cipher

# 복호화를 위해 역으로 shift
def inv_shift_rows(state: [[int]]) -> [[int]]: # type: ignore
    state[1][1], state[2][1], state[3][1], state[0][1] = state[0][1], state[1][1], state[2][1], state[3][1]
    state[2][2], state[3][2], state[0][2], state[1][2] = state[0][2], state[1][2], state[2][2], state[3][2]
    state[3][3], state[0][3], state[1][3], state[2][3] = state[0][3], state[1][3], state[2][3], state[3][3]
    return

# 역 S-box 정의
inv_s_box_string = '52 09 6a d5 30 36 a5 38 bf 40 a3 9e 81 f3 d7 fb' \
                   '7c e3 39 82 9b 2f ff 87 34 8e 43 44 c4 de e9 cb' \
                   '54 7b 94 32 a6 c2 23 3d ee 4c 95 0b 42 fa c3 4e' \
                   '08 2e a1 66 28 d9 24 b2 76 5b a2 49 6d 8b d1 25' \
                   '72 f8 f6 64 86 68 98 16 d4 a4 5c cc 5d 65 b6 92' \
                   '6c 70 48 50 fd ed b9 da 5e 15 46 57 a7 8d 9d 84' \
                   '90 d8 ab 00 8c bc d3 0a f7 e4 58 05 b8 b3 45 06' \
                   'd0 2c 1e 8f ca 3f 0f 02 c1 af bd 03 01 13 8a 6b' \
                   '3a 91 11 41 4f 67 dc ea 97 f2 cf ce f0 b4 e6 73' \
                   '96 ac 74 22 e7 ad 35 85 e2 f9 37 e8 1c 75 df 6e' \
                   '47 f1 1a 71 1d 29 c5 89 6f b7 62 0e aa 18 be 1b' \
                   'fc 56 3e 4b c6 d2 79 20 9a db c0 fe 78 cd 5a f4' \
                   '1f dd a8 33 88 07 c7 31 b1 12 10 59 27 80 ec 5f' \
                   '60 51 7f a9 19 b5 4a 0d 2d e5 7a 9f 93 c9 9c ef' \
                   'a0 e0 3b 4d ae 2a f5 b0 c8 eb bb 3c 83 53 99 61' \
                   '17 2b 04 7e ba 77 d6 26 e1 69 14 63 55 21 0c 7d'.replace(" ", "")

# 역 S-box 생성
inv_s_box = bytearray.fromhex(inv_s_box_string)

# 역 S-box 활용 byte 치환
def inv_sub_bytes(state: [[int]]) -> [[int]]: # type: ignore
    for r in range(len(state)):
        state[r] = [inv_s_box[state[r][c]] for c in range(len(state[0]))]

# byte 곱셈 연산 수행
def xtimes_0e(b):
    return xtime(xtime(xtime(b) ^ b) ^ b)
def xtimes_0b(b):
    return xtime(xtime(xtime(b)) ^ b) ^ b
def xtimes_0d(b):
    return xtime(xtime(xtime(b) ^ b)) ^ b
def xtimes_09(b):
    return xtime(xtime(xtime(b))) ^ b

# 역 MixColumns 단계 수행 함수 1
def inv_mix_column(col: [int]): # type: ignore
    c_0, c_1, c_2, c_3 = col[0], col[1], col[2], col[3]
    col[0] = xtimes_0e(c_0) ^ xtimes_0b(c_1) ^ xtimes_0d(c_2) ^ xtimes_09(c_3)
    col[1] = xtimes_09(c_0) ^ xtimes_0e(c_1) ^ xtimes_0b(c_2) ^ xtimes_0d(c_3)
    col[2] = xtimes_0d(c_0) ^ xtimes_09(c_1) ^ xtimes_0e(c_2) ^ xtimes_0b(c_3)
    col[3] = xtimes_0b(c_0) ^ xtimes_0d(c_1) ^ xtimes_09(c_2) ^ xtimes_0e(c_3)

# 역 MixColumns 단계 수행 함수 2
def inv_mix_columns(state: [[int]]) -> [[int]]: # type: ignore
    for r in state:
        inv_mix_column(r)

# 역 MixColumns 단계 최적화 함수 1
def inv_mix_column_optimized(col: [int]): # type: ignore
    u = xtime(xtime(col[0] ^ col[2]))
    v = xtime(xtime(col[1] ^ col[3]))
    col[0] ^= u
    col[1] ^= v
    col[2] ^= u
    col[3] ^= v

# 역 MixColumns 단계 최적화 함수 2
def inv_mix_columns_optimized(state: [[int]]) -> [[int]]: # type: ignore
    for r in state:
        inv_mix_column_optimized(r)
    mix_columns(state)

# AES 알고리즘 기반의 데이터 복호화 수행
def aes_decryption(cipher: bytes, key: bytes) -> bytes:

    # 키 byte 길이 계산
    key_byte_length = len(key)
    # 키 bit 길이 계산
    key_bit_length = key_byte_length * 8

    # 키 길이에 따라 라운드 수 결정
    if key_bit_length == 128:
        nr = 10
    elif key_bit_length == 192:
        nr = 12
    else:  # 256-bit keys
        nr = 14

    # 4x4 행렬 변환
    state = state_from_bytes(cipher)
    # 키 확장을 통해 라운드 키 스케줄 생성
    key_schedule = key_expansion(key)
    # 마지막 라운드 키 암호문에 추가
    add_round_key(state, key_schedule, round=nr)

    # 마지막 라운드부터 역 라운드 수행
    for round in range(nr-1, 0, -1):
        inv_shift_rows(state)
        inv_sub_bytes(state)
        add_round_key(state, key_schedule, round)
        inv_mix_columns(state)

    # 역 ShiftRows 변환
    inv_shift_rows(state)
    # 역 SubBytes 변환
    inv_sub_bytes(state)
    # 첫 번째 라운드 키 추가
    add_round_key(state, key_schedule, round=0)

    # 평문을 state에서 byte로 변환
    plain = bytes_from_state(state)
    return plain

# HMAC 함수
def HMAC(key, message):
    h = hashlib.sha256()
    h.update(key)
    h.update(message)
    return h.digest()

# AES 기반 ECIES 암호화 함수
def ECIES_encrypt(shared_key, plaintext):
    # 공유키 기반 AES, MAC 키 생성
    AES_key = hashlib.sha256(str(shared_key).encode()).digest()
    HMAC_key = hashlib.sha256(str(shared_key).encode()).digest()

    # AES 기반 평문 암호화
    ciphertext = aes_encryption(plaintext, AES_key)

    # MAC값 생성
    mac = HMAC(HMAC_key, plaintext)

    return ciphertext, mac

# AES 기반 ECIES 복호화 함수
def ECIES_decrypt(shared_key, ciphertext, mac):
    # 공유키 기반 AES, MAC 키 생성
    AES_key = hashlib.sha256(str(shared_key).encode()).digest()
    HMAC_key = hashlib.sha256(str(shared_key).encode()).digest()

    # AES 기반 암호문 복호화
    plaintext = aes_decryption(ciphertext, AES_key)

    # MAC 생성 및 비교 검증
    expected_mac = HMAC(HMAC_key, plaintext)
    assert (mac == expected_mac)

    return plaintext

# PKCS7 기반의 패딩 함수 정의
def pad(data):
    # 16byte 블록 단위, 패딩에 필요한 바이트 계산
    padding_length = 16 - (len(data) % 16)
    
    # 패딩 길이 만큼 패딩 바이트 생성
    padding = bytes([padding_length] * padding_length)

    # 데이터에 패딩 추가
    return data + padding

# PKCS7 기반의 패딩 제거 함수 정의
def unpad(data):
    # 복호화 데이터 마지막 바이트를 통해 패딩 길이 확인
    padding_length = data[-1]
    # 패딩 제외 원래 데이터 반환
    return data[:-padding_length]

# 소수 판별 함수
def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

# 타원 곡선 파라미터 입력 및 예외 처리 함수
def get_elliptic_curve_parameters():
    while True:
        try:
            # 타원 곡선 파라미터 입력
            a = int(input("Elliptic Curve의 a 값을 입력해주세요: "))
            b = int(input("Elliptic Curve의 b 값을 입력해주세요: "))
            p = int(input("유한필드 Fp에서 소수 p 값을 입력해주세요: "))
            
            # 입력값이 유효한지 확인
            if a < 0 or b < 0 or p <= 0:
                raise ValueError("a와 b는 음수가 될 수 없고, p는 양수이어야 합니다.")
            
            # 소수 여부 확인
            if not is_prime(p):
                raise ValueError("입력된 p값은 소수가 아닙니다.")
            
            return a, b, p
        # 예외 처리 수행
        except ValueError as ve:
            print("입력값이 올바르지 않습니다:", ve)
            print("다시 입력해주세요.")
        except Exception as e:
            print("오류가 발생했습니다:", e)
            print("다시 시도해주세요.")

# 평문 입력 및 예외 처리 함수
def get_plaintext():
    while True:
        try:
            plaintext = input("평문을 입력해주세요: ")

            # 입력값이 유효한지 확인
            if not plaintext:
                raise ValueError("평문이 입력되지 않았습니다.")
            if len(plaintext.encode('utf-8')) >= 16:
                raise ValueError("평문의 길이를 16바이트보다 작게 설정해주세요.")
            
            return plaintext
        # 예외 처리 수행
        except ValueError as ve:
            print("입력값이 올바르지 않습니다:", ve)
            print("다시 입력해주세요.")
        except Exception as e:
            print("오류가 발생했습니다:", e)
            print("다시 시도해주세요.")

# 메인 함수
def main():
    # 타원 곡선 Base Point 정의
    g_x = 5
    g_y = 7

    # 타원 곡선 파라미터 입력
    a, b, p = get_elliptic_curve_parameters()

    # ECDH를 위한 기본값 지정
    curve = ECurve(a,b,p)
    G = ECPoint(curve, g_x, g_y)

    # 송신자의 개인키 및 공개키 생성
    private_key_A = random.randint(1, p-1)
    public_key_A = G * private_key_A

    # 수신자의 개인키 및 공개키 생성
    private_key_B = random.randint(1, p-1)
    public_key_B = G * private_key_B

    # 송수신자 간에 공유 비밀키 생성
    shared_key_A = public_key_B * private_key_A
    shared_key_B = public_key_A * private_key_B

    # 공유 비밀키 동일한지 검증
    assert (shared_key_A == shared_key_B)
    
    # shared_key_A의 x, y 좌표를 Byte로 변환
    x_bytes_A = shared_key_A.x.to_bytes((shared_key_A.x.bit_length() + 7) // 8, byteorder='big')
    y_bytes_A = shared_key_A.y.to_bytes((shared_key_A.y.bit_length() + 7) // 8, byteorder='big')

    # shared_key_B의 x, y 좌표를 Byte로 변환
    x_bytes_B = shared_key_B.x.to_bytes((shared_key_B.x.bit_length() + 7) // 8, byteorder='big')
    y_bytes_B = shared_key_B.y.to_bytes((shared_key_B.y.bit_length() + 7) // 8, byteorder='big')

    # shared_key의 x, y좌표의 Byte값을 이어붙여 AES 암복호화 키 생성
    shared_key_bytes_A = x_bytes_A + y_bytes_A
    shared_key_bytes_B = x_bytes_B + y_bytes_B

    # 평문 입력
    plaintext = get_plaintext()

    # 평문 byte화 및 패딩
    plaintext_bytes = plaintext.encode('UTF-8')
    padded_plaintext = pad(plaintext_bytes)

    # ECIES 암호화
    ciphertext, mac = ECIES_encrypt(shared_key_bytes_A, padded_plaintext)

    # ECIES 복호화
    decrypted_plaintext = ECIES_decrypt(shared_key_bytes_B, ciphertext, mac)
    unpad_decrypted_plaintext = unpad(decrypted_plaintext)

    # 암호문과 복호화된 암호문 출력
    print("Plaintext:", plaintext)
    print("Ciphertext:", ciphertext)
    print("Decrypted Plaintext:", unpad_decrypted_plaintext)

if __name__ == "__main__":
    main()
