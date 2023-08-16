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

//insertion at starting of linked list
void insertAthead(node* &head, int val){
    node* n= new node(val);
    n->next=head;
    head=n;
}

//insertion in last of linked list
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

// search element in ll
bool search(node* &head, int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }// will give value as 0 or 1
        temp=temp->next;
    }
    return false;
}

// to display ll
void display (node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

// to delete ll
void deletion(node* &head, int val){
    if (head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAthead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

// delete at head (first node)
void deleteAthead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
}
// reverse the ll(itrative way)
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

// reverse the ll(recursive way)
node* recursiveReverse(node* &head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=recursiveReverse(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

// reverse k nodes of the ll
node* reversek(node* &head, int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next=reversek(nextptr, k);
    }

    return prevptr;
}
// make cycle at a given pt, in ll
void makecycle(node* &head , int pos){
    node* temp=head;
    node* starnode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->startnode;  
}

/*detection & removal of cycle in ll
 Flyod's algo (hare & tortoise algo)
 two nodes have same next
 hare & tortoise(fast & slow) will move 2 and 1 steps resp & if they collide means there is a cycle in ll*/
bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fats->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(fast==slow){
            return true;
        }
    }
    return false;
}

/*remove cycle
 now that slow & fast ptr are at same pt. shift anyone(slow or fast ) on the head 
 & move them by one step at a time and the pt they will collide is the pt where cycle starts*/
void removecycle(node* &head){
    node* slow= head;
    node* fast= head;
     do{
        slow=slow->next;
        fast=fast->next->next;
     }while(slow!=fast);// till we get the common pt.

    fast=head; //moved one ptr at head
    while(slow->next!=fats->next){
        // now move both ptr by 1 step
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;// to remove cycle
}
// length of ll
int length(node* head){
    int len=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return len;
}
//append k nodes 
node* append(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int len=length(head);
    k=k%l;
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

    return newhead;
}
int main(){
    node* head=NULL;
    insertAttail(head, 1);
    insertAttail(head, 2);
    insertAttail(head, 3);
    insertAthead(head,4);
    insertAthead(head,5);
    insertAthead(head,6);
    display(head);
    cout<< search(head,3);
    cout<< search(head,9);
    deletion(head, 3);
    display(head);
    deleteAthead(head);
    display(head);
    node* newhead=reverse(head);
    display(newhead);
    node* newhead=recursiveReverse(head);
    display(newhead);
    
    int k=2;
    node* reversek(head,k);
    display (newhead);
    makecycle(head, 3);
    cout<<detectcycle(head)<<endl;
    removecycle(head);
    cout<<detectcycle<<endl;
    display(head);
    return 0;
}