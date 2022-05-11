#include <iostream>
using namespace std;

void scarecrow(int cases);

int main(){
    int datas;
    cin >> datas;
    for(int i = 0; i < datas; i++){
        scarecrow(i);
        
    }

    return 0;
}

void scarecrow(int cases){
    int space;
    cin >> space;
    int answer = 0;     // need how much scarecrow
    char land[space];    // lands input
    int bad = 0;        // how many concecutive bad land
    int good = 0;       // how many concecutive good land
    for(int i = 0; i < space; i++){
        cin >> land[i];
    }
    int idx = 0;
    while(idx < space){
        if(land[idx] == '.'){
            answer += 1;
            idx += 3;
        }else if(land[idx] == '#'){
            idx += 1;
        }
        if(idx > space){
            break;
        }
    }
    cout << "Case " << cases + 1 << ": " << answer << endl;;
}