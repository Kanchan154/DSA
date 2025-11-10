#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// check that the the config is valid or not
bool isValid(vector<int> &rows, int cows, int size, int MinAllowed)
{
    int cow = 1, space = rows[0];
    for (int i = 1; i < size; i++)
    {
        if ((rows[i] - space) >= MinAllowed)
        {
            cow++;
            space = rows[i];
        }
        if(cows == cow){
            return true;
        }
    }
    return false;
}

// get the maximum space between the cows
void cow_Slots(vector<int> &rows, int cows)
{
    // sort the array first
    sort(rows.begin(), rows.end());

    // find start and end value of the search space
    int size = rows.size();
    int start = 1, mid, end = rows[size - 1] - rows[0];

    // find the mid value
    int answer = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isValid(rows, cows, size, mid))
        { // if possible then move to right part
            answer = mid;
            start = mid + 1;
        }
        else
        { // if not possible move to the left part
            end = mid - 1;
        }
    }
    cout << "The value is: " << answer;
}
int main()
{
    vector<int> rows = {1, 2, 8, 4, 9};
    cow_Slots(rows, 3);
    return 0;

}


