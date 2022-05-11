#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
#define ll long long
ll things[1000000];
ll dp[10000000];
void min();
int main(){
    int datas;
    cin >> datas;
    dp[0] = 0;
    while(datas--){
        min();
    }
    return 0;
}

void min(){
    ll datas;
    ll min = numeric_limits<ll>::max();
    ll answer;
    cin >> datas;
    
    for(ll i = 0; i < datas; i++){
        cin >> things[i];
    }
    if(datas == 1){
        cout << 0 << endl;
        return;
    }
    for (ll i = 0; i < datas; i++){
        dp[i + 1] = dp[i] + things[i]; // dp 中每個元素都是前n項的和
    }
    
    for(ll i = 0; i < datas; i++){
        if(i < datas - 1){
            ll avg_1 = dp[i+1]; 
            ll avg_2 = dp[datas] - avg_1; 
            avg_1 = floor(avg_1 / (i+1)); // avg_1 是第一個部分的平均
            avg_2 = floor(avg_2 / (datas-i-1)); // avg_2 是第二個部分的平均
            ll diff = avg_1 - avg_2;
            if(diff < 0){
                diff = -diff;
            }
            if(diff < min){
                min = diff;
                answer = i; //答案就是最小絕對值平均差的index
            }
        }else{
            ll avg_1 = dp[i+1]; 
            ll avg_2 = dp[datas] - avg_1; 
            avg_1 = floor(avg_1 / (i+1)); // avg_1 是第一個部分的平均
            ll diff = avg_1 - avg_2;
            if(diff < 0){
                diff = -diff;
            }
            if(diff < min){
                min = diff;
                answer = i; //答案就是最小絕對值平均差的index
            }
        }
    }
    cout << answer << endl;
    return;
}