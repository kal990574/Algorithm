import numpy as np

# 모듈러 연산 함수
def mod(x, q):
    return x % q

# 암호화 함수
def encrypt(plain_text, A, s, e, q):
    # 문자열을 숫자 벡터로 변환
    m = np.array([ord(char) for char in plain_text])
    # 암호화: c1 = A * s + e, c2 = m + (A * s + e)
    c1 = mod(np.dot(A, s) + e, q)
    c2 = mod(m + c1, q)
    return c1, c2

# 복호화 함수
def decrypt(c1, c2, s, q):
    # 복호화: m = c2 - (A * s + e)
    m = mod(c2 - np.dot(c1, s), q)
    # 숫자 벡터를 문자열로 변환
    plain_text = ''.join([chr(num) for num in m])
    return plain_text

def main():
    try:
        # 파라미터 설정
        n = 4  # 벡터의 차원
        q = 23  # 모듈러 값
        A = np.random.randint(0, q, (n, n))  # 랜덤 행렬 A
        s = np.random.randint(0, q, n)  # 비밀키 벡터 s
        e = np.random.randint(0, 3, n)  # 작은 오류 벡터 e

        # 사용자로부터 평문 입력 받기
        plain_text = input("암호화할 문자열을 입력하세요: ")

        # 암호화
        c1, c2 = encrypt(plain_text, A, s, e, q)
        print("암호문:", (c1, c2))

        # 복호화
        decrypted_text = decrypt(c1, c2, s, q)
        print("복호화된 문자열:", decrypted_text)

    except Exception as e:
        print(f"오류 발생: {e}")

if __name__ == "__main__":
    main()
