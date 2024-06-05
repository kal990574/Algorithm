import numpy as np

def generate_lwe_keys(n, q):
    """
    LWE 키를 생성합니다.
    :param n: 비밀키와 난수 벡터의 길이
    :param q: 모듈로 값
    :return: (비밀키, 공용키) 튜플
    """
    s = np.random.randint(0, q, size=n)  # 비밀키 벡터
    A = np.random.randint(0, q, size=(n, n))  # 공용키 행렬
    e = np.random.randint(-1, 2, size=n)  # 작은 오류 벡터
    b = (np.dot(A, s) + e) % q  # 공용키 벡터
    return (s, (A, b))

def encrypt_lwe(public_key, plaintext, q):
    """
    LWE 암호화를 수행합니다.
    :param public_key: 공용키
    :param plaintext: 평문 (문자열)
    :param q: 모듈로 값
    :return: 암호문 벡터
    """
    A, b = public_key
    m = len(plaintext)
    u = np.random.randint(0, q, size=A.shape[0])  # 난수 벡터
    e_prime = np.zeros(m, dtype=int)  # 작은 오류 벡터
    plaintext_vector = np.array([ord(char) for char in plaintext])  # 평문을 아스키 코드로 변환

    c1 = (np.dot(A.T, u)) % q  # 암호문 벡터 1
    c2 = (np.dot(b, u) + e_prime + plaintext_vector) % q  # 암호문 벡터 2
    return (c1, c2)

def decrypt_lwe(secret_key, ciphertext, q):
    """
    LWE 복호화를 수행합니다.
    :param secret_key: 비밀키
    :param ciphertext: 암호문 벡터
    :param q: 모듈로 값
    :return: 복호화된 평문 문자열
    """
    s = secret_key
    c1, c2 = ciphertext
    decrypted_vector = (c2 - np.dot(c1, s)) % q  # 복호화된 벡터
    decrypted_text = ''.join([chr(int(char)) for char in decrypted_vector])  # 아스키 코드를 문자로 변환
    return decrypted_text

def main():
    try:
        n = 10  # 비밀키와 난수 벡터의 길이
        q = 257  # 모듈로 값 (소수)
        plaintext = input("평문을 입력하세요: ")  # 문자열 평문 입력

        if not plaintext:
            raise ValueError("평문이 비어 있습니다.")

        # 키 생성
        secret_key, public_key = generate_lwe_keys(n, q)

        # 암호화
        ciphertext = encrypt_lwe(public_key, plaintext, q)
        print(f"암호문: {ciphertext}")

        # 복호화
        decrypted_text = decrypt_lwe(secret_key, ciphertext, q)
        print(f"복호화된 평문: {decrypted_text}")

    except ValueError as e:
        print(f"에러: {e}")
    except Exception as e:
        print(f"예기치 않은 에러가 발생했습니다: {e}")

if __name__ == "__main__":
    main()
