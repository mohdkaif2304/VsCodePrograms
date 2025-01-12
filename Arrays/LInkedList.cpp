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

void deleteNode(int position , Node* & head ){
    
    if (position == 1 ){ // 2 -> 3
     Node* temp ; 
     temp=head ;
     head = head ->next ;
     temp->next = NULL ; //  why this line because whenever we are deeitng make sure that the next is not pointing to 
     // somoene the deleted node should be pointed to null
     delete(temp);
    }

    else {
        // deleting any middle node or last node 
        Node* prev  = NULL ; //  1 -> 2 -> 3 -> 4 -> 5
        Node* curr = head ; 
        int count = 1; 

        while (count < position){
            prev = curr ; 
            curr = curr->next ;
            count ++ ;
        }

        prev->next = curr->next ; 
        curr->next = NULL ;//  same reason mentioned as above 
        delete curr ;

    }
    
}
void insertAtHead( Node* &head , int data){
Node *temp =  new Node(data) ; 
temp->next = head ;
head = temp; 
}
void insertAtTail(Node*&tail , int data ){ //  2 - >  3 - > 4 - > 5(tail)
    Node *temp = new Node(data); // we are inserting at the tail you know as we pointed out the tail in the node1 , so for now node1 is pointing as a tail
    // and it will update accordingly and same is in the case of head 
    tail->next = temp ; 
    tail = temp  ;
}

void insertAtPosition (Node* &head , Node* &tail , int data , int position ){
if(position == 1){
    insertAtHead(head,data );                   
    return ;
}
//  2 -> 3 - > 4 -> 5
   Node* temp = head ; // we have made this temp node just to reach the previous node where we have  to insert the node in actual 
   int count = 1; 
   while (count < position -1 ){ // count < position because it is starting from 1 and we want the node which is 1 popsition smaller 
    temp = temp->next ; 
    count ++ ; 
   }

   if (temp-> next  == NULL){
    insertAtTail(tail , data);
    return ;
   }

   Node* nodeToInsert = new Node(data) ; 
   nodeToInsert->next = temp->next ;
   temp->next = nodeToInsert ; 
   
}
void printNode (Node* &head ){
   
    Node *temp  = head ;
    while (temp != NULL){
            cout << temp ->data << "  "; 
            temp = temp->next ;
    }

   cout << endl ;
}

int main()
{

      Node *node1 = new Node(10) ;
    //  cout << node1 ->data << endl;
    //  cout << node1 ->next << endl;
      Node * head = node1 ; // head pointed at node1 
      Node* tail  = node1 ;
      printNode(head);
      insertAtTail(tail , 100);
      insertAtHead(head , 20);
      printNode(head);
      int position = 3 ; 
      cout << "Here we are inserting it int  the position : " << position << endl ; 
      insertAtPosition(head , tail , 500 , position);
      printNode(head);  

      deleteNode(2 ,head);
      printNode(head);
      
 return 0;
}