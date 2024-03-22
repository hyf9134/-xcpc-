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
    	int x, y;
    };
    std::vector<node> a(n + 1);
    for(int i = 1; i <= n; i++) {
    	int x;
    	std::cin >> x;
    	a[i].x = x;
    }
    for(int i = 1; i <= n; i++) {
    	int x;
    	std::cin >> x;
    	a[i].y = x;
    }
    std::sort(a.begin() + 1, a.end(), [&](node A, node B){
    	return A.y > B.y;
    });
    std::vector<int> pre(n + 1), h(n + 1), t(n + 2);
    for(int i = 1; i <= n; i++)
    	pre[i] = pre[i - 1] + a[i].y;
    for(int i = 1; i <= n; i++) {
    	h[i] = std::max(h[i - 1], a[i].x * 2);
    }
    for(int i = n; i >= 1; i--) {
    	t[i] = std::max(t[i + 1], a[i].x * 2 + a[i].y);
    }
    for(int i = 1; i <= n; i++) {
    	std::cout << std::max(pre[i] + h[i], pre[i - 1] + t[i]) << endl;
    }

    return 0;
}