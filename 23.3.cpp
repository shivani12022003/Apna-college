// reverse a stack
/*
ex1: Hey, how are you doing?
=> doing? you are how Hey, 
ex2: 5 4 3 2 1
=>  1 2 3 4 5 
*/
// without using extra stack (with recursion)
#include<iostream>
#include<stack>
using namespace std; 

void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return ;
    }
    int top_ele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(top_ele);

}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}
int main(){
    stack<int> st; 
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

}