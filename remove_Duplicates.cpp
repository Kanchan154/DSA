#include <iostream>
#include <vector>
using namespace std;

// create array with duplicate values
int main(){
    vector<int> arr = {1,1,1,2,2,2,3,3,3,3};
    int n = arr.size();
    int unique = 1;
    int i = 0,j = 1;
    return 0;
    while (j < n){
        if(arr[j] == arr[j-1]){
            i++;
            continue;
        }
        arr[i+1] = arr[j];
        i++;
        j++;
    }
    for(int x = 0;x<i; x++){
        cout << arr[x] << '\n';
    }
    
}