#include <iostream>
using namespace std;

int main()
{
    int n,q;
    cin>>n;
    int arr[3][2];
    for(int i=1; i<=n; i++) {
        for(int j=0; j<2; j++)
            cin>>arr[i][j];
    }

    cin>>q;
    for(int i=0; i<q; i++) {
        int t,d;
        cin>>t>>d;
        if((d%arr[t][0]) == arr[t][1]) d=d;
        else if((d%arr[t][0]) > arr[t][1]) {
            d += arr[t][0] - (d%arr[t][0]) + arr[t][1];
        } else {
            d += arr[t][1] - (d%arr[t][0]);
        }
        cout<<d<<"\n";
    }

}