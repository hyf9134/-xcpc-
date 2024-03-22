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
    	std::string s;
    	bool operator < (const node x) {
    		if(len(x.s) == len(this->s))
    			return this->s > x.s;
    		return len(this->s) > len(x.s);
    	}
    };
    std::vector<node> a(n);
    for(int i = 0; i < n; i++) {
    	std::string s;
    	std::cin >> s;
    	a[i] = {i + 1, s};
    }
    std::sort(all(a));
    std::cout << a[0].id << endl << a[0].s;
    return 0;
}