#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> m(3);
    for (int i = 0; i < 3; i++) cin >> m[i];

    vector<vector<int>> p =
            {{1, 1, 1}, {2, 1, 1}, {2, 2, 1}, {2, 2, 2},
            {0, 1, 1}, {1, 1, 1}, {1, 2, 1}, {1, 2, 2},
            {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {1, 1, 2},
            {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {1, 1, 1}
    };

    long long res = (long long)9e18;
    for (int i = 0; i < p.size(); i++){
         vector<long long> temp = m;
         for (int j = 0; j < 3; j++) temp[j] -= p[i][j];

         sort(temp.begin(), temp.end());

         res = min(res, (2 * temp[2] - (temp[0] + temp[1])));
    }

    cout << res << endl;
    return 0;
}
