#include<iostream>
using namespace std;

void print(int *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void merge(int *arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (int i=0; i<n1; i++){
        L[i] = arr[p + i];
    }
    
    for (int i=0; i<n2; i++){
        R[i] = arr[q + 1 + i];
    }
 
    int i=0, j=0;
    for (int k=p; k<=r; k++) {
        if (j == n2 || (i != n1 && L[i] <= R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergesort(int *arr, int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    int arr[] = {3, 2, 10, 0, -4, -10, 7, 2, 8};
    int n = sizeof(arr)/sizeof(*arr);
    print(arr, n);
    mergesort(arr, 0, n-1);
    print(arr,n);
    return 0;
}