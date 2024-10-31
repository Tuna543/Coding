#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

const int mx = 1e5 + 5;

struct node{
    int num;
    int isDivisible;
};

int arr[mx];
node tree[mx * 4];

void init(int root, int b, int e)
{
    if (b == e)
    {
        tree[root].num = arr[b];
        if(tree[root].num%3==0) tree[root].isDivisible++;
        return;
    }
    int left = root << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    if ((tree[left].num % 3)==0)
        tree[left].isDivisible++;
    if ((tree[right].num % 3)==0)
        tree[right].isDivisible++;
    
    tree[root].isDivisible = tree[left].isDivisible + tree[right].isDivisible;
}

void update(int root, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return;
    else if (b >= i && e <= j)
    {
        tree[root].num++;
        return;
    }
    int left = root << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
     update(left, b, mid, i, j);
     update(right, mid + 1, e, i, j);

    tree[root].num = tree[left].num + tree[right].num;
}

int query(int root, int b, int e, int i, int j)
{
    int sum = 0;
    if (i > e || j < b)
        return 0;
    else if (b >= i && e <= j)
        return tree[root].isDivisible;
    int left = root << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return p1+p2;
}

int main()
{
    int n, q;
    cin >> n >> q;

    int height = ceil(log2(n));
    int lastIndex = pow(2, height + 1);
    printf("height: %d\t last index: %d\n", height, lastIndex);

    printf("Printing Segment tree\n");
    for (int i = 0; i < lastIndex; i++)
    {
        printf("%d %d\t", tree[i].num, tree[i].isDivisible);
    }
    printf("\n");

    for (int i = 0; i < q; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
            update(1, 0, n - 1, a, b);
        else
            cout << query(1, 0, n - 1, a, b) << endl;
    }
}