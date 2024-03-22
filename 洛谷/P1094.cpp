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
    int m, n;
    std::cin >> m >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
    	std::cin >> a[i];
    std::sort(all(a));
    int cnt = 0;
    int st = 0, ed = n - 1;
    while(st <= ed) {
    	if(a[st] + a[ed] <= m) {
    		st++;
    		ed--;
    		cnt++;
    	} else {
    		ed--;
    		cnt++;
    	}
    }
    std::cout << cnt << endl;


    return 0;
}