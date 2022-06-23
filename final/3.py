datas = int(input())

for i in range(datas):
    # input the # of vertices in the graph
    v = int(input())
    v = int(v)
    # initialize the selected list and the graph
    selected = []
    G = []
    for j in range(v):
        selected.append(0)
    # print(selected, G)
    # get the input of the graph
    x = []
    y = []
    for j in range(v):
        tmp_x, tmp_y = input().split()
        tmp_x = int(tmp_x)
        tmp_y = int(tmp_y)
        x.append(tmp_x)
        y.append(tmp_y)
    for j in range(v):
        tmp = []
        for k in range(v):
            tmp.append(abs(x[j] - x[k]) + abs(y[j] - y[k]))
        G.append(tmp) 
    
    # set the number of edges
    edges = 0
    #choose the 0th edge and set it true
    selected[0] = True
    #set the mst = 0
    sum = 0
    while(edges < v - 1):
        minimum = 100000
        x = 0
        y = 0
        for i in range(v):
            if selected[i]:
                for j in range(v):
                    if ((not selected[j]) and G[i][j]):  
                        # not in selected and there is an edge
                        if minimum > G[i][j]:
                            minimum = G[i][j]
                            x = i
                            y = j
        sum += int(G[x][y])
        selected[y] = True
        edges += 1
    print(sum)