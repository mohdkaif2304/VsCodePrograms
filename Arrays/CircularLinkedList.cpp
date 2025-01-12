#include<iostream>
using namespace std;

class Node {
public:
int data ;
Node *next ; // next pointer which is of type node 
    Node(int data ){
        this->data = data ;
        this-> next = NULL ;
    }

    ~Node(){
            int value = this->data ; 
            if(this-> next != NULL){
              delete next ; // we are deleting node (pointer) which is of Node type 
              this->next = NULL ;
            }
            cout << "Memory is free with the data " << value << endl ;
        }

};

void insertNode(Node* & tail , int element, int data ){

    // if the list is empty 
    if (tail == NULL){
    Node * newNode = new Node(data);
    tail = newNode ; 
    newNode->next = newNode ; 
    }
    else {
        Node* curr = tail ; 

        while (curr->data != element){
            curr= curr -> next  ;

        }

        Node* temp = new Node(data);
        temp->next = curr->next ;
        curr->next =temp ;


    }

}

void deleteNode(Node* &tail , int value){
     
     Node* prev = tail  ;
     Node* curr = prev->next  ;

// this is the case when the linked list is empty 
     if (tail == NULL){

        cout << "List is empty please be carefull before deleting " ; 
        return;

     }

// this is the case when in list only one node is present 

if (prev == curr){
    tail =NULL ;

}
// In start what you have done is you have updated the newnode as tail so your tail is in the start 
      //  so if  you want to deleted the starting node then you need to update your tail to prev 

      else if(tail == curr){ // if tail == current and we are deleting current so that will go wrong if we will delete the first node 
      // in the linked list so we will do tail = prev 
          tail = prev ;
      }

     while (curr->data != value){
        prev = curr ;
        curr = curr->next ;
     }

      prev->next = curr->next ;
      curr->next = NULL ;
      delete curr ;
}


void print(Node* &tail ){

    Node* temp = tail  ;

    if (tail == NULL){
        cout << "List is empty " << endl  ; 
        return ;
    }

do{
    cout << tail->data << " " ;   
     tail = tail->next ;
}  while(tail != temp );

    // this code has some logic missing because when there is single node then it will not print the node
    // so you have to use like do while loop for first printing and then checking or handle this case
    // diferently or accordingly .....
    // while (tail->next != temp ){
    //  cout << tail->data << " " ;   
    //  tail = tail->next ;
    // }
    cout << "Tail is : " << tail->data ;
    cout << endl ;
    
}


int main()
{

    Node* tail = NULL ; 
    insertNode(tail , 5 ,3);
    print(tail) ;
    // insertNode(tail , 3 ,5);
    // print(tail) ;
    // insertNode(tail , 5 ,7);
    // print(tail) ;
    //  insertNode(tail , 7 ,40);
    // print(tail) ;
    // insertNode(tail , 3 ,50);
    // print(tail) ;
    // insertNode(tail , 5 ,700);
    // print(tail) ;

    deleteNode(tail , 3);
    print(tail);
 return 0;
}