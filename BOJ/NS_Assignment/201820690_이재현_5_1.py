import numpy as np

def key_generation(n, q):
    # 비밀 키 s 생성
    s = np.random.randint(0, q, n)
    return s

def encrypt(plain_text, s, q):
    n = len(s)
    m = len(plain_text)
    
    # 공용 매트릭스 A 생성
    A = np.random.randint(0, q, (m, n))
    
    # 오류 벡터 e 생성
    e = np.zeros(m, dtype=int)
    
    # 평문을 벡터로 변환
    plain_vector = np.array([ord(char) for char in plain_text])
    
    # 암호문 c 계산
    c = (np.dot(A, s) + e + plain_vector) % q
    
    return A, c

def decrypt(A, c, s, q):
    # 암호문 복호화
    decrypted_vector = (c - np.dot(A, s)) % q
    
    # 벡터를 문자열로 변환
    decrypted_text = ''.join([chr(int(num)) for num in decrypted_vector])
    
    return decrypted_text

def main():
    try:
        # 평문 입력 받기
        plain_text = input("암호화할 문자열을 입력하세요: ")
        
        # 파라미터 설정
        n = 10  # 비밀 키의 길이
        q = 256  # 모듈로 값
        
        # 키 생성
        s = key_generation(n, q)
        
        # 암호화
        A, c = encrypt(plain_text, s, q)
        print("암호문:", c)
        
        # 복호화
        decrypted_text = decrypt(A, c, s, q)
        print("복호화된 문자열:", decrypted_text)
        
    except Exception as e:
        print("예외가 발생했습니다:", e)

if __name__ == "__main__":
    main()
