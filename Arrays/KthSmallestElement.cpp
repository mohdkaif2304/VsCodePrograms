
#include<iostream>
using namespace std;

void increment(int num) {
    num++;
}

int main() {
    int number = 5;
   cout <<  increment(number);
    // The value of 'number' remains unchanged (still 5)
    return 0;
}
