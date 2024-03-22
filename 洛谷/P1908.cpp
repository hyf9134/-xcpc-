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
    std::vector<int> a(n), o(n), rank(n);
    for(int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }
    std::iota(all(o), 0);
    std::sort(all(o), [&](int i, int j){
    	if(a[i] == a[j])
    		return i < j;
    	return a[i] < a[j];
    });
    for(int i = 0; i < n; i++) {
    	rank[o[i]] = i + 1;
    }
    std::vector<int> tree(n + 10);
    auto add = [&](int idx, int key) {
    	while(idx <= n) {
    		tree[idx] += key;
    		idx += lowbit(idx);
    	}
    };
     auto query = [&](int idx) {
     	int res = 0;
     	while(idx) {
     		res += tree[idx];
     		idx -= lowbit(idx);
     	}
     	return res;
     };
     int cnt = 0;
     for(int i = n - 1; i >= 0; i--) {
     	cnt += query(rank[i] - 1);
     	add(rank[i], 1);
     }
     std::cout << cnt << endl;

    return 0;
}