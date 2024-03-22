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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	std::cin >> a[i];
    int st = 1, ed = 1e18;
    int max = -1, min = 1e18;
    while(st < ed) {
    	int mid = st + ed >> 1;
    	int cnt = 0;
    	int last = 0;
    	for(int i = 1; i <= n; i++) {
    		last += a[i];
    		if(last >= mid) {
    			cnt++;
    			last = 0;
    		} else if(last <= 0) {
    			last = 0;
    		}
    	}
    	if(cnt <= k) {
    		ed = mid;
    	} else {
    		st = mid + 1;
    	}
    	if(cnt == k) {
    		min = std::min(min, mid);
    	}
    }
    //std::cout << min << endl;
    st = 1, ed = 1e18;
    while(st < ed) {
        int mid = st + ed + 1 >> 1;
        int cnt = 0;
        int last = 0;
        for(int i = 1; i <= n; i++) {
            last += a[i];
            if(last >= mid) {
                cnt++;
                last = 0;
            } else if(last <= 0) {
                last = 0;
            }
        }
        if(cnt >= k) {
            st = mid;
        } else {
            ed = mid - 1;
        }
        if(cnt == k) {
            max = std::max(max, mid);
        }
    }
    //std::cout << max << endl;
    if(max != -1 && min != 1e18)
        std::cout << min << ' ' << max;
    else
        std::cout << -1 << endl;

    return 0;
}