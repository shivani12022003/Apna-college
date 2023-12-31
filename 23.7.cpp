#include <iostream>
#include<stack>
using namespace std;
// infix to postfix
int prec(char a){
    if(a=='^'){
        return 3;
    }else if(a=='*'|| a=='/'){
        return 2;
    }else if(a=='+' || a=='-'){
        return 1;
    }else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack <char> st;
    string result;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z' ) || (s[i]>='A' && s[i]<='Z' )){
            result+=s[i];
         }else if(s[i]=='('){
            st.push(s[i]);
         }else if(s[i]==')'){
            while(!st.empty() || st.top()!= '('){
                result+=st.top();
                st.pop();
            }if(!st.empty()){
                st.pop();
            }
         }
         else{
           while(!st.empty() && prec(st.top()) > prec(s[i]) ){
            result+=st.top();
            st.pop();
           }
           st.push(s[i]);
        }

    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
int main(){
   //string =(a-b/c)*(a/k-l)
   
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;;
    return 0;
  
}