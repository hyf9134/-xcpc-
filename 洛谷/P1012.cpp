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
    std::vector<std::string> a(n);
    for(int i = 0; i < n; i++)
    	std::cin >> a[i];
    std::sort(all(a), [&](std::string x, std::string y) {
        return x + y > y + x;
    });
    for(int i = 0; i < n; i++)
    	std::cout << a[i];
    return 0;
}