#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    int datas;
    string s;
    cin >> datas;
    while (datas--){
        cin >> s;
        int a = 0, b = 0; //ax + b = 0
        int buf = 0; //數字暫存器
        int neg = 1; //正數: 1, 負數: -1
        int left = 1; //等號右邊: -1
        bool hasNum = false;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '='){
                b += buf * left * neg;
                left = -1;
                neg = 1;
                buf = 0;
                hasNum = false;
            } else if (s[i] == 'x'){
                if (!hasNum && buf == 0) buf = 1; // x 係數為 1
                a += buf * left * neg;
                buf = 0;
                hasNum = false;
            } else if (s[i] == '-'){
                b += buf * left * neg;
                neg = -1;
                buf = 0;
                hasNum = false;
            } else if (s[i] == '+'){
                b += buf * left * neg;
                neg = 1;
                buf = 0;
                hasNum = false;
            } else{
                hasNum = true;
                buf *= 10;
                buf += s[i] - '0';
            }
        }
        if (buf > 0) b += buf; //最後可能還有數字未處理
         
        if (a == 0 && b == 0) cout << "IDENTITY\n";
        else if (a == 0 && b != 0) cout << "IMPOSSIBLE\n";
        else cout << (int)floor((double)(-b) / (double)a) << "\n";
    }
    return 0;
}