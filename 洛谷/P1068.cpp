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
    struct node {
    	int id, sc;
    	bool operator < (const node x) {
    		if(x.sc == this->sc) {
    			return id < x.id;
    		}
    		return this->sc > x.sc;
    	}
    };
    int n, m;
    std::cin >> n >> m;
    std::vector<node> a(n + 1), b;
    for(int i = 1; i <= n; i++) {
    	int x, y;
    	std::cin >> x >> y;
    	a[i] = {x, y};
    }
    std::sort(a.begin() + 1, a.end());
    int k = m * 1.5;
    for(int i = 1; i <= n; i++) {
    	if(a[i].sc >= a[k].sc)
    		b.push_back({a[i].id, a[i].sc});
    }
    std::cout << a[k].sc << ' ' << len(b) << endl;
    for(int i = 0; i < len(b); i++)
    	std::cout << b[i].id << ' ' << b[i].sc << endl;


    return 0;
}