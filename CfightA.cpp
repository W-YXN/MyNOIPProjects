#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

namespace segmenttree
{
const int MAXN = 50010;
int a[MAXN], ans[MAXN << 2], lazy[MAXN << 2];

void PushUp(int root)
{
    ans[root] = ans[root << 1] + ans[root << 1 | 1];
}

void Build(int l, int r, int root)
{
    if (l == r)
    {
        ans[root] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, root << 1);
    Build(mid + 1, r, root << 1 | 1);
    PushUp(root);
}

void PushDown(int root, int ln, int rn)
{
    if (lazy[root])
    {
        lazy[root << 1] += lazy[root];
        lazy[root << 1 | 1] += lazy[root];
        ans[root << 1] += lazy[root] * ln;
        ans[root << 1 | 1] += lazy[root] * rn;
        lazy[root] = 0;
    }
}

void Add(int L, int C, int l, int r, int root)
{
    if (l == r)
    {
        ans[root] += C;
        return;
    }
    int mid = (l + r) >> 1;
    PushDown(root, mid - l + 1, r - mid);
    if (L <= mid)
        Add(L, C, l, mid, root << 1);
    else
        Add(L, C, mid + 1, r, root << 1 | 1);
    PushUp(root);
}

void Update(int L, int R, int C, int l, int r, int root)
{
    if (L <= l && r <= R)
    {
        ans[root] += C * (r - l + 1);
        lazy[root] += C;
        return;
    }
    int mid = (l + r) >> 1;
    PushDown(root, mid - l + 1, r - mid);
    if (L <= mid)
        Update(L, R, C, l, mid, root << 1);
    if (R > mid)
        Update(L, R, C, mid + 1, r, root << 1 | 1);
    PushUp(root);
}

long long Query(int L, int R, int l, int r, int root)
{
    if (L <= l && r <= R)
        return ans[root];
    int mid = (l + r) >> 1;
    PushDown(root, mid - l + 1, r - mid);
    long long ANS = 0;
    if (L <= mid)
        ANS += Query(L, R, l, mid, root << 1);
    if (R > mid)
        ANS += Query(L, R, mid + 1, r, root << 1 | 1);
    return ANS;
}

} // namespace segmenttree

using namespace segmenttree;

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int kkk = 0; kkk < t; kkk++)
    {
        std::memset(a, 0, sizeof(a));
        std::memset(ans, 0, sizeof(ans));
        std::memset(lazy, 0, sizeof(lazy));
        int n;
        for (int i = 1; i < n + 1; i++)
        {
            cin >> a[i];
        }
        Build(1, n, 1);
        cout << "Case " << kkk << ":" << endl;
        std::string s;
        cin >> s;
        while (s != "End")
        {
            if (s == "Query")
            {
                int l, r;
                cin >> l >> r;
                cout << Query(l, r, 1, n, 1) << endl;
            }
            else if (s == "Add")
            {
                int pci, num;
                cin >> pci >> num;
                Add(pci, num, 1, n, 1);
            }
            else if (s == "Sub")
            {
                int pci, num;
                cin >> pci >> num;
                Add(pci, (0 - num), 1, n, 1);
            }
            cin >> s;
        }
    }
    return 0;
}