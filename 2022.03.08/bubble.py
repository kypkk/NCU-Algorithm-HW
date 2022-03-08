def bubble(arr):
    length = len(arr)
    swaps = 0
    for i in range(length):
        for j in range(length - i - 1):
            if arr[j] > arr[j+1]:
                s = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = s
                swaps = swaps + 1
    return swaps

datas = int(input())
for i in range(datas):
    leng = int(input())
    item = input()
    items = item.split()
    arr = list(map(int, items))
    print(f"Optimal swapping takes {bubble(arr)} swaps.")