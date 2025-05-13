#include<iostream>
using namespace std;

void QuickSort(int a[],int low,int high){
    if(low < high){
        int pivot = a[high];
        int i = low-1,temp,j;
        for(j=low;j<=high;j++){
            if(a[j] < pivot){
                ++i;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[i+1];
        a[i+1] = a[high];
        a[high] = temp;
        QuickSort(a,low,i);
        QuickSort(a,i+2,high);
    }
}

int main(){
    int i,j,n,low,high,pivot,temp;
    cout << "Enter the array size : ";
    cin >> n;
    int a[n];
    cout << "\n *******************  Enter the values in array  *****************\n";
    for(i=0;i<n;i++){
        cout << "Enter the value in  " << i << "  position : ";
        cin >> a[i];
    }

    cout << "\n *****************  Printing the array  **************\n";
    for(i = 0;i < n ; i++){
        cout << a[i] << "\t";
    }

    //                  MERGE SORT
    QuickSort(a,0);

    cout << "\n*******************  Sorted aray by MERGE SORT  *******************\n";
    for(i=0;i<n;i++){
        cout << a[i] << "\t";
    }


}