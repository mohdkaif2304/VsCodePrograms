#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // next pointer which is of type node
    Node *prev; // prev pointer which is also the type of node
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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

void insertAtHead(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {

        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&tail, Node *&head, int data)
{

    if (tail == NULL)
    {

        Node *temp = new Node(data);
        tail = temp;
        head = temp;
        return;
    }
    else
    {

        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void printNode(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }

    cout << endl;
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, head, data);
        return;
    }
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(int position , Node* & head ){
    
    if (position == 1 ){
     Node* temp = head ; 
     head = temp ->next ;
     temp->next->prev = NULL ;
     temp->next = NULL ; //  why this line because whenever we are deeitng make sure that the next is not pointing to 
     // somoene the deleted node should be pointed to null
     delete(temp);
    }

    else {
        // deleting any middle node or last node 
        Node* prev  = NULL ;
        Node* curr = head ; 
        int count = 1; 

        while (count < position){
            prev = curr ; 
            curr = curr->next ;
            count ++ ;
        }

        curr->prev = NULL ; 
        prev->next = curr->next ;
        curr->next->prev = prev ; // this condition is something that i have written with my own undertstanding 
        curr->next =NULL ;
        delete curr ;

    }
    
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 10);
    printNode(head);
    insertAtTail(tail, head, 20);
    printNode(head);
    insertAtHead(head , tail , 30);
    printNode(head);
    insertAtTail(tail, head , 40 );
    printNode(head);
    insertAtPosition(head, tail, 300, 2);
    printNode(head);
    cout << "Head is : " << head->data << " "; 
    cout << "Tail is : " << tail->data ;  


    deleteNode(1, head);
    printNode(head) ;
    return 0;
}