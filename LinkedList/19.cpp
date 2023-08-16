#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for the sort function
using namespace std;

bool myCompare(pair<int,int> a, pair<int,int> b){// used in pair topic
    return a.first < b.first; // denoting the array element
}
int main(){
    /*******************{ VECTORS }*************************/
    // To declare vector : vector<datatype> name
    vector<int> v;
    v.push_back(1);// to add elements in the vector
    v.push_back(2);
    v.push_back(3);
    // to print u can use for loop 
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    // or use iterator
    vector<int>::iterator it;// noe we got a iterator 
    for(it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }cout<<endl;
    // use auto keyword
    for(auto element:v){
        cout<<element<<" ";
    }cout<<endl;

    // to delete/pop an element 
    v.pop_back();
    for(auto element:v){
        cout<<element<<" ";
    }cout<<endl;

    vector<int> v2 (4,24);
    for(auto element:v2){
        cout<<element<<" ";
    }cout<<endl;

    swap(v,v2);
    cout<<"print v(1,2): after swapping ";
    for(auto element:v){
        cout<<element<<" ";
    }cout<<endl;
    cout<<"print v2(24,24,24,24): after swapping ";
    for(auto element:v2){
        cout<<element<<" ";
    }cout<<endl;

    vector<int> v3;
    v3.push_back(36);
    v3.push_back(22);
    v3.push_back(67);
    v3.push_back(5);
    cout<<"vector 3 after sorting function: ";
    for(auto element:v3){
        cout<<element<<" ";
    }cout<<endl;

    // to sort the vector :
    sort(v3.begin(),v3.end());

    cout<<"vector 3 after sorting function: ";
     for(auto element:v3){
        cout<<element<<" ";
    }cout<<endl;

/*******************{ PAIR }*************************/
cout<<endl<<endl<<" NEW TOPICS :PAIR "<<endl;

   pair<int,int> p1;// two different datatypes 
   pair<int,char> p2;

   p2.first=1;
   p2.second='a';
   cout<<"printing first element of pair p2: "<<p2.first<<" "<<"second element of p2: "<<p2.second<<endl;
   /*Q. Reduce the array (change the values from 0 to size-1)
   Input:  { 10, 16, 7, 14, 5, 3, 12, 9 }
   Output: { 4,  7,  2, 6,  1, 0, 5,  3 }
   WHAT? write smallest element as 0 and after that second smallest as 1 and so on
   HOW? sort the array along with their index so the index wont be lost and then acc to that place 0 at the index of
    first element of sorted array(i.e smallest element) and continue it*/
    int arr[]= { 10, 16, 7, 14, 5, 3, 12, 9 };
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<pair<int,int> > vect;
    for(int i=0; i<n; i++){
       /* pair<int,int> p;
        p.first=arr[i];
        p.second=i;*/
        // OR USE MAKEPAIR FUNCTION:
        vect.push_back(make_pair(arr[i],i));
    }
    sort(vect.begin(),vect.end(),myCompare);// will sort acc to the array element in ascending order
    for(int i=0; i<vect.size(); i++){
        arr[vect[i].second]=i;
    }cout<<endl<<"Reduced array: "<<endl;
    for(int i=0; i<vect.size(); i++){
        cout<<arr[i]<<" ";
    }cout<<endl;



}