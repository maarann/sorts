#include<iostream>
using namespace std;

void print(int *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubblesort(int *arr, int n) {
    for (int i=0; i<n-1; i++) {
        int flag = 0;
        for(int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

int main() {
    int arr[] = {3, 2, 10, 0, -4, -10, 7, 2, 8};
    int n = sizeof(arr)/sizeof(*arr);
    print(arr, n);
    bubblesort(arr, n);
    print(arr,n);
    return 0;
}