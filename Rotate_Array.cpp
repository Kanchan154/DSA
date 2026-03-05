#include<iostream>
using namespace std;

void rotateArray(int arr[],int n, int k){
    int start = 0, end = n-1;
    // reversing the array
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    // reverse the array till the kth element
    start = 0;
    end = n-1;
    while(start < k){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    // reverse the array after the kth element
    start = k;
    end = n-1;
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    // print the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rotateArray(arr,n, 4);
    return 0;
}