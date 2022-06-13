T=int(input())
for counts in range(T):
    num=int(input())
    sum=1
    for i in range(2,num):
        x=num
        y=i
        while(1):
            tmp=x%y
            if(tmp==0):
                break
            else:
                x=y
                y=tmp
        if(y==1):
            sum+=1
    print(sum)