#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

const int MaxN = 100 * 1000;
const int MaxQ = 100 * 1000;

int price[MaxN+10];
int times[MaxN+10];
int priceMax[MaxN+10];
pii pd[MaxN+10];
int dateMin[MaxN+10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> times[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
        pd[i] = {price[i], times[i]};
    }

    // second query
    priceMax[n+1] = -1;
    for (int i = n; i >= 0; i--)
        priceMax[i] = max(priceMax[i+1], price[i]);

    // first query
    sort(pd+1, pd+n+1);
    dateMin[n+1] = -1;
    dateMin[n] = pd[n].second;
    for (int i = n-1; i >= 0; i--)
        dateMin[i] = min(dateMin[i+1], pd[i].second);


    for (int Q = 0; Q < q; Q++)
    {
        int tp, a;
        cin >> tp >> a;
        if (tp == 2)
        {
            int day = lower_bound(times+1, times+n+1, a) - times;
            cout << priceMax[day] << endl;
        }
        else
        {
            pii pr = {a, 0};
            int ind = lower_bound(pd+1, pd+n+1, pr) - pd;
            cout << dateMin[ind] << endl;
        }
    }
	return 0;
}
