#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100000;
class board{

public:    
    int game[3][3];
    int idx_i;
    int idx_j;
    board(int a[3][3]){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                game[i][j] = a[i][j];
                if(game[i][j] == 0){
                    idx_i = i;
                    idx_j = j;
                }
            }
        }
    }
};

bool isexist(board tmp, vector<board> exist){
    bool isexist = false;
    for(int k = 0; k < exist.size(); k++){
        int count = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(exist[k].game[i][j] == tmp.game[i][j]){
                    count += 1;
                }
            }
        }
        if(count == 9){
            isexist = true;
        }
    }
    return isexist;
}

int main(){
    
    int ans[3][3];
    int target[3][3];
    vector<board> exist;
    queue<board> q;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> ans[i][j];
        }
    }
    board answer(ans);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> target[i][j];
        }
    }
    q.push(answer);
    exist.push_back(answer);

    while(true){
        board tmp = q.front();
        q.pop();
         
        int count = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(tmp.game[i][j] == target[i][j]){
                    count += 1;
                } 
            }
        }        
        
        
        
        for (int i = 0; i < 3; i++)
            cout << tmp.game[i][0] << " " << tmp.game[i][1] << " " << tmp.game[i][2] << endl;
        if(count == 9){
            break;
        }
        
        // cout << "----------------------------------" << endl;
        int tmp_i = tmp.idx_i;
        int tmp_j = tmp.idx_j;

        int up[3][3];
        int right[3][3];
        int down[3][3];
        int left[3][3];
        if(tmp_i != 0){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(i == tmp_i - 1 && j == tmp_j){
                        up[i][j] = tmp.game[i+1][j];
                    }else if (i == tmp_i && j == tmp_j){
                        up[i][j] = tmp.game[i-1][j];
                    }else{
                        up[i][j] = tmp.game[i][j];
                    }    
                    
                }
            }
            board up_game(up);
            if(!isexist(up_game, exist)){
                q.push(up_game);
                exist.push_back(up_game);
            }
            
        }
        
        if(tmp_j != 2){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(j == tmp_j && i == tmp_i){
                        right[i][j] = tmp.game[i][j+1];
                    }else if (j == tmp_j + 1 && i == tmp_i){
                        right[i][j] = tmp.game[i][j-1];
                    }else{
                        right[i][j] = tmp.game[i][j];
                    }    
                    
                }
            }
            board right_game(right);
            if(!isexist(right_game, exist)){
                q.push(right_game);
                exist.push_back(right_game);
            }
        }

        if(tmp_i != 2){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(i == tmp_i && j == tmp_j){
                        down[i][j] = tmp.game[i+1][j];
                    }else if (i == tmp_i + 1 && j == tmp_j){
                        down[i][j] = tmp.game[i-1][j];
                    }else{
                        down[i][j] = tmp.game[i][j];
                    }    
                    
                }
            }
            board down_game(down);
            if(!isexist(down_game, exist)){
                q.push(down_game);
                exist.push_back(down_game);
            }
        }

        if(tmp_j != 0){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(j == tmp_j - 1 && i == tmp_i){
                        left[i][j] = tmp.game[i][j+1];
                    }else if (j == tmp_j && i == tmp_i){
                        left[i][j] = tmp.game[i][j-1];
                    }else{
                        left[i][j] = tmp.game[i][j];
                    }    
                    
                }
            }
            board left_game(left);
            if(!isexist(left_game, exist)){
                q.push(left_game);
                exist.push_back(left_game);
            }
        }

    }

    return 0;
}



