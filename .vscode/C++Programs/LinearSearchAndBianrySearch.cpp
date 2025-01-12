// Linear search & Binary search

#include<iostream>
using namespace std;

void LinearSearch(int arr[], int n)
{
    int key, i;
    cout<<"Enter the key: ";
    cin>>key;
    for(i=0; i<n; i++){
        if(key==arr[i])
        {
            cout<<"Element is found at index "<<i <<endl;
            break;
        }
    }
    if(key!=arr[i])
    {
        cout<<"Element id not found";
    }
}

void binarySearch(int arr[], int n)
{
    int start=0;
    int end=n-1;
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    int mid=start+(end - start)/2;
    for(start=0; start<=end;)
    {
        if(key==arr[mid])
        {
            cout<<"Element id founded at "<<mid+1;
        }
        if(key > arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;

    }
    if(key!=arr[mid])
    {
        cout<<"Element is not found";
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"\nPress 1 For Linear Search and 2 For Binary Search"<<endl;
    cin>>k;
    if(k==1)
    {
        LinearSearch(arr,n);
        
    }
    else if(k==2)
    {
        binarySearch(arr,n); 
    }

}