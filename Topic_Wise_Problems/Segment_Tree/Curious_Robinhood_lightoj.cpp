#include <stdio.h>
#include <math.h>
using namespace std;

#define mx 100001
#define ll long long int
int arr[mx];
ll tree[mx*4];

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
    tree[node] = tree[left] + tree[right];
}

ll query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left = node*2;
    int right = node*2 +1;
    int mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}

void update(int node, int b, int e, int i, int newValue)
{
    if(i>e || i<b) return;
    if(b>=i && e<=i) {
        tree[node] = newValue;
        // printf("updated value %d\n", tree[node]);
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, newValue);
    update(right, mid+1, e, i, newValue);
    tree[node] = tree[left] + tree[right];
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

        int height = ceil(log2(n));
        int lastIndex = pow(2, height+1);
        printf("height: %d\t last index: %d\n", height, lastIndex);

        printf("Printing Segment tree\n");
        for(int i=1; i<=lastIndex; i++){
            printf("%d ", tree[i]);
        }
        printf("\n");

        
        printf("Case %d:\n", caseNo);

        for(int i=0; i<q; i++) {
            int op,j,k;
            scanf("%d", &op);
            if(op==1) {
                scanf("%d", &j);
                printf("%d\n", arr[j+1]);
                update(1, 1, n, j+1, 0);
            }
            else if(op==2) {
                scanf("%d %d", &j, &k);
                update(1, 1, n, j+1, k+arr[j+1]);
            }
            else if(op==3) {
                scanf("%d %d", &j, &k);
                printf("%lld\n", query(1, 1, n, j+1, k+1));
            }
        }
    }
    return 0;
}
