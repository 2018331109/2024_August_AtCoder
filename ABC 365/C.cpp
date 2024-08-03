#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg cout << -1 << endl
#define pb push_back
#define ss second
#define ff first

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e18;
int md = 998244353;

bool canSubsidize(const vector<int>& A, int x, int M)
{
    int total = 0;
    for (int a : A)
    {
        total += min(a, x);
        if (total > M) return false; // If total exceeds M, return false
    }
    return total <= M;
}

void solve()
{
    int N;
    int M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int left = 0, right = *max_element(A.begin(), A.end()), ans = 0;

    // Binary search for the maximum x
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canSubsidize(A, mid, M))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // Check if the subsidy can be made infinitely large
    int total = 0;
    for (int a : A)
    {
        total += a;
    }
    if (total <= M)
    {
        cout << "infinite" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test=1;
    //cin >> test;
    for (int tc = 0; tc < test; tc++)
    {
        solve();
    }

    return 0;
}


