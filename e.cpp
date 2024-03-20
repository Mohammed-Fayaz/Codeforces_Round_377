#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    set<pair<int, int>>p, s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p.insert(make_pair(x, i));
    }
    for (int j = 0; j < m; j++){
        int x; cin >> x;
        s.insert(make_pair(x, j));
    }

    int c = 0, u = 0;
    vector<int> a(m, 0), b(n, -1);
    int d = 1;
    for (int pw = 0; pw <= 30; pw++){
        auto it = s.begin();
        while (it != s.end()){
            auto next = it; next++;
            auto match = p.lower_bound(make_pair((int)ceill((long double)(it -> first) / d), -1));
            if (match != p.end() && match -> first == (int)ceill((long double)(it -> first) / d)){
                c++, u += pw;
                a[it -> second] += pw;
                b[match -> second] = it -> second;
                p.erase(match);
                s.erase(it);
            }
            it = next;
        }
        d *= 2;
    }

    cout << c << " " << u << endl;

    for (int i = 0; i < m; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << b[i] + 1 << " ";
    cout << endl;
    return 0;
}
