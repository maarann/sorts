#include<iostream>
using namespace std;

void print(int *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void insertionsort(int *arr, int n) {

    for (int i=1; i<n; i++) {
        int j = i-1;

        while(j >= 0 && arr[j+1] < arr[j]) {
            swap(arr[j], arr[j+1]);
            j--;
        }
    }
} 

int main() {
    int arr[] = {3, 2, 10, 0, -4, -10, 7, 2, 8};
    int n = sizeof(arr)/sizeof(*arr);
    print(arr, n);
    insertionsort(arr, n);
    print(arr,n);
    return 0;
}