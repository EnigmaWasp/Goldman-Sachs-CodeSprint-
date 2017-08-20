#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

const int MaxN = 30;
const int MaxK = 10;
int a[MaxN+5];

LL dp[MaxN + 5][MaxK + 5];

void solve()
{
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    memset(dp, 0, sizeof(dp));
    for (int day = 2; day <= n; day++)
    {
        for (int K = 1; K <= k; K++)
        {
            dp[day][K] = dp[day-1][K];
            for (int d = 1; d < day; d++)
            {
                LL t = dp[d-1][K-1] + a[day] - a[d];
                if (t > dp[day][K])
                    dp[day][K] = t;
            }
        }
    }

    cout << dp[n][k] << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve();

	return 0;
}
