// Lets introduce you to the algorithm of selection sort -->>
#include <iostream>
using namespace std;
void PrintArray(int arr[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}
// selction sort and bubble sort are somewhat opposite of each other
// as in selection sort the smaller element is on the lhs side similiarly in bubble sort the greater element is on the
// rhs side
void selectionsort(int arr[], int size)
{
    for (int i = 0; i <= size - 2; i++)
    {
        int first = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[first])
                swap(arr[j], arr[first]);
        }
    }
    PrintArray(arr, size);
}

void bubbleSort(int arr[], int size)
{

    for (int i = size - 1; i >= 0; i--)
    {                    // 3 , 6 , 2 , 1 , 8 , 0 , 9
        //int last = size -1 ; //                         last
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    PrintArray(arr, size);
}

int main()
{
    int n = 7;
    int arr[n] = {3, 6, 2, 1, 8, 0, 9};
    cout << "Result of selection sort", selectionsort(arr, n); // 0 to 6 ( size = 7 )
    cout << "Result of Bubble sort", bubbleSort(arr, n);

    return 0;
}