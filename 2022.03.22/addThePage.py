datas = int(input())
for i in range(datas):
    total = int(input())
    sum = 0
    j = 1
    while sum < total:
        sum += j
        j += 1
    if sum == total:
        print(j, j)
    elif sum > total:
        print(sum - total, j - 1)