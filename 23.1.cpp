//STACK using array:LIFO
#include<iostream>
using namespace std ;
#define n 100

class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
// to insert an element
    void push(int x){
        if(top==n-1){
            cout<<"Stack overflow";
            return ;
        }
        top++;
        arr[top]=x;
    }
// to delete an element 
    void pop(){
        if(top==-1){
            cout<<"No element to pop";
            return ;
        }
        top--;
    }
// to return topmost element    
    int Top(){
        if(top==-1){
            cout<<"No element in stack";
            return -1;
        }
        return arr[top];
    }
// to chcek if stack is empty or not
    bool empty(){
        return top==-1;
    }
}
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;


}
