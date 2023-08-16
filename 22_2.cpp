#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next=NULL;
    node(int val){
        data=val;
        next=NULL;
    }
};

/* insert at tail function*/
void insertAtTail(node* &head,int val){
    node* n=new node(val);// node has val as data and address as NULL
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;// to traverse the ll
    while(temp->next!=0){
        temp=temp->next;// till u found NULL(0) at temp's next
    }
    temp->next=n;
}
/* delete the head node*/
void deletehead(node* &head){
    node* temp=head;

}
/* tabnine delete a node in ll*/
void deleteNodetabnine(node* &head,int val){
    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==val){
            temp->next->next=NULL;
            break;
        }
        temp=temp->next;
    }
}

/* mine delete a node in ll*/
void deleteNodeMine(node* &head, int val){
    node* temp=head;
    if(head==NULL){
        return;
    }
    while(temp->next!=NULL){
        if(temp->data!=val){
             temp=temp->next;
        }temp->next=temp->next->next;
       
    }
}

/* apni kaksha delete a node in ll*/
void deleteNodeak(node* &head ,int val){
    node* temp=head;
    while(temp->data!=val){
        temp=temp->next;
    }
    node* todel=temp->next;
    temp->next=temp->next->next;
    delete todel;
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
    deleteNodeak(head,0);
    cout<<"by ak:";
    display(head);
    deleteNodeMine(head,6);
    cout<<"by mine:";
    display(head);
    deleteNodetabnine(head,2);
    cout<<"by tabnine:";
    display(head);
    return 0;
}