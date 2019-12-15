#include<iostream>
using namespace std;

void print(int *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr, int p, int r) {
    int x = arr[r];
    int i = p-1;
    for (int j=p; j<=r-1; j++) {
        if (arr[j] <= x) {
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quicksort(int *arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}

int main() {
    int arr[] = {3, 2, 10, 0, -4, -10, 7, 2, 8};
    int n = sizeof(arr)/sizeof(*arr);
    print(arr, n);
    quicksort(arr, 0, n-1);
    print(arr,n);
    return 0;
}