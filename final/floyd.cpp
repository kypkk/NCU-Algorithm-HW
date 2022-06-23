#include <iostream>

using namespace std;

int main(){
    int points, sides;
    cin >> points >> sides;
    int answer[points][points];
    for(int i = 0; i < points; i++){
        for(int j = 0; j < points; j++){
            if(i == j){
                answer[i][j] = 0;
            }else{
                answer[i][j] = 9999999;
            }
             
        }
    }
    char alph[26] = {'0'};
    int idx = 0;
    for(int i = 0; i < sides; i++){
        char side1, side2;
        int tmp1 = -1;
        int tmp2 = -1;
        int distance;
        cin >> side1 >> side2 >> distance;
        for(int i = 0; i < idx; i++){
            if(side1 == alph[i]){
                tmp1 = i;
            }
            if(side2 == alph[i]){
                tmp2 = i;
            }
        }
        if(tmp1 == -1){
            tmp1 = idx;
            alph[idx] = side1;
            idx += 1;
        }
        if(tmp2 == -1){
            tmp2 = idx;
            alph[idx] = side2;
            idx += 1;
        }
        answer[tmp1][tmp2] = distance;
    }

    
    for(int k = 0; k < points; k++){
        for(int j = 0; j < points; j++){
            for(int i = 0; i < points; i++){
                if (answer[i][j]>answer[i][k]+answer[k][j]){
                    answer[i][j] = answer[i][k] + answer[k][j];  
                }

            }
        }
    }
    for(int i = 0; i < points; i++){
        if(answer[i][0] != 9999999)
            cout << answer[i][0];
        else
            cout << "INF";
        for(int j = 1; j < points; j++){
            if(answer[i][j] != 9999999)
                cout << " " << answer[i][j]; 
            else
                cout << " " << "INF";
        }
        if(i!= points - 1)
            cout << endl;
    }
    
    return 0;
}

