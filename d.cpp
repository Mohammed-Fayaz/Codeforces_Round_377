#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    auto possible = [&](int index){
        vector<int> latest(m, -1);
        for (int i = 0; i <= index; i++){
            if (d[i] == 0) continue;
            latest[d[i] - 1] = i;
        }

        set<pair<int, int>> s;
        for (int i = 0; i < m; i++){
            if (latest[i] == -1) return false;
            s.insert(make_pair(latest[i], i));
        }

        int days = 0;
        int prev = 0;
        auto it = s.begin();
        while (it != s.end()){
            pair<int, int> next = *it;
            days += next.first - prev;
            prev = next.first + 1;
            if (days >= a[next.second]){
                days -= a[next.second];
            } else {
                return false;
            }
            it++;
        }
        return true;
    };

    int res = -2;
    int lo = 0, hi = n - 1;
    while (lo <= hi){
        int mid = (lo + hi) /  2;
        if (possible(mid)){
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << res + 1 << endl;
    return 0;
}
