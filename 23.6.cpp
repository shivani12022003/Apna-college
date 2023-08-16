#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
/* postfix expression evaluation 
   it is same as the prefix expression evaluation
   just the values are traversed from left to right. 
*/
int postfix_evaluation(string s){
    stack<int> st;
    int len=s.length();
    for(int i=0; i<len; i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
    }else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch(s[i]){
                case '+':
                  st.push(op1+op2);
                  break;
                case '-':
                  st.push(op1-op2);
                  break;
                case '*':
                  st.push(op1*op2);
                  break;
                case '/':
                  st.push(op1/op2);
                  break;
                case '^':
                  st.push(pow(op1,op2));
                  break;
            }
        } 
    }
    return st.top(); 
}
int main(){//ans is wrong
    cout<<postfix_evaluation("46+2/5*7+");
    return 0;
}