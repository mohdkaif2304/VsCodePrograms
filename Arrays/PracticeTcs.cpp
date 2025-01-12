#include<bits/stdc++.h>
using namespace std  ; 

int solve ( vector<string> & s , int N ){
  int sum = 0 ;
  int n = N + 1 ;
  for ( int i = 0 ; i < N ; i++ ) {
   int num = stoi(s[i]) ; 
   sum += num ;
  }

  int actualSum = (n * ( n + 1 ) )/ 2 ;
  return actualSum - sum ;
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
    solve_3(arr1); // Print the result
}


int main(){
// we need to calculate the missing number in an array 
int N ; 
cout << "Enter Size :" ;
cin >> N ;
cin.ignore() ;
cout << "Enter elements in a Form .. e1,e2,e3" << endl ;
string s  ; 
getline(cin, s);// firstly we will take the input separated by commas   //    [a ,   b ,     c]

//   // Remove the square brackets
//     s.erase(remove(s.begin(), s.end(), '['), s.end()); /// ----------->> This will be required for taking the bracket also in the input 
//     s.erase(remove(s.begin(), s.end(), ']'), s.end());
// [a so we need to remove this bcs stoi is coverting string into integer and we will unable to convert this [
stringstream ss(s);
string token ;
vector<string> ans ; 
while ( getline(ss , token ,',')){
ans.push_back(token);
}

cout << "Missing Nummber :" << solve(ans , N) << endl;
return 0 ;
}