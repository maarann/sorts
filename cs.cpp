#include<iostream>
using namespace std;

void print(int *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countingsort(int *arr, int *res, int n, int k) {
    int count[k+1];

    for (int i=0; i<n; i++) {
        res[i] = 0;
    }

    for (int i=0; i<=k; i++) {
        count[i] = 0;
    }

    for (int i=0; i<n; i++) {
        count[arr[i]] += 1;
    }

    for (int i=1; i<=k; i++) {
        count[i] += count[i-1];
    }

    for (int i=n-1; i>=0; i--) {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]] -= 1;
    }
}

int main() {
    int arr[] = {3, 2, 10, 0, 4, 10, 7, 2, 8};
    int n = sizeof(arr)/sizeof(*arr);
    int res[n];
    print(arr, n);
    countingsort(arr, res, n, 10);
    print(res,n);
    return 0;
}