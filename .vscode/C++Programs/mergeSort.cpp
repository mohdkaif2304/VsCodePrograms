#include <iostream>
using namespace std;
// This is the function of the merge simply merges the two array ..
void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // This is the Way of Declaring the array of length1 and Length2 dynamically as we dont know the size that's why we
    // need to go for the dynamic size of an array ...
    int *first = new int[len1];
    int *second = new int[len2];
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }
    int index1 = 0;
    int index2 = 0;
    k = start;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}
// As you know merge sort is based on the divide and conquer method so in this wee are dividing the array into two equal
// halves .. Right part and the left one as the function name is same so they are running in parallel and also
// at the same time they are calling the merge function but the merge function did not executed because no base case
// reaches till now when the base casee will reach it will retuen the function call and the backtracing of the function
// call will start taking place
void divide(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    divide(arr, start, mid);
    divide(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{

    int arr[4] = {42, 5, 222, 13};
    int start = 0;
    int n = 4;
    int end = n - 1;
    int mid = (start + end) / 2;
    divide(arr, start, end);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}