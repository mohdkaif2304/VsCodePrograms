#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& arr) {
    stringstream result;
    for (auto n : arr) {
        int num = stoi(n);
        if (num % 3 == 0 && num % 5 == 0) {
            cout << "ThreeFive " << " ";
        } else if (num % 5 == 0) {
            cout << "Five "<< " ";
        } else if (num % 3 == 0) {
            cout << "Three "<< " ";
        } else {
            cout << num << " ";
        }
    }
}
void input_array_format1() {
    int n; cin >> n;
    cin.ignore(); 
    string input;
    getline(cin, input);
    input.erase(remove(input.begin(), input.end(), '['), input.end()); // Remove '['
    input.erase(remove(input.begin(), input.end(), ']'), input.end()); // Remove ']'
    stringstream ss(input);
    vector<string> arr1;
    string element;
    while (ss >> element) { // Read elements separated by space
        arr1.push_back(element);
    }
    solve(arr1); // Print the result
}

int main() {
    input_array_format1();
    return 0;
}

/**
 * #include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool isArmStrongNumber(int n, int k) {
    int sum = 0;
    int originalNum = n;
    while (originalNum > 0) {
        int digit = originalNum % 10;
        sum += pow(digit, k);
        originalNum /= 10;
    }
    return sum == n;
}

int main() {
    string input;
    cout << "Enter numbers separated by commas: ";
    getline(cin, input);

    // Using stringstream to split the input string by commas
    stringstream ss(input);
    string temp;
    vector<int> numbers;

    // Extract numbers from the input string
    while (getline(ss, temp, ',')) {
        numbers.push_back(stoi(temp));
    }

    int flag = 0;
    for (int num : numbers) {
        int n = to_string(num).length();
        if (isArmStrongNumber(num, n)) {
            cout << num << " ";
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "No Armstrong numbers present";
    }
    return 0;
}

 */