#include<stdio.h>
#include<iostream>
using namespace std;

const int mx=1e5+5;

struct node
{
    int toggle;
    int on;
} tree[mx*4];

void init(int node, int b, int e)
{
    if(b==e){
        tree[node].toggle = 0;
        tree[node].on = 0;
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1; 
    init(left, b, mid);
    init(right, mid+1, e);
}

void propagate(int node, int b, int e)
{
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    
    tree[node].toggle = 0;
    tree[left].toggle ^= 1;
    tree[right].toggle ^= 1;

    tree[left].on = mid - b + 1 - tree[left].on; //e-b+1-on
    tree[right].on = e - (mid+1) + 1 - tree[right].on; //e-b+1-on
}

void update(int node, int b, int e, int i, int j)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
        tree[node].toggle ^= 1;
        tree[node].on = e-b+1 - tree[node].on;
        return;
    }

    if(tree[node].toggle) {
        propagate(node, b, e);
    }

    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1; 
    /*if(j<=mid)*/ update(left, b, mid, i, j);
    update(right, mid+1, e, i, j);

    tree[node].on = tree[left].on + tree[right].on;
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) {
        return tree[node].on;
    }

    if(tree[node].toggle) propagate(node, b, e);

    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1; 
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}

int main()
{ 
    int n,m,si,ei; 
    bool op;
    cin>>n>>m;
    init(1, 1, n);

    for(int i=0; i<m; i++) {
        cin>>op>>si>>ei;
        if(op) {
            cout<<query(1, 1, n, si, ei)<<"\n";
            // cout<<"ON lights on node 1: "<<tree[1].on<<" toggle value: "<<tree[1].toggle<<"\n";
            // cout<<"ON lights on node 2: "<<tree[2].on<<" toggle value: "<<tree[2].toggle<<"\n";
            // cout<<"ON lights on node 3: "<<tree[3].on<<" toggle value: "<<tree[3].toggle<<"\n";
            // cout<<"ON lights on node 4: "<<tree[4].on<<" toggle value: "<<tree[4].toggle<<"\n";
            // cout<<"ON lights on node 5: "<<tree[5].on<<" toggle value: "<<tree[5].toggle<<"\n";
            // cout<<"ON lights on node 6: "<<tree[6].on<<" toggle value: "<<tree[6].toggle<<"\n";
            // cout<<"ON lights on node 7: "<<tree[7].on<<" toggle value: "<<tree[7].toggle<<"\n";
        } else {
            update(1, 1, n, si, ei);
        }
    }
}