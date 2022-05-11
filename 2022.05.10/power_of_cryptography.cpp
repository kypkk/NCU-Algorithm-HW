#include <iostream>
#include<math.h>
using namespace std;

int main(){
    int datas;
    cin >> datas;
    while(datas--){
        long double n, p, k;
        cin >> n >> p;
        k = pow(p, (1/n));
        cout << k << endl;
    }
    return 0;
}