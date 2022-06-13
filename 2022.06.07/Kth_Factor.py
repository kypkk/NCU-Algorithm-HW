N=int(input())
for counts in range(N):
    nums=list(map(int, input().split()))
    nums.sort()
    k=int(input())
    print(nums[k-1])