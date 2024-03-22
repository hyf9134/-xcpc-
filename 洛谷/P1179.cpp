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
    int l, r;
    std::cin >> l >> r;
    auto get = [&](std::vector<int> pos, int st, int ed) -> int {
        int ans = 0;
        for(int i = st; i <= ed; i++)
            ans = ans * 10 + pos[i];
        return ans;
    };
    auto count = [&](int n, int x) -> int {
        std::vector<int> pos;
        pos.push_back(0);
        if(n < 0)
            return 0;
        int ans = 0;
        ans = (x == 0 ? 1 : 0);
        
        while(n != 0) {
            pos.push_back(n % 10);
            n /= 10;
        }
        std::reverse(pos.begin() + 1, pos.end());
        for(int i = 1; i < len(pos); i++) {
            if(i != 1) {
                ans += (get(pos, 1, i - 1) - !x) * pow(10, len(pos) - 1 - i);
            }
            if(pos[i] == x) {
                ans += get(pos, i + 1, len(pos) - 1) + 1;
            } else if(x < pos[i]){
                ans += pow(10, len(pos) - 1 - i);
            }
        }
        return ans;
    };
    std::cout << count(r, 2) - count(l - 1, 2);
    return 0;
}