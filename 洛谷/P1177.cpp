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
    auto quick = [&](auto self, int l, int r) -> void{
    	if(l >= r)
    		return;
    	int i = l, j = r, op = a[l + r >> 1];
    	do {
            while(a[i] < op)
                i++;
            while(op < a[j])
                j--;
            if(i <= j) {
                std::swap(a[i], a[j]);
                i++;
                j--;
            }
        }while(i <= j);
    	self(self, l, j);
    	self(self, i, r);
    };
    quick(quick, 1, n);
    for(int i = 1; i <= n; i++)
    	std::cout << a[i] << " ";

    return 0;
}