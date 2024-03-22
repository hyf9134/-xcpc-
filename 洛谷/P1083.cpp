#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define len(x) (x).size()
#define endl '\n'
#define lowbit(x) ((x) & - (x))

//using namespace std;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //std::cout.precision(10);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 2);
    for(int i = 1; i <= n; i++) {
    	std::cin >> a[i];
    }
    for(int i = n; i >= 2; i--)
        a[i] -= a[i - 1];
    std::vector<std::pair<int, std::pair<int, int>>> v(m + 1);
    for(int i = 1; i <= m; i++) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	v[i] = {x, {y, z}};
    }
    int st = 1, ed = m;
    auto check = [&](int idx) {
        std::vector<int> t;
        t = a;
        for(int i = 1; i <= idx; i++) {
            int res = v[i].first;
            int l = v[i].second.first;
            int r = v[i].second.second;
            t[l] -= res;
            t[r + 1] += res;
        }
        int ok = 1;
        for(int i = 1; i <= n; i++) {
            t[i] += t[i - 1];
            if(t[i] < 0)
                ok = 0;
        }
        if(ok)
            return true;
        return false;
    };

    while(st < ed) {
    	int mid = st + ed + 1 >> 1;
    	if(check(mid)) {
    		st = mid;
        }
    	else
    		ed = mid - 1;
    }
    if(check(st) && st == m)
        std::cout << 0 << endl;
    else if(check(st))
        std::cout << -1 << endl << st + 1;
    else
        std::cout << -1 << endl << st;
    return 0;
}