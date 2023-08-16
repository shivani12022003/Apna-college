# include<iostream>
using namespace std;

/*recurrence relation if fibonacci series
f(n)=f(n-1)+f(n-2)*/

/*master threorem: gives the time comlexity if recurrence relation
{master theorem formula}
T(n)=aT(n/b)+f(n) {n size problem}
=>Θ(press Alt & type 233)
=>n²(press alt & type 253)
3 cases:
1.if f(n)=Θ(n) where c<Log₆a then T(n)=Θ(nᴸᵒᵍ₆ᵃ)
2.if f(n)=Θ(n) where c=Log₆a then T(n)=Θ(nᶜLogn)
3.if f(n)=Θ(n) where c>Log₆a then T(n)=Θ(f(n))
*/

/* FOR MERGE SORT:
divide the problem in two halves : T(n) is the problem then
-> T(n)=T(n/2)+T(n/2)      ->T(n)=2T(n/2)+Θ(n){i.e time to join the problem}
{above is how we solve the merge sort problem}
SO, a=2, b=2, c=1   ->c=Log₆a
hence, time complex.=Θ(nLog2n)
*/

/* FOR ANOTHER PROBLEM:
->T(n)=3T(n/2)+n²
SO, a=3, b=2, c=2    ->c>Log₆a
hence, time complex.=Θ(n²)
*/
/*RECURRENCE TREE METHOD:
T(n)=T(n-1)+n
T(n-1)=T(n-2)+(n-1)
T(n-1)=T(n-3)+(n-2)
.
.
T(1)=1 ; now add all the rhs and lhs terms resp.

->T(n)=n+(n-1)+(n-2)(n-3)+........1
->T(n)=(n* (n+1) )/2
->T(n)=Θ(n²)
*/
int main(){
    
}