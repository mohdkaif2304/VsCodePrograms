//array

#include<iostream>
using namespace std;

//updation the in the array
void updataAtArray(int arr[], int n)
{
    int pos, x;
    cout<<"Enter the position that where you want to insert: "<<endl;
    cin>>pos;
    cout<<"Enter the value that you want to insert: ";
    cin>>x;
    arr[pos-1]=x;
    cout<<"the array element after update: "<<endl;

}

//deletion in array
void deletionInArray(int arr[], int n)
{
    int pos;
    cout<<"Enter the position that you want to delete from the array: ";
    cin>>pos;
    --pos; // as index of the element to be delete is 1 less then its position
    for(int i =pos; i<=n; i++)
    {
        arr[i]=arr[i+1];
    }

    cout<<"After deletion the element of array"<<endl;
    for(int i=0; i<n-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

//print the array
void printArray(int arr[] , int n)
{
    //traversal
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the of size of array: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //traversal function called
    printArray(arr,n);

    //deletion
   // deletionInArray(arr,n);

    //updata
    updataAtArray(arr,n);
    printArray(arr,n);
    
}