#include<iostream>
using namespace std;

void print(int *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionsort(int *arr, int n) {
    for (int i=0; i<n-1; i++) {
        int min_i = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }
        }
        swap(arr[i], arr[min_i]);
    }
}

int main() {
    int arr[] = {3, 2, 10, 0, -4, -10, 7, 2, 8};
    int n = sizeof(arr)/sizeof(*arr);
    print(arr, n);
    selectionsort(arr, n);
    print(arr,n);
    return 0;
}