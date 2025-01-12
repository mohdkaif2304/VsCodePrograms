//queue using circular array

#include<iostream>
using namespace std;

#define size 6 //macros
int A[size];
int front = -1;
int rear = -1;

//isEmpty method
bool isEmpty()
{
    if(front==-1 && rear==-1)
        return true;
    else
        return false;
}

//enqueue method
void enqueue(int value)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is full"<<endl;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        A[rear]=value;
    }
}

//dequeue method
void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty";
    }
    else{
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front-1)%size;
        }
    }
}

//showfornt method
void showfornt()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty";
    }
    else{
        cout<<"Element at front: "<<A[front]<<endl;
    }
}

//display method
void display()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty";
    }
    else{
        int i;
        if(front<=rear)
        {
            for(i=front; i<=rear; i++)
            {
                cout<<A[i]<<" ";
            }
        }
        else{
            i=front;
            while(i<size){
                cout<<A[i]<<" ";
                i++;
            }
            i=0;
            while(i<=rear){
                cout<<A[i]<<" ";
                i++;
            }
        }
    }
}

int main()
{
    enqueue(5);
    enqueue(9);
    enqueue(4);
    enqueue(7);
    enqueue(8);
    enqueue(10);
    display();
}