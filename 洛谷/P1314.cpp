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
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<int> w(n + 1), v(n + 1);
    for(int i = 1; i <= n; i++) {
    	std::cin >> w[i] >> v[i];
    }
    std::vector<std::pair<int, int>> a(m);
    for(int i = 0; i < m; i++) {
    	int x, y;
    	std::cin >> x >> y;
    	a[i] = {x, y};
    }

    // for(int i = 1; i <= n; i++)
    //     std::cout << w[i] << ' ' << v[i] << endl;



    int st = 0, ed = (*std::max_element(all(v)));
    int min = 1e18;
    while(st < ed) {
    	int mid = st + ed + 1 >> 1;
    	
    	int sum = 0;
        std::vector<int> pw(n + 1), pv(n + 1);
        for(int i = 1; i <= n; i++) {
            pw[i] = pw[i - 1];
            pv[i] = pv[i - 1];
            if(w[i] >= mid) {
                pw[i]++;
                pv[i] += v[i];
            }
        }
    	for(int i = 0; i < m; i++) {
    		int l = a[i].first, r = a[i].second;
    		sum += (pw[r] - pw[l - 1]) * (pv[r] - pv[l - 1]);
    	}
    	if(sum >= s) {
            st = mid;
        } else {
            ed = mid - 1;
        }
        min = std::min(std::abs(sum - s), min);
    }
    std::cout << min << endl;

    return 0;
}