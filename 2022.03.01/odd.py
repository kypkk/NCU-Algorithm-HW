n = int(input())
i = 0
while(i < n):
    ans = 0
    lb = int(input())
    ub = int(input())
    for j in range (lb, ub+1):
        if(j % 2 == 1):
            ans += j
    print(f"Case {i+1}: {ans}")
    i += 1