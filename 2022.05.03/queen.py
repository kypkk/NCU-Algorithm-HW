while True:
    x1, y1, x2, y2 = input().split()
    x1 = int(x1)
    y1 = int(y1)
    x2 = int(x2)
    y2 = int(y2)
    if(x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0):
        break
    x_diff = x2 - x1
    y_diff = y2 - y1
    if x_diff < 0:
        x_diff = -x_diff
    if y_diff < 0:
        y_diff = -y_diff
    if x_diff == y_diff and x_diff == 0:
        print(0)
    elif (x_diff == y_diff and x_diff != 0) or (x_diff == 0 or y_diff == 0):
        print(1)
    else:
        print(2)