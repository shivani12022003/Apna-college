#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
/* insert at tal ll*/
void insertAtTail(node* &head, int val){
    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    return;
}
/* reverse a ll*/
node* reverse_ll(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    // iterative
    while(nextptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=nextptr;
        currptr=nextptr;
    }
    return prevptr;
}
/* reverse a ll*/
node* reverserec_ll(node* &head){
    node* newhead=reverserec_ll(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

/* display function*/
void display(node* head){ // took w/o reference bcz no modification needed
    node* temp= head; // to store the val of head 
    while(temp!=NULL){
        cout<<temp->data<<" "; // print each node till temp=NULL
        temp=temp->next;
    }
    cout<<endl;
}     
int main(){
    node* head=NULL; 
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    
    return 0;
}