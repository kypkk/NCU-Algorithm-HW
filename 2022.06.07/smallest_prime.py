a=b=int(input())
output = ""                          # 新增 output 變數，作為輸出的文字
while True:                           # 使用 while 迴圈
    for i in range(2,(a+1)):          # 使用 for 迴圈
        if i==b:                      # 如果 i 等於 b，表示是質數，跳出 for 迴圈
            break
        if a%i==0:                    # 如果可以被 i 整除，表示不是質數
            output += f'{i}'          # 設定 output 輸出的內容
            a = int(a/i)              # 重新將 a 設定為商
            break                     # 跳出 for 迴圈
    if a==1 or a==b:                  # 如果商等於 1 或是質數，跳出 while 迴圈
        break
    else:
        output += '*'                 # 否則在 output 後方加上 * 號，繼續 while 迴圈
if a == b:
    print(f'{b}=1*{b}')               # while 迴圈結束後，如果 a 等於 b，印出質數的文字
else:
    num=[]
    time=[]
    tmp=output.split("*")
    for i in tmp:
        if i in num:
            ind=num.index(i)
            time[ind]+=1
        else:
            num.append(i)
            time.append(1)
    output2=""
    for i in range(len(num)):
        if(time[i]!=1):
            output2+=num[i]
            output2+="^"
            output2+=str(time[i])
            output2+="*"
        else:
            output2+=num[i]
            output2+="*"
    output2=output2[:-1]
    print(f'{b}={output2}')