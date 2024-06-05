import numpy as np

# LWE 파라미터 설정
n = 10  # 비밀 키 길이
q = 257  # 소수 모듈러 값
sigma = 0.1  # error 값의 시그마 값 

# 비밀 키 생성 함수
def generate_secret_key(n):
    # 길이 n인 비밀 키 벡터 랜덤하게 생성
    return np.random.randint(0, q, n)

# error 값 생성 함수
def generate_error_value(length, sigma):
    return np.random.normal(0, sigma, length)

# LWE 기반 암호화 함수
def encrypt(plaintext, s, q):
    try:
        # 평문을 숫자로 변환
        plaintext_vector = np.array([ord(char) for char in plaintext])
        # plaintext_vector 길이 계산
        length = len(plaintext_vector)
        
        # 암호화 행렬 생성
        A = np.random.randint(0, q, (length, len(s)))
        # error 값 생성
        e = generate_error_value(length, sigma)
        
        # 암호문 계산
        c = (np.dot(A, s) + e + plaintext_vector) % q
        # 암호문 리턴
        return A, c
    
    # 예외 처리
    except Exception as e:
        print(f"암호화 중 오류 발생: {e}")
        return None

# LWE 기반 복호화 함수
def decrypt(A, c, s, q):
    try:
        # 비밀 키 활용 암호문 복호화
        decrypted_vector = (c - np.dot(A, s)) % q
        # 복호화 결과를 반올림 후 0에서 q-1 사이로 설정
        decrypted_vector = np.round(decrypted_vector) % q
        
        # 숫자를 문자로 변환
        decrypted_text = ''.join([chr(int(num)) for num in decrypted_vector])
        return decrypted_text
    
    # 예외 처리
    except Exception as e:
        print(f"복호화 중 오류 발생: {e}")
        return None

# 평문 입력 함수
def get_valid_input(prompt):
    while True:
        try:
            # 입력 받기
            user_input = input(prompt)

            # 빈 문자열 예외 처리
            if not user_input:
                raise ValueError("입력된 문자열이 비어 있습니다. 다시 입력해 주세요.")
            return user_input
        except ValueError as ve:
            print(ve)

# 메인 함수
if __name__ == "__main__":
    # 비밀 키 생성
    secret_key = generate_secret_key(n)
    
    # 사용자 입력 및 예외 처리
    plaintext = get_valid_input("암호화할 문자열을 입력하세요: ")
    
    # LWE 기반 암호화
    A, ciphertext = encrypt(plaintext, secret_key, q)
    if A is not None and ciphertext is not None:
        print(f"암호문: {ciphertext}")
        
        # LWE 기반 복호화
        decrypted_text = decrypt(A, ciphertext, secret_key, q)
        if decrypted_text is not None:
            print(f"복호화된 평문: {decrypted_text}")
