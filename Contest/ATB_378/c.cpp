#include<iostream>
#include<map>
using namespace std;

map<int, int> mp;

int main()
{
    int n;
    cin>>n;
    int a[6];
    int b[6];
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        if(mp[a[i]]==0) {
            b[i] = -1;
        } else {
            b[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }

    for(int i=1; i<=n; i++) {
        cout<<b[i]<<" ";
    }
    cout<<"\n";
}