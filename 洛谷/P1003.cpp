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
    int n;
    std::cin >> n;
    struct node {
    	int a, b, c, d;
    };
    std::vector<node> v(n + 1);
    for(int i = 1; i <= n; i++) {
    	int a, b, c, d;
    	std::cin >> a >> b >> c >> d;
    	v[i] = {a, b, a + c - 1, b + d - 1};
    }
    int x, y;
    std::cin >> x >> y;
    int res = -1;
    for(int i = 1; i <= n; i++) {
    	if(v[i].a <= x && x <= v[i].c && v[i].b <= y && y <= v[i].d)
    		res = i;
    	
    }
    std::cout << res << endl;
    return 0;
}