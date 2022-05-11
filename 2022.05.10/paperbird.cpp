#include <iostream>
using namespace std;

#define ll long long

void paperbird(int datas);

int main(){
    while(true){
        int datas;
        cin >> datas;
        if(datas == 0)
            break;
        paperbird(datas);
    }
}

void paperbird(int datas){
    int answer, idx = 1;
    ll former_area = 0;
    while(datas--){
        ll width, height;
        cin >> width >> height;
        ll tmp_area = width * height;
        if(tmp_area > former_area){
            former_area = tmp_area;
            answer = idx;
        }
        idx += 1;
    }
    cout << answer << endl;
}