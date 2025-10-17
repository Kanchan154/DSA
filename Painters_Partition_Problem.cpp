#include <iostream>
#include <vector>

using namespace std;

/**
 * Given are N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of board
 * The task is to find the minimum time to paint all the boards under the constraints that any painter will only paint contineous section of boards. skipping any board is not allowed.
 */

// function to check whether the middle value is possible or not
bool isPossible(vector<int> boards, int size, int painters, int maxAllocatedTime)
{
    int pntr = 1, time = 0;
    for (int i = 0; i < size; i++)
    {
        if (boards[i] > maxAllocatedTime)
        {
            return false;
        }
        if ((time + boards[i]) <= maxAllocatedTime)
        {
            time += boards[i];
        }
        else
        {
            pntr++;
            time = boards[i];
        }
    }
    return pntr <= painters;
}

// function that gives the value of the minimum time
void Painter_Partition(vector<int> boards, int painters)
{
    int size = boards.size(), sum = 0;
    int start = boards[0];
    for (int i : boards)
    {
        sum += i;
        start = max(start, i);
    }
    int end = sum, answer = -1;
    // now start the binary Search
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        bool possible = isPossible(boards, size, painters, mid);
        if (possible)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "Minimum time taken to paint all the boards : " << answer << endl;
}
int main()
{
    vector<int> boards = {40, 30, 10, 20};
    Painter_Partition(boards, 2);
    return 0;

}


