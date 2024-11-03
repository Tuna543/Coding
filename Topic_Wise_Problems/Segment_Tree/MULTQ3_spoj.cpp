#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

const int mx = 1e5 + 5;

struct node
{
    int m1, m2, m3, prop;
};

int arr[mx];
node tree[mx * 4];

void init(int root, int b, int e)
{
    if (b == e)
    {
        tree[root].m3 = 1;
        return;
    }
    int left = root << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);

    tree[root].m3 = tree[left].m3 + tree[right].m3;
}

void update(int root, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return;
    else if (b >= i && e <= j)
    {
        tree[root].prop += e-b+1;
        
        for(int k=0; k<tree[root].prop%3; k++) {
            swap(tree[root].m1, tree[root].m3);
            swap(tree[root].m2, tree[root].m3);
        }
        return;
    }
    int left = root << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);

    tree[root].m1 = tree[left].m1 + tree[right].m1;
    tree[root].m2 = tree[left].m2 + tree[right].m2;
    tree[root].m3 = tree[left].m3 + tree[right].m3;
}


int query(int root, int b, int e, int i, int j, int carry = 0)
{
    int sum = 0;
    if (i > e || j < b)
        return 0;
    else if (b >= i && e <= j) {
        return tree[root].m3;
    }
    int left = root << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    int p1 = query(left, b, mid, i, j, carry+tree[root].prop);
    int p2 = query(right, mid + 1, e, i, j, carry+tree[root].prop);

    return p1 + p2;
}

int main()
{
    int n, q;
    cin >> n >> q;

    init(1, 1, n);
    int height = ceil(log2(n));
    int lastIndex = pow(2, height + 1);
    printf("height: %d\t last index: %d\n", height, lastIndex);

    printf("Printing Segment tree\n");
    for (int i = 1; i <= lastIndex; i++)
    {
        printf("%d %d %d %d \t", tree[i].prop, tree[i].m1, tree[i].m2, tree[i].m3);
    }
    printf("\n");

    for (int j = 0; j < q; j++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        a++;
        b++;
        if (op == 0)
            update(1, 1, n, a, b);
        else
            cout << query(1, 1, n, a, b, 1) << endl;

        printf("Printing Segment tree\n");
        for (int i = 1; i <= lastIndex; i++)
        {
            printf("%d %d %d %d \t", tree[i].prop, tree[i].m1, tree[i].m2, tree[i].m3);
        }
        printf("\n\n");
    }
}