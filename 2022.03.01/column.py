n = int(input())
j = 0
while(j < n):
    string = input()
    ans = 0
    i = len(string)
    for character in string:
        ans = ans + (ord(character) - 64) * (26 ** (i-1))
        i -= 1
    print(ans)
    j += 1