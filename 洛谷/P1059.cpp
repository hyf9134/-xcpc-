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
    std::vector<int> a(n + 1), v;
    for(int i = 1; i <= n; i++) {
    	std::cin >> a[i];
    }
    auto quick = [&](auto self, int l, int r) -> void {
    	if(l >= r)
    		return;
    	int i = l, j = r, op = a[l];
    	while(i < j) {
    		while(i < j && op < a[j])
    			j--;
    		std::swap(a[i], a[j]);
    		while(i < j && op >= a[i])
    			i++;
    		std::swap(a[i], a[j]);
    	}
    	self(self, l, i - 1);
    	self(self, i + 1, r);
    };
    quick(quick, 1, n);
    for(int i = 1; i <= n; i++) {
    	v.push_back(a[i]);
    	int j = i;
    	while(a[j] == a[i] && j <= n) {
    		j++;
    	}
    	i = j - 1;
    }
    std::cout << len(v) << endl;
    for(int i = 0; i < len(v); i++)
    	std::cout << v[i] << ' ';
    return 0;
}