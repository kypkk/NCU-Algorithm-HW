k=int(input())
for i in range(k):
    t,n=list(map(int, input().split()))
    bag=list(map(int, input().split()))
    v=0
    ans=[]
    for x in range(n):
        v=bag[x]
        ans.append(bag[x])
        if(v==t):
            break
        for y in range(x+1,n):
            v+=bag[y]
            ans.append(bag[y])
            if(v>t):
                v-=bag[y]
                ans.pop()
        if(v==t):
            break
        ans=[]
    if(v!=t):
        print("impossible")
    else:
        for z in range(len(ans)):
            if(z!=len(ans)-1):
                print(ans[z],end=" ")
            else:
                print(ans[z]) 