#include<iostream>
using namespace std; 

int arr[5];

int main()
{
    int cnt =0;
    for(int i=1; i<=4; i++) {
        int num;
        cin>>num;
        arr[num]++;
    }
    for(int i=1; i<=4; i++) {
        // if(arr[i]%2==0) {
            cnt += arr[i]/2;
        // }
    }
    cout<<cnt<<"\n";
}