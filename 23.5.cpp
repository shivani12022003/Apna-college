#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
/*operation on prefix expression 
eg: -+7*45+20
Create a stack then push the two values then when 
the first operator comes store those values in 
variables o1 & o2 and perform oper. then put that
result back into the stack & again push the values
till next operator comes then again store the values
in o1 & o2 and perform oper. then store that result
in stack keep repeating this till values are done and
the final num in stack will be the result.
*/
int prefix_evaluation(string s){
    stack<int> st;
    int len=s.length();
    for (int i = len-1; i >=0; i--)
    {
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
int main(){

    cout<<prefix_evaluation("-+7*45+20");
    return 0;
}