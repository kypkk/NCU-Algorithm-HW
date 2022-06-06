#include <iostream>

using namespace std;

void sol();
void merge_sort(int *arr, int low, int high);
void merge(int *arr, int low, int high, int mid);

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
    int blue[n], red[n];

    int idx_blue = 0;
    int idx_red = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp < 0){
            red[idx_red] = tmp * -1;
            idx_red += 1; 
        }else{
            blue[idx_blue] = tmp;
            idx_blue += 1;
        }
    }
    merge_sort(blue, 0, idx_blue-1);
    merge_sort(red, 0, idx_red - 1);

    int answer = 0;

    int new_idx_blue = 0;
    int new_idx_red = 0;
    int handle;
    int tmp = 0;

    if(blue[new_idx_blue] > red[new_idx_red]){
        handle = 1;
    }else{
        handle = 2;
    }

    for(int i = 0; i < n; i++){
        if(handle == 1){
            handle = 2;
            while(red[new_idx_red] < tmp && new_idx_red < idx_red ){
                new_idx_red += 1;
            }
            
            if(new_idx_red == idx_red){
                break;
            }else{
                tmp = red[new_idx_red];
                new_idx_red += 1;
                answer += 1;
            }
        }else if(handle == 2){
            handle = 1;
            while(blue[new_idx_blue] < tmp && new_idx_blue < idx_blue){
                new_idx_blue += 1;
            }

            if(new_idx_blue == idx_blue){
                break;
            }else{
                tmp = blue[new_idx_blue];
                new_idx_blue += 1;
                answer += 1;
            }
        }
        
    }
    
    cout << answer << endl;

}


void merge_sort(int *arr, int low, int high){
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}
// Merge sort 
void merge(int *arr, int low, int high, int mid){
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}