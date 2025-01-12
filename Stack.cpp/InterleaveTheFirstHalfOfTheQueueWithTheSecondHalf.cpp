#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q ){

    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;
 
    // Initialize an empty queue of int type
    queue<int> nq;
    int halfSize = q.size() / 2;
for (int i = 0; i < halfSize; i++) {
        nq.push(q.front());
        q.pop();
    }

    while(!nq.empty()){
       q.push(nq.front()) ; 
       q.push(q.front()); 
       nq.pop();
       q.pop() ;
    }
}

int main()
{

   queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    cout << "Now your function call occur " ; 
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
 return 0;
}