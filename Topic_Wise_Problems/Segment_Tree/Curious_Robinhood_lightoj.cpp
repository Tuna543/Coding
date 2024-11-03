#include <stdio.h>
#include <math.h>
using namespace std;

// #define mx 100005
const int mx = 1e5 + 5;
int arr[mx];
int tree[mx * 4];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int left = node << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int newValue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[node] = newValue;
        arr[i] = newValue;
        // printf("updated value %d\n", tree[node]);
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, newValue);
    update(right, mid + 1, e, i, newValue);
    tree[node] = tree[left] + tree[right];
}

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for (int caseNo = 1; caseNo <= testCase; caseNo++)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        init(1, 1, n);

        // int height = ceil(log2(n));
        // int lastIndex = pow(2, height + 1);
        // printf("height: %d\t last index: %d\n", height, lastIndex);

        // printf("Printing Segment tree\n");
        // for (int i = 1; i <= lastIndex; i++)
        // {
        //     printf("%d\t", tree[i]);
        // }
        // printf("\n");

        printf("Case %d:\n", caseNo);

        for (int i = 0; i < q; i++)
        {
            int op;
            scanf("%d", &op);
            if (op == 1)
            {
                int j;
                scanf("%d", &j);
                j++;
                printf("%d\n", arr[j]);
                update(1, 1, n, j, 0);
            }
            else if (op == 2)
            {
                int j, value;
                scanf("%d %d", &j, &value);
                j++;
                update(1, 1, n, j, value + arr[j]);
            }
            else if (op == 3)
            {
                int j, k;
                scanf("%d %d", &j, &k);
                j++;
                k++;
                printf("%d\n", query(1, 1, n, j, k));
            }
        }
    }
    return 0;
}
