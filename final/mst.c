#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100000

void solution();

int main(){
    int datas;
    scanf("%d", &datas);
    for(int i = 0; i < datas; i++){
        solution();
        if(i != datas - 1){
            printf("\n");
        }
    }
    return 0;
}

void solution(){
    // input the size of the graph & the graph
    int sides;
    scanf("%d", &sides);
    int point_x[sides];
    int point_y[sides];
    int matrix[sides][sides];
    
    for(int i = 0; i < sides; i++){
        scanf("%d%d", &point_x[i], &point_y[i]);
    }
    for(int i = 0; i < sides; i++){
        for(int j = 0; j < sides; j++){
            int tmp = 0;
            tmp += abs(point_x[i] - point_x[j]);
            tmp += abs(point_y[i] - point_y[j]);

            matrix[i][j] = tmp;
        }
    }
    // // test the input matrix
    // for(int i = 0; i < sides; i++){
    //     for(int j = 0; j < sides; j++){
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }


    // initial the sum of the minimum spanning tree
    // set a counter for the edges
    // the array for marking the passed point
    // initial we start from point 1
    int sum = 0;
    int num_edge = 0;
    int selected[MAX] = {0};
    selected[0] = 1;

    // in the while loop we walk through the graph from the point we walk through
    // then find the smallest edge and mark the point true
    while(num_edge < sides-1) {
        int smallest = 100000;
        int x = 0;
        int y = 0;
        for (int i = 0; i < sides; i++) {
            if (selected[i]) {
                for (int j = 0; j < sides; j++) {
                    if (matrix[i][j] < smallest && !selected[j] && matrix[i][j]) {
                        smallest = matrix[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (smallest != 100000){
            sum += smallest;
            selected[y] = true;
        }
        num_edge++;
    }

    printf("%d", sum);

}