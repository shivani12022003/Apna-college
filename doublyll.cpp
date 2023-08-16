#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node (int val){
        data=val;
        prev=NULL;
        next=NULL;

    }
};
// insert at head
void insertAthead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
   if(head!=NULL) { 
    head->prev=n;
    }

    head=n;
}
// insert at tail
void insertAttail(node* &head, int val){
    if (head==NULL){
        insertAthead(head, val);
        return ;
    }
    node* n= new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

// delete at head in doubly ll
void deleteAthead(node* &head){
    node* todel=head;
    head=head->next;
    head->prev=NULL;

    delete todel;
}
// deletion in doubly ll
void deletion(node* &head, int pos){
    node* temp=head;
    int count=1;
    if (pos==0){
        deleteAthead(head);
        return ;
    }

    while(temp!=NULL && count<pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    delete temp;
}
// length of ll
int length(node* head){
    int len=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
//append k nodes 
node* append(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int len=length(head);
    k=k%len;
    int count=0;
    while(tail->next!=NULL){
        if(count==len-k){
            newTail=tail;
        }
        if(count==len-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;

    return newHead;
}
// display of doubly ll
void display (node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){ 
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    cout<<"doubly ll:"<<endl;
    display(head);
    cout<<"after deletion:"<<endl;
    deletion(head,4);
    display(head);
    return 0;
}