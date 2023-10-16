arr = [0] * 3
result =[0] * 3
for i in range(0,3):
    arr[i] = input()
    if arr[i] == 'A':
        result[i] = 4.5
    if arr[i] == 'B':
        result[i] = 3.5
    if arr[i] == 'C':
        result[i] = 2.5
    if arr[i] == 'D':
        result[i] = 1.5
    if arr[i] == 'F':
        result[i] = 0
a = (result[0] + result[1] + result[2]) / 3
print("The average grade is %.2f."%a)