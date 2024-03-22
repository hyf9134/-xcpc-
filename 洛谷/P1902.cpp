#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define len(x) (x).size()
#define endl '\n'
#define lowbit(x) ((x) & - (x))

//using namespace std;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int mp[1010][1010];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //std::cout.precision(10);
    int n, m;
    std::cin >> n >> m;
    int max = 0;
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= m; j++) {
    		std::cin >> mp[i][j];
    		max = std::max(max, mp[i][j]);
    	}
    }
    int st = 0, ed = max;
    while(st < ed) {
    	int mid = st + ed >> 1;
    	auto check = [&](int res) {
    		std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
    		int x[] = {0, 1, 0, -1};
    		int y[] = {1, 0, -1, 0};
    		std::queue<std::pair<int, int>> q;
    		q.push({1, 1});
    		f[1][1] = 1;
    		while(len(q)) {
    			auto t = q.front();
    			q.pop();
    			int tx = t.first;
    			int ty = t.second;
    			for(int i = 0; i < 4; i++) {
    				int xt = tx + x[i];
    				int yt = ty + y[i];
    				if(xt < 1 || yt < 1 || xt > n || yt > m)
    					continue;
    				if(f[xt][yt])
    					continue;
    				if(mp[xt][yt] > res)
    					continue;
    				f[xt][yt] = 1;
    				q.push({xt, yt});
    			}
    		}
    		int ok = 1;
    		for(int i = 1; i <= m; i++) {
    			if(f[n][i] != 1)
    				ok = 0;
    		}
    		if(ok)
    			return true;
    		else
    			return false;
    	};
    	if(check(mid))
    		ed = mid;
    	else
    		st = mid + 1;
    }
    std::cout << st << endl;


    return 0;
}