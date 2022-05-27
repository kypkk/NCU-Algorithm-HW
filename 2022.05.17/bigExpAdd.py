

def bigExpAdd():
    a, b = input().split()
    a = int(a)
    b = int(b)
    num1 = pow(2, a)
    num2 = pow(2, b)
    print(num1 + num2)


if __name__ == '__main__':
    datas = int(input())
    for i in range(datas):
        bigExpAdd()