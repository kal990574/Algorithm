plaintext_bytes = bytearray.fromhex('00112233445566778899aabbccddeeff')

# UTF-8 디코딩으로 문자열로 변환
plaintext_string = plaintext_bytes.decode('utf-8')

# 결과 출력
print("평문:", plaintext_string)
