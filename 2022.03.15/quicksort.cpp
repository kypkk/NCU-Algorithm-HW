#include <iostream>
using namespace std;
#define max 1000000

int size ;
/* Function to swap twp elements in an array */
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* Function to print an array */
void printArray(int arr[], int length){
    int i;
    for (i = 0; i < length - 1; i++)
        cout << arr[i] << " ";
    cout << arr[length - 1];
    cout << endl;
}

void quickSort(int arr[], int lb, int rb){
    if(lb < rb){
        int pivot = arr[rb];
        int l = lb;
        int r = rb - 1;
        while(true){
            while(arr[l] < pivot){
                l++;
            }
            while (arr[r] >= pivot && r != lb){
                r--;
            }
            if(l < r){
                swap(&arr[l], &arr[r]);
                printArray(arr, size);
            }else break;
        }
        if(rb != l){
            swap(&arr[rb], &arr[l]);
            printArray(arr, size);
        }
        quickSort(arr, lb, l - 1);
        quickSort(arr, l + 1, rb);
    }

}

int main(){
    int arr[max];
    int element = 1;
    int i = 0;

    
    while(cin >> element){
        arr[i] = element;
        if(getchar() == '\n') break;
        i++;
    }
    size = i + 1;
    printArray(arr, size);
    quickSort(arr, 0, i);

    return 0;
    
}