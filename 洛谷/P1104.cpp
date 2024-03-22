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
    	int id;
    	std::string name;
    	int n, y, r;
    	bool operator < (const node x) {
    		if(this->n == x.n && this->y == x.y && this->r == x.r)
    			return this->id > x.id;
    		if(this->n != x.n)
    			return this->n < x.n;
    		if(this->y != x.y)
    			return this->y < x.y;
    		return this->r < x.r;
    	}
    };
    int n;
    std::cin >> n;
    std::vector<node> a(n);
    for(int i = 0; i < n; i++) {
    	std::string s;
    	int x, y, r;
    	std::cin >> s >> x >> y >> r;
    	a[i] = {i, s, x, y, r};
    }
    std::sort(all(a));
    for(int i = 0; i < n; i++)
    	std::cout << a[i].name << endl;
    return 0;
}