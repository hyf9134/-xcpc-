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
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	std::cin >> a[i];
    std::sort(all(a));
    int st = 0, ed = n;
    int sum = 0;
    int idx = 1;
    while(st < ed) {
    	if(idx & 1) {
    		idx++;
    		sum += (a[st] - a[ed]) * (a[st] - a[ed]);
    		st++;
    	} else {
    		idx++;
    		sum += (a[st] - a[ed]) * (a[st] - a[ed]);
    		ed--;
    	}
    }
    std::cout << sum << endl;
    return 0;
}