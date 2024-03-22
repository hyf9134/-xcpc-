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
    	int x, y, z;
    	bool operator < (const node x) {
    		return this->z < x.z;
    	}
    };
    int n;
    std::cin >> n;
    std::vector<node> a(n);
    for(int i = 0; i < n; i++) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	a[i] = {x, y, z};
    }
    std::sort(all(a));
    double sum = 0;
    for(int i = 1; i < n; i++) {
    	sum += std::sqrt((a[i].x - a[i - 1].x) * (a[i].x - a[i - 1].x) + (a[i].y - a[i - 1].y) * (a[i].y - a[i - 1].y) + (a[i].z - a[i - 1].z) * (a[i].z - a[i - 1].z));
    }
    printf("%.3lf\n", sum);
    return 0;
}