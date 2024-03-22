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
    k++;
    for(int i = 1; i <= n; i++)
    	std::cin >> a[i];
    int ans = -1;
    auto quick = [&](auto self, int l, int r) -> void {
        int i = l, j = r, op = a[l];
        while(i < j) {
            while(i < j && a[j] > op)
                j--;
            std::swap(a[i], a[j]);
            while(i < j && a[i] <= op)
                i++;
            std::swap(a[i], a[j]);
        }
        if(k > i)
            self(self, i + 1, r);
        else if(k < i)
            self(self, l, i - 1);
        else {
            ans = a[i];
            return;
        }
    };
    quick(quick, 1, n);
    std::cout << ans;
    return 0;
}