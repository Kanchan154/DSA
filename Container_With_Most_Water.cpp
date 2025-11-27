#include <iostream>
#include <vector>

using namespace std;

// brute force approach to find the container with the maximum volume in the container
void MostWater(vector<int> &bars)
{
    int width, height;
    double maximum_Volume = 0.0;
    int n = bars.size();
    for (int i : bars)
    {
        double curr_Vol = 0.0;
        for (int j = i + 1; j < n; j++)
        {
            width = j - i;
            height = min(bars[i], bars[j]);
            curr_Vol = width * height;
            maximum_Volume = max(curr_Vol, maximum_Volume);
        }
    }
    cout << "Maximum volume that can be stored is : " << maximum_Volume << endl;
}

// two pointer approach to find the maximum volume in the containers 
void MostWater_Using_Two_Pointer(vector<int> bars)
{
    int left = 0, right = bars.size() - 1;
    double max_Vol = 0.0, curr_Vol = 0.0;
    while (left < right)
    {
        curr_Vol = min(bars[left], bars[right]) * (right - left);
        max_Vol = max(max_Vol, curr_Vol);
        
        (bars[left] < bars[right]) ? left++ : right--;
    }
    cout << "Maximum volume that can be stored is : " << max_Vol << endl;
}

int main()
{
    vector<int> bars = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    MostWater(bars);
    MostWater_Using_Two_Pointer(bars);
}
