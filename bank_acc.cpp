#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <deque>

using namespace std;

int main()
{

 ios_base::sync_with_stdio(0);

    int q, n, k, x, d;
    cin >> q;
    string fee = "fee";
    string upf = "upfront";

    for (int i = 0; i < q; i++)
    {
        cin >> n >> k >> x >> d;
        int ans = 0;
        d *= 100;
        k *= 100;
        for (int j = 0; j < n; j++)
        {
            int p;
            cin >> p;
            ans += max(k, p * x);
        }
        if (ans > d) cout << upf << endl;
        else
            cout << fee << endl;
    }


 return 0;
}


