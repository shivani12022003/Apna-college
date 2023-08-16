/*precedence of operators
1. (),{},[]
2. ^ (R->L)
3. *,/ (L->R)
4. +,- (L->R)
*/
/*prefix: {<operator> <operand> <operand>}
eg1: 4*3+7 => ((4*3)+7) => +*437
eg2: 5-6/3 => (5-(6/3)) => -5/63
postfix: {<operand> <operand> <operator>}
eg1: 4*2+3 => ((4*2)+3) => 42*3+
eg2: 5-6/3 => (5-(6/3)) => 563/-
*/
#include <iostream>
#include <stack>
using namespace std;
 
int main(){

}