import math

# Returns sum of squares of digits
def digitSumSquare(num):
    sum = 0
    while(num != 0):
        x = num % 10
        sum = sum + (x ** 2)
        num = math.floor(num / 10)
    return sum 

# Returns true if n is Happy number
# else returns false.
def isHappy(num):
    while(num != 1 and num != 4):
        num = digitSumSquare(num)
    if(num == 1):
        return True
    else:
        return False

# Driver code

n = int(input())
i = 0
while(i < n):
    num = int(input())
    if(isHappy(num)):
        print("Happy")
    else:
        print("Not Happy")
    i += 1