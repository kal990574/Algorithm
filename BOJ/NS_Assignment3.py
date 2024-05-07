import random
import math

# 유한체 Fp의 크기 (소수)
p = 23

# 곡선의 계수 a와 b
a = 1
b = 1

# 곡선 위의 생성점의 x, y 좌표
Gx = 5
Gy = 7

# 개인 키를 무작위로 선택
private_key_A = random.randint(1, p-1)
private_key_B = random.randint(1, p-1)

# 최대공약수 계산 함수
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# 모듈러 역수 계산 함수
def mod_inverse(a, m):
    if gcd(a, m) != 1:
        raise ValueError("해당 값은 모듈러 역수를 가질 수 없습니다.")
    return pow(a, -1, m)

# 개인 키로부터 공용 키 생성
def generate_public_key(private_key):
    # 개인 키에 대응하는 공용 키 계산
    public_key = scalar_multiply(private_key, (Gx, Gy))
    return public_key

# 점의 스칼라 곱
def scalar_multiply(k, point):
    # 초기값으로 무한원점을 설정
    result = (None, None)
    # 점을 k번 더하기
    for _ in range(k):
        result = point_add(result, point)
    return result

# 두 점의 합
def point_add(point1, point2):
    if point1[0] is None:
        return point2
    if point2[0] is None:
        return point1
    
    x1, y1 = point1
    x2, y2 = point2
    
    if point1 != point2:
        # 서로 다른 두 점의 합 계산
        m = ((y2 - y1) * mod_inverse(x2 - x1, p)) % p
    else:
        # 같은 점에 대한 합 계산
        m = ((3 * x1**2 + a) * mod_inverse(2 * y1, p)) % p
    
    x3 = (m**2 - x1 - x2) % p
    y3 = (m * (x1 - x3) - y1) % p
    
    return (x3, y3)

# 공유 비밀 키 계산
shared_secret_A = scalar_multiply(private_key_A, generate_public_key(private_key_B))
shared_secret_B = scalar_multiply(private_key_B, generate_public_key(private_key_A))

# 두 사용자가 계산한 공유 비밀 키가 같은지 확인
assert shared_secret_A == shared_secret_B

print("공유 비밀 키:", shared_secret_A)
