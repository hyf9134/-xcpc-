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
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
    	std::cin >> a[i];
    int res = 0;
    for(int i = 1; i < n; i++) {
    	for(int j = 1; j < n - i + 1; j++) {
    		if(a[j - 1] > a[j]) {
    			res++;
    			std::swap(a[j - 1], a[j]);
    		}
    	}
    }
    std::cout << res << endl;

    return 0;
}