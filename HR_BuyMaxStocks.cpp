#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

const int MaxN = 100 * 1000;
pair<LL, LL> arr[MaxN+10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        LL t;
        cin >> t;
        arr[i] = {t, i+1};
    }
    LL k;
    cin >> k;

    sort(arr, arr+n);

    LL ans = 0;
    {
        int i = 0;
        while (k>0 && i < n)
        {
            LL q = k / arr[i].first;
            q = min(q, arr[i].second);
            k -= q * arr[i].first;
            ans += q;
            i++;
        }
    }

    cout << ans << endl;

	return 0;
}
