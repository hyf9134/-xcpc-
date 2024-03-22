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
    std::map<int, int> hang, lie;
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, -1));
    hang[1] = 1;
    lie[1] = (n + 1) / 2;
    f[hang[1]][lie[1]] = 1;
    for(int i = 2; i <= n * n; i++) {
    	if(hang[i - 1] == 1 && lie[i - 1] != n) {
    		hang[i] = n;
    		lie[i] = lie[i - 1] + 1;
    		f[hang[i]][lie[i]] = i;
    	} else if(lie[i - 1] == n && hang[i - 1] != 1) {
    		lie[i] = 1;
    		hang[i] = hang[i - 1] - 1;
    		f[hang[i]][lie[i]] = i;
    	} else if(hang[i - 1] == 1 && lie[i - 1] == n) {
    		hang[i] = 2;
    		lie[i] = n;
    		f[hang[i]][lie[i]] = i;
    	} else {
    		if(f[hang[i - 1] - 1][lie[i - 1] + 1] != -1) {
    			hang[i] = hang[i - 1] + 1;
    			lie[i] = lie[i - 1];
    		} else {
    			hang[i] = hang[i - 1] - 1;
    			lie[i] = lie[i - 1] + 1;
    		}
    		f[hang[i]][lie[i]] = i;
    	}
    }
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= n; j++) {
    		std::cout << f[i][j] << ' ';
    	}
    	std::cout << endl;
    }
    return 0;
}