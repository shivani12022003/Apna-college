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
//append k nodes 
node* kappend(node* &head, int k){
    node* newhead;
    node* newtail;
    node* tail=head;
    int len=length(head);
    k=k%len;
    int count=0;
    while(tail->next!=NULL){
        if(count==len-k){
            newtail=tail;
        }
        if(count==len-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;

    return newhead;
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
    node* head=NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0; i<6; i++){
         insertAttail(head,arr[i]);
    }
    display(head);
    node* newhead=kappend(head, 3);
    display(newhead);
    return 0;
}

/*************** another approach ******************
 node* appendK(node* head, int k)
{
    int length = 1;
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }  
    int count = length-k-1;
    node* newtail = head;
    while(count)
    {
        newtail = newtail->next;
        count--;
    }
    node* newhead = newtail->next;
    temp->next = head;
    newtail->next = NULL;
    return newhead;
}
********************************************************/


/******************* another approach **********************
 Node* appendKNodes(Node* h, int k){
    // if k = 0 means we did not have to append any node in the starting
    if(k == 0){
        return h;
    }

    // Two Pointers starting with head 
    Node* ptr1 = h;
    Node* ptr2 = h;

    // Counter variable 
    int count = 0;

    // Traverse ptr1 to k times because there is one pointer exists which is k steps after the second one 
    while(count < k){
        ptr1 = ptr1->next;
        count++;
    }

    // if we reach to Null then it means value of k is equal to length of linked list so we return same list
    if(ptr1 == NULL){
        return h;
    }

    // until the first pointer reaches to NULL increment second pointer 
    while(ptr1->next != NULL){
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    // Now we got our two pointers as discussed in video new tail as ptr2 and tail as ptr1
    // then adding or deleting link 
    Node* temp = h;
    h = ptr2->next;
    ptr2->next = NULL;
    ptr1->next = temp;

    // returning our new head 
    return h;
}
******************************************************************************************/