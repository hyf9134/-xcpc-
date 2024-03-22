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
    	int id;
    	std::string name;
    	int res;
    	bool operator < (const node x) {
    		if(this->res == x.res)
    			return this->id < x.id;
    		return this->res > x.res;
    	}
    };
    int sum = 0;
    std::vector<node> v(n);
    auto check = [&](int a, int b, char x, char y, int cnt) -> int {
    	int res = 0;
    	if(a > 80 && cnt >= 1)
    		res += 8000;
    	if(a > 85 && b > 80)
    		res += 4000;
    	if(a > 90)
    		res += 2000;
    	if(a > 85 && y == 'Y')
    		res += 1000;
    	if(b > 80 && x == 'Y')
    		res += 850;
    	return res;
    };
    for(int i = 0; i < n; i++) {
    	std::string s;
    	int a, b;
    	char x, y;
    	int cnt;
    	std::cin >> s >> a >> b >> x >> y >> cnt;
    	int res = check(a, b, x, y, cnt);
    	sum += res;
    	v[i] = {i, s, res};
    }
    std::sort(all(v));
    std::cout << v[0].name << endl;
    std::cout << v[0].res << endl;
    std::cout << sum << endl;

    return 0;
}