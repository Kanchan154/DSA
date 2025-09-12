#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> bookArray, int size, int students, int maxAllowedPages)
{
    int stu = 1, pages = 0;
    for (int i = 0; i < size; i++)
    {
        if (bookArray[i] > maxAllowedPages)
        {
            return false;
        }
        if ((pages + bookArray[i]) < maxAllowedPages)
        {
            pages += bookArray[i];
        }
        else
        {
            stu++;
            pages = bookArray[i];
        }
    }
    return stu > students ? false : true;
}

void allocateBook(vector<int> bookArray, int students)
{
    int sum = 0;
    int size = bookArray.size();
    if (students > size)
    {
        cout << "The value is : " << -1 << endl;
        return;
    }
    int answer = -1;
    for (int i = 0; i < size; i++)
    {
        sum += bookArray[i];
    }
    int start = 0, end = sum;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(bookArray, size, students, mid))
        { // left
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "The value is : " << answer << endl;
}

int main()
{

    vector<int> bookArray = {2, 1, 3, 4};
    allocateBook(bookArray, 2);

    return 0;

}

