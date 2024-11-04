#include<iostream>
using namespace std;

const int range=1e5+5;

int arr[range];
int tree[range+1];

void update(int idx, int value, int maxValue)
{
    while(idx <= maxValue) {
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

void build(int n)
{
    for(int i=1; i<=n; i++) {
        update(i, arr[i-1], n+1);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx>0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>arr[i];
    build(n);
    for(int i=0; i<=n; i++) cout<<tree[i]<<" ";
    cout<<"\n";
    for(int i=0; i<q; i++) {
        char ch;
        cin>>ch;
        if(ch=='u') {
            int value, index;
            cin>>index>>value;
            update(index, value, n);
        } else if(ch=='q') {
            int index;
            cin>>index;
            cout<<"The sum upto "<<index<<"th index is: "<<query(index)<<"\n";
        }
    }
}
/*
testcase
11 5
3 2 -1 6 5 4 -3 3 7 2 3
q 11
q 3
u 3 1
q 11
q 3
*/