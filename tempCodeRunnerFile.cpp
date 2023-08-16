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

/* insert at head function*/
void insertAtHead(node* &head,int val){
    node* n=new node(val);// node has val as data and address as NULL
    n->next=head;// n,s next is pointed to head
    head=n; // head is given the value of n
}
/* boolean search for any node*/
bool search(node* head,int val){
    node* temp=head;
    int pos=0;
    while(temp!=NULL){
        if(temp->data==val){
            cout<<"found at :"<<pos<<endl;
            return 1;
        }
        temp=temp->next;
        pos++;
    }
    return 0;
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
        display(head);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
        display(head);
    insertAtHead(head,6);
        display(head);
    //deleteAtHead(head);
        //display(head);
    //deleteAtTail(head);
        //display(head);
        search(head,6);
}

