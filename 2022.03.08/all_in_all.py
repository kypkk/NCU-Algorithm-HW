from operator import indexOf


def all_in_all(s, t):
    len_t = len(t)
    len_s = len(s)
    ans = False
    a = 0
    b = 0
    for i in range(len_s):
        for j in range(b, len_t):
            if(s[i] == t[j]):
                a = a + 1
                b = j + 1
                break
    if a == len_s:
        ans = True
    if ans == True:
        return "Yes"
    else:
        return "No"

datas = int(input())
for i in range(datas):
    a = input()
    a = a.split()
    print(all_in_all(a[0], a[1]))