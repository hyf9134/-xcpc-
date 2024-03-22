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
    int n, r, c;
    std::cin >> n >> r >> c;
    struct node {
    	int id;
    	int power;
    	int res;
    	bool operator < (const node x) {
    		if(this->res == x.res)
    			return this->id < x.id;
    		return this->res > x.res;
    	}
    };
    std::vector<node> a(n * 2 + 1);
    auto mange = [&](auto self, int l, int r) -> void {
        if(l >= r)
            return;
        int mid = l + r >> 1;
        self(self, l, mid);
        self(self, mid + 1, r);
        int i = l, j = mid + 1;
        std::vector<node> t;
        while(i <= mid && j <= r) {
            if((a[i].res == a[j].res && a[i].id < a[j].id) || a[i].res > a[j].res)
                t.push_back(a[i++]);
            else
                t.push_back(a[j++]);
        }
        while(i <= mid)
            t.push_back(a[i++]);
        while(j <= r)
            t.push_back(a[j++]);
        int k = l;
        for(int i = 0; i < len(t); i++) {
            a[k++] = t[i];
        }
    };
    for(int i = 1; i <= n * 2; i++) {
    	int res;
    	std::cin >> res;
    	a[i].res = res;
        a[i].id = i;
    }
    for(int i = 1; i <= n * 2; i++) {
    	int power;
    	std::cin >> power;
    	a[i].power = power;
    }
    while(r--) {
    	// std::sort(a.begin() + 1, a.end());
        mange(mange, 1, n * 2);
    	for(int i = 2; i <= n * 2; i += 2) {
    		if(a[i].power > a[i - 1].power)
    			a[i].res++;
    		else
    			a[i - 1].res++;
    	}
    }
    std::sort(a.begin() + 1, a.end());
    std::cout << a[c].id << endl;

    return 0;
}