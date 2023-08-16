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

//creating ll
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

//merge two ll (iterative way)
node* merge(node* &head1, node* &head2){
    node* p1=head1;
    node* p2=head2;
    //node to use temp (dummyNode)
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if (p1->data<p2->data)
        {
           p3->next=p1;
           p1=p1->next;
        }else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;
}
//merge two ll (recursive)
node* mergeRecursive(node* &head1, node* &head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }

    return result;
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
    int arr1[]={1,4,5,7};
    for(int i=0; i<4; i++){
        insertAttail(head1,arr1[i]);
    }
    node* head2=NULL;
    int arr2[]={2,3,6};
    for(int i=0; i<3; i++){
        insertAttail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    node* newhead=merge(head1,head2);
    display(newhead);
    return 0;
}
