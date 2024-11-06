#include<iostream>
using namespace std;

const int min_value = 1e5+5;
const int range = min_value;
int arr[range];
int tree[4*range];

void build(int node, int b, int e)
{
    if(b==e) {
        tree[node]=arr[b];
        return;
    }

    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[node] = (tree[left]<tree[right]) ? tree[left] : tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b) return min_value;
    if(b>=i && e<=j) {
        return tree[node];
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    if(p1<p2) return p1;
    else return p2;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>arr[i];

    build(1, 1, n);
    
    for(int i=0; i<m; i++) {
        int l,r;
        cin>>l>>r;
        l++, r++;
        cout<<query(1, 1, n, l, r)<<"\n";
    }
    return 0;
}