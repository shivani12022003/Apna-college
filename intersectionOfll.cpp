#include<iostream>
using namespace std;

//class
class node{
    public:
    int data;
    node* next;    
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAttail(node* &head, int val){
    node* n= new node(val);
    if(head=NULL){// if the ll is empty
        head=n;
        return;
    }
    node* temp=head;
     while(temp->next!=NULL){
    // traverse the ll till the last element
        temp=temp->next;
     }
     // insertion of new element
     temp->next=n;
}
// length of ll
int length(node* &head){
    int len=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
// made a intersection of ll (later)
void intersect(node* head1, node* head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;

}
//intersection of two ll
int intersection(node* &head1, node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1=ptr2->next;
        if(ptr1==NULL){
            return -1;
        }
    }

    while(ptr1!=NULL &&ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

//display ll
void display (node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
     node* head1=NULL;
    insertAttail(head1, 1);
    insertAttail(head1, 2);
    insertAttail(head1, 3);
    insertAthead(head1,4);
    insertAthead(head1,5);
    insertAthead(head1,6);
    display(head1);
     insertAttail(head2, 9);
    insertAttail(head2, 8);
    insertAttail(head2, 7);
    insertAthead(head2,4);
    display(head2);
    cout<<intersection(head1,head2);
    return 0;
}