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
    int l, n, m;
    std::cin >> l >> n >> m;
    std::vector<int> a(n + 2), f(n + 2), t;
    for(int i = 1; i <= n; i++)
    	std::cin >> a[i];
    a[n + 1] = l;
    int st = 0, ed = l;
    while(st < ed) {
        int mid = (st + ed + 1) >> 1;
        auto check = [&](int x) {
            int now = 0, cnt = 0;
            for(int i = 1; i <= n + 1; i++) {
                if(a[i] - a[now] < x) {
                    cnt++;
                } else
                    now = i;
            }
            if(cnt <= m)
                return true;
            else
                return false;
        };
        if(check(mid))
            st = mid;
        else
            ed = mid - 1;
    }
    std::cout << st << endl;
    return 0;
}