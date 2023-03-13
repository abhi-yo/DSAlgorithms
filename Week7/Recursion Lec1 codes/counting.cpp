// //for normal counting formula->
// #include<iostream>
// using namespace std;
// void printCounting(int n){
//     //base case
//     if(n==0){
//         return;
//     }
//      //recursive relation
//     printCounting(n-1);
//     //processing
//     cout<<n<<endl;

    
// }
// int main(){
//     int n;
//     cin>>n;
//     printCounting(n);
// }


//for reverse counting
//for counting formula-> f(n) = print(n) + f(n-1)
#include<iostream>  
using namespace std;
void printCounting(int n){
    //base case
    if(n==0){
        return;
    }
   
    //processing
    cout<<n<<endl;

    //recursive relation
    printCounting(n-1);

    
}
int main(){
    int n;
    cin>>n;
    printCounting(n);
}