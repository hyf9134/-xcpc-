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
    std::cin >> m >> n;
    std::vector<std::pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
    	int x, y;
    	std::cin >> x >> y;
    	a[i] = {x, y};
    }
    int sum = 0;
    std::sort(all(a));
    for(int i = 0; i < n; i++) {
    	if(m == 0)
    		break;
    	sum += std::min(m, a[i].second) * a[i].first;
    	m -= std::min(m, a[i].second);
    }
    std::cout << sum << endl;


    return 0;
}