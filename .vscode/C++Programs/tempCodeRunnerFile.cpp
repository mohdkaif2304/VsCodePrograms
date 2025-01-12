#include <iostream>
using namespace std;

int
main ()
{
  cout << " Algorithm of  Insertion Sort ..." << endl;
  int n;
  cout << " Enter the value of N -->> ";
  cin >> n;
  int arr[n];
  cout << "Enter N Number of elements -->> " << endl;
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << " Program Before Sorting :) " << endl ;
 for (int i = 0; i < n; i++)
    {
      cout << "  " << arr[i] << " ";
    }
cout << endl ;
  for (int i = 1; i < n; i++)
    {

      int temp = arr[i];
      int j = i - 1;
      for (; j >= 0; j--)
	{

	  if (arr[j] > temp)
	    {
	      arr[j + 1] = arr[j];
	    }
	  else
	    break;
	}
      arr[j + 1] = temp;
    }
     cout << " Program After Sorting :) " << endl ;
  for (int i = 0; i < n; i++)
    {
      cout << "  " << arr[i] << " ";
    }


  return 0;
}