#include <stdio.h>
#include <math.h>
using namespace std;

#define mx 100001
int arr[mx];
int tree[mx*3];

void init(int node, int b, int e)
{
    if(b==e) {
        tree[node] = arr[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    // tree[node] = tree[left] + tree[right];
    if(tree[left] < tree[right]) tree[node] = tree[left];
    else tree[node] = tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return mx;
    if(b>=i && e<=j)
        return tree[node];
    int left = node*2;
    int right = node*2 +1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    // return p1+p2;
    if(p1 < p2) return p1;
    else return p2;
}

int main() {
    int testCase;
    scanf("%d", &testCase);
    for(int caseNo=1; caseNo<=testCase; caseNo++) {
        int n,q;
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) {
            scanf("%d", &arr[i]); 
        }
        
        init(1,1,n);

        printf("Case %d:\n", caseNo);
        for(int i=0; i<q; i++) {
            int j,k;
            scanf("%d %d", &j, &k); 
            printf("%d\n", query(1, 1, n, j, k));
        }
    }
    return 0;
}
