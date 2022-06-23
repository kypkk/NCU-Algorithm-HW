points, side = input().split()
points = int(points)
side = int(side)
row = []
for i in range(points):
    row.append(0)
answer = []
for i in range(points):
    answer.append(row)
for i in range(side):
    side1, side2, distance = input().split()
    side1 = ord(side1) - 97
    side2 = ord(side2) - 97
    distance = int(distance)
    answer[side2][side1] = distance
print(answer)
