datas = int(input())
for i in range(datas):
    a, b = input().split()
    a = int(a)
    b = int(b)
    maxim = maxCount = 0
    for j in range(a, b+1):
        total = 0
        temp = int(j ** 0.5)
        for k in range(1, temp + 1):
            if j % k == 0:
                total += 1
                if k ** 2 != j:
                    total += 1
        if total > maxCount:
            maxCount = total
            maxim = j
    print(f"Between {a} and {b}, {maxim} has a maximum of {maxCount} divisors.")