#include<iostream>
using namespace std;

const int range = 1e7+2;
#define ul unsigned long long

struct node
{
    // ul mx;
    ul prop;
} tree[range*4];

void build(int root, int b, int e)
{
    if(b==e) {
        // tree[root].mx = 0;
        tree[root].prop = 0;
        return;
    }

    int left = root << 1; 
    int right = left + 1;
    int mid = (b+e) >> 1; 
    build(left, b, mid);
    build(right, mid+1, e);
}

void propagate(int root, int b, int e)
{
    int left = root << 1; 
    int right = left + 1;
    int mid = (b+e) >> 1; 
    
    tree[left].prop += tree[root].prop;
    tree[right].prop += tree[root].prop;
    tree[root].prop = 0;
}
void update(int root, int b, int e, int i, int j, int value)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
        tree[root].prop += value;
        return;
    }

    if(tree[root].prop) propagate(root, b, e);

    int left = root << 1; 
    int right = left + 1;
    int mid = (b+e) >> 1; 
    
    update(left, b, mid, i, j, value);
    update(right, mid+1, e, i, j, value);
}

ul query(int root, int b, int e)
{
    if(b==e) {
        // tree[root].mx = tree[root].prop;
        return tree[root].prop;
    }

    if(tree[root].prop) propagate(root, b, e);

    int left = root << 1; 
    int right = left + 1;
    int mid = (b+e) >> 1; 
    
    ul p1 = query(left, b, mid);
    ul p2 = query(right, mid+1, e);
    if(p1>p2) return p1;
    else return p2;
}

int main()
{
    int n, m;
    cin>>n>>m;
    
    build(1, 1, n);

    for(int i=0; i<m; i++) {
        int a, b, k;
        cin>>a>>b>>k;
        update(1, 1, n, a, b, k);
    }

    cout<<query(1, 1, n);
}