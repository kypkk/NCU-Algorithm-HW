#include <iostream>

using namespace std;

void sol();

int main(){
    int datas;
    cin >> datas;
    while(datas--){
        sol();
    }

    return 0;
}

void sol(){
    int n;
    cin >> n;
    int piles[n];
    int total = 0;
    int steps = 0;
    
    for (int i = 0; i < n; i++){
        cin >> piles[i];
        total += piles[i];
    }
    int avg = total / n;
    int extra = 0;
    for (int i = 0; i < n; i++){
        
        if(piles[i] == avg){
            continue;
        }else if(piles[i] > avg){
            while(piles[i] > avg){
                piles[i] -= 1;
                extra += 1;
                steps += 1;
            }
        }else if(piles[i] < avg){
            while(piles[i] < avg){
                piles[i] += 1;
                extra -= 1;
                steps += 1;
            }
        }
    }
    cout << steps / 2 << endl;

}