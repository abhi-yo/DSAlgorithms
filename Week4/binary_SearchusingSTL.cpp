#include<stdio.h>
using namespace std;
int arr1[]={1200,200,23000,1230,1543};
int arr2[]={12,14,16,18,20};
int temp,result=0;
int main(){
    for(temp=0;temp<5;temp++){
        result+=arr1[temp];

    }
    for(temp=0;temp<4;temp++){
        result=result+arr2[temp];

    }
    return result;
    return 0;
}