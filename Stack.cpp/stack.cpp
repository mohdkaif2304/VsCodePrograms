#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> stack;
    cout << "This is the basic implementation of the stack " << endl ; 
    stack.push(1); 
    stack.push(3);
    stack.push(4); 
    stack.push(5); 

   cout << "This is the top element of the stack now " <<  stack.top();
   cout << endl ;
    while (!stack.empty()){
        cout << stack.top(); 
        stack.pop();
    }

cout << "Total element in a stack " << stack.size();

 return 0;
}
