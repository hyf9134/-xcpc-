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
    std::cout.precision(10);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
    	std::cin >> a[i];
    for(int i = n - 1; i >= 1; i--)
    	a[i] = std::abs(a[i] - a[i - 1]);
    std::sort(a.begin() + 1, a.end());
    for(int i = 1; i < n; i++) {
    	if(a[i] != i) {
    		std::cout << "Not jolly" << endl;
    		return 0;
    	}
    }
    std::cout << "Jolly" << endl;
    return 0;
}