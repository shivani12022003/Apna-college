/*********{ TOPICS }*******
>SINGLE LL: INSERTION ,DELETION, DISPLAY, SEARCH,|(done) REVERSE, SHIFT, ROTATE, MERGE, PALINDROME
>DOUBLE LL: INSERTION ,DELETION, DISPLAY, SEARCH,REVERSE, SHIFT, ROTATE, MERGE, PALINDROME
>CIRCULAR-SINGLE LL: INSERTION ,DELETION, DISPLAY, SEARCH, SHIFT, ROTATE, MERGE
>CIRCULAR-DOUBLE LL: INSERTION ,DELETION, DISPLAY, SEARCH, SHIFT, ROTATE, MERGE
*/
/** PROPERTIES OF LL :
 * size can be modified 
 * noncontiguos memory 
 * insertion and deletion at any point is easier
*
STRUCTURE : (block of memory is called node) consists:-
 1.data:data ( char , int) anything
 2.next:point towards next node 
head:stores address of first node 
next->NULL : it means it is last node 
*/

#include <iostream>
using namespace std;

class Node{
   public :
   int data;// data inside node
   Node* next;// address of next node

   Node(int data){
    this->data=data;  /* OR Node(int val){data=val;next=NULL;}*/
    next=NULL;
   }
};

//insert at head
void insertAtHead(Node* &head, int val){
    Node* n=new Node(val);
    n->next=head;
    head=n;
}
// insert node at tail
void insertAtTail(Node* &head, int val){
    Node* temp=head;
    Node* n=new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
// insert value at n position
void insertAtN(Node* &head, int n, int val){
    Node* temp=head;
    Node* addN=new Node(val);
    while(n-1){
        temp=temp->next;
    }
    addN->next=temp->next->next;
    temp->next=addN;
     cout<<addN;
}
// Search a node in linkedlist given value to be searched
bool searchKey(Node* head, int key){
    Node* temp=head;
    while(temp!=NULL){
    if(temp->data==key){
        return true;
    }
    temp=temp->next;
    }
    return false;
} 
// delete from head
void deleteHead(Node* &head ){
    Node* temp=head;
    head=head->next;

    delete temp;
}
// delete nth node from the ll  
void deleteKeyMine(Node* &head, int n){// n here is the node that will be deleted
if (head==NULL){// if the ll is empty then just return
    return;
}
     Node* temp=head;
     int count=1;
     while(temp->next!=NULL){
        if(count==n-1){
            temp->next=temp->next->next;
        }
        temp=temp->next;
        count++;

     }
}

// delete a node from ll given data of the node
void deleteKey(Node* &head, int key){ // key here is the value that will be deleted
    Node* temp=head;
    if(head==NULL){// if the ll is empty then just return
        return ;
    }
    if(head->data==key){
       head=NULL;
       return;
    }
    while(temp->next->data!=key){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

// display linkedlist 
void display(Node *head){
    Node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<".."<<endl;
}

int main(){
   /*Node n1(1);
    Node* head=&n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    n1.next=&n2;    
    n2.next=&n3;    
    n3.next=&n4;    
    display(head);*/
    

    Node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    display(head);
    insertAtHead(head,0);
    display(head);
    cout<<searchKey(head,4)<<endl;;
   // deleteKeyMine(head,1);
   // display(head);
    deleteKey(head,5);
    display(head);
    //insertAtN(head,3,7);
    //display(head);
    deleteHead(head);
    display(head);
    return 0;
}
