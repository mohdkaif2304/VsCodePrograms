#include <iostream>
using namespace std;

class Node {
public :
int data ;
Node* next  ;
Node (int val ){
data = val ;
next = NULL ;
}
};

void insertAtTail (Node* &head , int val ){
    Node * temp = new Node(val) ;
if (head == NULL){
head = temp ;
return ;
}
Node* ptr  = head ;
    while (ptr -> next != NULL){
ptr = ptr ->next ;
}
ptr -> next = temp ;  
}
void insertAthead (Node*  &head , int val ){
     Node* temp = new Node(val) ;
   temp->next = head ;
   head = temp ; 
}
void insertAtAnyPosition (Node * &head , int val ,int pos ){
Node* temp = head  ;
 int i ;   
for (int i = 1 ; i < pos - 1 ; i++){
temp = temp -> next ;
}
Node *newNode = new Node (val) ;
newNode ->next = temp ->next ;
temp -> next = newNode ;
}
void deleteAtHead (Node * &head){
Node * temp = head ;
head = head ->next ;
delete(temp );
}
void deleteNode (Node* &head , int val){

Node *temp = head ;
while (temp ->data != val){
temp = temp ->next;

}
Node *toDelete = temp ->next ;
temp->next = temp->next->next ;
delete (toDelete) ;

}

void display (Node* head ){
Node* temp = head ;
while (temp != NULL){
    cout << temp->data << "->";
    temp = temp->next ;
}
cout << "NULL" << endl ;

}
int main()
{

cout << "Insert at Tail" <<endl ;
Node* head = NULL ;
insertAtTail(head ,1 );
insertAtTail(head ,10 );
insertAtTail(head ,100 );
insertAtTail(head ,1000 );
insertAtTail(head ,100000 );
display(head) ;
//insertAthead(head , 20);
insertAthead(head , 20000);
display(head);
insertAtAnyPosition(head , 3000 , 4);
deleteAtHead(head);
deleteNode(head , 3000);
display(head);
    return 0;
}