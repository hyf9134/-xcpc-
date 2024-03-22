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
    std::vector<int> f(n + 1), a, b;
    std::map<std::pair<int, int>, int > hash;
    for(int i = 1; i < n; i++) {
    	for(int j = i + 1; j <= n; j++) {
    		int x;
    		std::cin >> x;
    		hash[{i, j}] = x;
    		hash[{j, i}] = x;
    	}
    }
    int maxt = 0;
    for(int i = 1; i <= n; i++) {
        int max = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j)
                continue;
            max = std::max(max, hash[{i, j}]);
        }
        for(int j = 1; j <= n; j++) {
            if(i == j)
                continue;
            if(hash[{i, j}] > maxt && hash[{i, j}] < max) {
                maxt = hash[{i, j}];
            }
        }
    }
    std::cout << 1 << endl << maxt;

    return 0;
}