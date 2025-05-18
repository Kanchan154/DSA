#include<iostream>
using namespace std;

int main(){
    int size,i,j;
    
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];
    cout << "Enter the values in array : " << endl;
    for (i = 0;i < size;i++ ){
        cout << "Enter the element in " << i << " position : ";
        cin >> arr[i];
    }
    cout << "\n *****************  Printing the array  **************\n";
    for(i = 0;i < size ; i++){
        cout << arr[i] << "\t";
    }

    //                  Selection Sort
    int temp,loc,min;
    for(i = 0;i < size-1;i++){
        min = arr[i];
        loc = i+1;
        for(j = i+1;j < size;j++){
            if(min > arr[j]){
                min = arr[j];
                loc = j;
            }
        }
        if(arr[loc] < arr[i]){
            temp = arr[loc];
            arr[loc] = arr[i];
            arr[i] = temp;
        }
    }

    
    cout << "\n*******************  Sorted aray by SELECTION SORT  *******************\n";
    for(i=0;i<size;i++){
        cout << arr[i] << "\t";
    }
}