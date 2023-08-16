// reverse a stack
/*
ex1: Hey, how are you doing?
=> doing? you are how Hey, 
ex2: 5 4 3 2 1
=>  1 2 3 4 5 
*/
// her extra is being used
#include <iostream>
#include <stack>
using namespace std;

void reverseSen(string s){
    stack<string> st;
    int len=s.length();
    for(int i=0; i<len; i++){
        string word="";
        while(s[i]!=' ' && i<len){
            word+=s[i];
            i++;
        }
        st.push(word);

    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    string s;
    cout<<"Type the string:"<<endl;
    getline(cin,s);
    reverseSen(s);
}