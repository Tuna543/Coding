#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

const int mx=1e5+5;
int arr[mx];
struct node{
    int num;
    int prop;
    int sum;
} tree[4*mx];

void build(int node, int b, int e)
{
    if(b==e) {
        tree[node].num = arr[b];
        return;
    }
    int left = node << 1;
    int right = left + 1; 
    int mid = (b+e) >> 1; 
    build(left, b, mid);
    build(right, mid+1, e);
}

void update(int node, int b, int e, int i, int j)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
        tree[node].sum += e-b+1;
        tree[node].prop++;
        return;
    }
    int left = node << 1;
    int right = left + 1; 
    int mid = (b+e) >> 1; 
    update(left, b, mid, i, j);
    update(right, mid+1, e, i, j);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1) * tree[node].prop;
}

int query(int node, int b, int e, int i, int carry=0)
{
    if(i>e || i<b) return 0;
    if(b>=i && e<=i) {
        // arr[b] = ((tree[node].sum + carry*(e-b+1))%2) ? arr[b] ^= 1: arr[b];
        return tree[node].sum + carry*(e-b+1);
    }
    int left = node << 1;
    int right = left + 1; 
    int mid = (b+e) >> 1; 
    int p1 = query(left, b, mid, i, carry+tree[node].prop);
    int p2 = query(right, mid+1, e, i, tree[node].prop+ carry);
    return p1+p2;
}

int main()
{
    int testCases;
    cin>>testCases;
    for(int caseNo=1; caseNo<=testCases; caseNo++) {
        string str;
        int n,q;
        cin>>str;
        n=str.length();
        for(int i=1; i<=n; i++) arr[i]=str[i-1]-'0';//cin>>arr[i];
        
        // for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
        // cout<<"\n";

        build(1, 1, n);
        
        // int height = ceil(log2(n));
        // int lastIndex = pow(2, height + 1);
        // printf("height: %d\t last index: %d\n", height, lastIndex);

        // printf("Printing Segment tree\n");
        // for (int i = 1; i <= lastIndex; i++)
        // {
        //     printf("%d %d %d \t", tree[i].num, tree[i].sum, tree[i].prop);
        // }
        // printf("\n");
        cin>>q;
        
        cout<<"Case "<<caseNo<<":\n";

        for(int k=0; k<q; k++) {
            char ch; 
            cin>>ch;
            if(ch=='I') {
                int i, j;
                cin>>i>>j;
                update(1, 1, n, i, j);
            } else if(ch=='Q') {
                int i, j;
                cin>>i;
                j = query(1, 1, n, i)%2;
                // cout<<"j: "<<j<<endl;
                if(j) {
                    j=arr[i]^1;
                    cout<<j<<endl;
                } else {
                    cout<<arr[i]<<endl;
                }
            }
        }

        memset(tree, 0, sizeof(tree));
    }
}