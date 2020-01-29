#include<iostream>
using namespace std;

void print(float *arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

struct node {
    float data;
    node* next;
};

node* createNode(float data) {
    node* newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void printLinkedList(node* head) {
    while(head != NULL) {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}

void insertAtEnd (node* head, float data) {
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = createNode(data);
}

void insertionSort (node* head) {
    node* temp = head;

    while (temp->next != NULL) {
        if (temp->data > temp->next->data) {
            node* cur = temp->next;
            temp->next = temp->next->next;
            node* temp2 = head;
            node* prev = NULL;
            while (temp2->data < cur->data) {
                prev = temp2;
                temp2 = temp2->next;
            }
            if (prev == NULL) {
                cur->next = head;
                head = cur;
            } else {
                cur->next = prev->next;
                prev->next = cur;
            }
        } else {
            temp = temp->next;
        }
    }
}

void bucketsort (float *arr, int n) {
    node** buckets = new node*[n];
    for (int i=0; i<n; i++) {
        buckets[i] = createNode(0.0);
    }

    for (int i=0; i<n; i++) {
        int index = arr[i] * n;
        insertAtEnd(buckets[index], arr[i]);
    }

    for (int i=0; i<n; i++) {
        insertionSort(buckets[i]);
    }

    for (int i=0, j=0; i<n; i++) {
        node* temp = buckets[i]->next;
        
        while (temp != NULL) {
            arr[j] = temp->data;
            temp = temp->next;
            j++;
        }
    }
}

int main() {
    float arr[] = {0.897, 0.665, 0.656, 0.1234, 0.565, 0.3434};
    int n = sizeof(arr)/sizeof(*arr);
    print(arr, n);
    bucketsort(arr, n);
    print(arr,n);
    return 0;
}
