#include <iostream>
#include <cmath>
using namespace std;

int fact(int a){
    if(a == 0){
        return 1;
    }
    int fac = 1;
    while(a > 1){
        fac *= a;
        a--;
    }
    return fac;
}

int uniquePaths1(int m, int n){  
    if(m <= 0 || n <= 0){  
        return 0;  
    }else if(m == 1 || n == 1){  
        return 1;  
    }else if(m == 2 && n == 2){  
        return 2;  
    }  
    uniquePaths1(m - 1, n);  
    uniquePaths1(m , n-1);  
    return uniquePaths1(m - 1, n)+uniquePaths1(m , n-1);  
}  

static int arr[101][101] = { 0 };  
int uniquePaths2(int m, int n){   //机器人从一个 m x n 网格的左上角 走到右下角的方法（只能向右或向下走）1.递归实现  
    if(m <= 0 || n <= 0){  
        return 0;  
    }  
    if(m == 1 || n == 1){  
        return 1;  
    }  
    if(m == 2 && n == 2){  
        return 2;  
    }  
    if(arr[m][n] > 0){  
        return arr[m][n];  
    }  
    arr[m-1][n]=uniquePaths1(m - 1, n);  
    arr[m][n-1]=uniquePaths1(m , n-1);  
    arr[m][n] = arr[m - 1][n] + arr[m][n - 1];  
    return arr[m][n];  
}
int dp_uniquePaths(int m,int n){
    if(m == 1 || n == 1) return 1;
    int arr[m][n];
    arr[0][0] = 1;
    for(int i = 1;i<m;i++) {
        for(int j = 1;j<n;j++) {
            if(i - 1 == 0 ) {
                arr[i - 1][j] = 1;
            }
            if(j - 1 == 0) {
                arr[i][j - 1] = 1;
            }
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    return arr[m-1][n-1];
}
int main() {
    int datas;
    cin >> datas;
    for(int i = 0; i < datas; i++){
        int num1, num2;
        cin >> num1 >> num2;
        // int x = fact((num1 + num2 - 2));
        // int y = fact((num1 - 1));
        // int z = fact((num2 - 1));
        // y = y * z;
        // int answer = x / y;
        int answer = dp_uniquePaths(num1, num2);
        cout << answer << endl;
    }
}