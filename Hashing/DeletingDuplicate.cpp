#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;


vector<int> removeduplicates ( int * a , int size )
{

vector <int> output ; 
unordered_map <int, bool> seen ;

for (int i = 0; i < size; i++)
{
    if (seen.count(a[i]) > 0){
      continue;
    }
     seen[a[i]] = true ; 
     output.push_back(a[i]);

}
return output ;

}


int main()
{
    int a[] = { 1, 2, 3, 4,41, 3, 44,2,32,2,1};
    vector<int> output =  removeduplicates (a , 11 );
    for (int i = 0; i < output.size() ; i++)
    {
        /* code */
        cout<< output[i] << endl ;
    }
    


 return 0;
}










// vector<int> removeduplicates (int *a , int size ){
    
//     vector<int> output ; 
//     unordered_map<int , bool > seen; 

// for(int i = 0 ; i< size ; i++){

//  if (seen.count(a[i]) > 0 ){
//         continue;
//     }
//     seen[a[i]] = true ;
//     output.push_back(a[i]);

// }
// return output ;

// }