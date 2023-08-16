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
// reverse the ll

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
   Node n1(1);
    Node* head=&n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);
    n1.next=&n2;    
    n2.next=&n3;    
    n3.next=&n4;    
    display(head);
    }