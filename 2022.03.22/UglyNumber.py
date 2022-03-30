# # Method 1 
# def Maxdivide(a, b):
#     while a % b == 0:
#         a = a / b
#     return a
# def isUgly(n):
#     n = Maxdivide(n, 2)
#     n = Maxdivide(n, 3)
#     n = Maxdivide(n, 5)
#     if n == 1:
#         return True
#     else:
#         return False
# datas = int(input())
# for i in range(datas):
#     number = int(input())
#     counter = 0
#     i = 1
#     while counter < number:
#         if isUgly(i):
#             counter += 1
#         i += 1
#     print(i - 1)

# Method 2 Dynamic Programming
datas = int(input())
for i in range(datas):
    number = int(input())
    ugly = [0] * number
    ugly[0] = 1
    i2 = 0
    i3 = 0
    i5 = 0
    next2 = ugly[i2] * 2
    next3 = ugly[i3] * 3
    next5 = ugly[i5] * 5
    for i in range(1,number):
        nextUgly = min(next2, next3, next5)
        ugly[i] = nextUgly
        if nextUgly == next2:
            i2 = i2 + 1
            next2 = ugly[i2] * 2
        if nextUgly == next3:
            i3 = i3 + 1
            next3 = ugly[i3] * 3
        if nextUgly == next5:
            i5 = i5 + 1
            next5 = ugly[i5] * 5
    print(ugly[number - 1])