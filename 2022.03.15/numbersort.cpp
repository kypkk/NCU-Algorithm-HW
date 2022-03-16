#include <iostream>
#include <algorithm>
using namespace std;

struct Data{
    string s;
    int id, unsortedness;
};

int calUnsortedness(string s){
    int ret = 0;
    for (int i = 0; i < s.size(); i++){
        int cnt = 0;
        for (int j = i+1; j < s.size(); j++){
            if (s[j] < s[i]) cnt++;
        }
        ret += cnt;
    }
    return ret;
}

bool cmp(Data a, Data b){
    if (a.unsortedness != b.unsortedness) return a.unsortedness < b.unsortedness;
    else return a.id < b.id;
}

 

int main() {
    int T, n, m;
    cin >> T;
    while (T--){
        cin >> n >> m;
        Data data[m];
        for (int i = 0; i < m; i++){
            cin >> data[i].s;
            data[i].id = i;
            data[i].unsortedness = calUnsortedness(data[i].s);
        }
        cout << endl;
        sort(data, data+m, cmp);
        for (int i = 0; i < m; i++){
            cout << data[i].s << "\n";
        }

    }

    return 0;

}
