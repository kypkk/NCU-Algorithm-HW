#include <iostream>
using namespace std;

int main(){
    while(true){
        int arr[101] = {0};
        int tmp;
        int length;
        int ans[2000000];
        int count = 0;
        cin >> length;
        if(length == 0) break;
        for(int i = 0; i < length; i++){
            cin >> tmp;
            arr[tmp]++; 
        }
        for(int i = 0; i < 100; i++){
            while(arr[i]--){
                ans[count] = i;
                count++;
            }
        }
        for(int i = 0; i < length - 1; i++){
            cout << ans[i] << " ";
        }    
        cout << ans[length - 1] << endl;
    }

    return 0;
}