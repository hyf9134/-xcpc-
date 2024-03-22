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
    int a, b, p;
    std::cin >> a >> b >> p;
    auto fast_pow = [&](int key, int cnt, int modp) {
    	int res = 1;
    	while(cnt) {
    		if(cnt & 1)
    			res = res * key % modp;
    		cnt >>= 1;
    		key = key * key % modp;
    	}
    	return res;
    };
    printf("%ld^%ld mod %ld=%ld\n", a, b, p, fast_pow(a, b, p));

    return 0;
}