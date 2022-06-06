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
    int n, target;
    cin >> n >> target;
    int money[n];
    int answer;
    for(int i = 0; i < n; i++){
        cin >> money[i];
    }
    int dp[target+1];
    dp[0] = 0;
    for(int i = 1; i < target+1; i++){
        dp[i] = target + 1;
    }
    for(int i = 1; i < target+1; i++){
        for(int j = 0; j < n; j++){
            if(i - money[j] >= 0){
                if(dp[i] < dp[i-money[j]] + 1){
                    dp[i] = dp[i];
                }else{
                    dp[i] = dp[i-money[j]] + 1;
                }
            }
        }
    }
    // for(int i = 1; i < target + 1; i++){
    //     cout << dp[i] << " "; 
    // }
    // cout << endl;
    cout << dp[target] << endl;

}