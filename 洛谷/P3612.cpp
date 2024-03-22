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
    std::string s;
    int n;
    std::cin >> s >> n;
    int len = len(s);
    while(len < n)
        len <<= 1;
    while(len > len(s)) {
        len >>= 1;
        if(len >= n)
            continue;
        if(len + 1 == n)
            n = len;
        else
            n = n - len - 1;
    }
    std::cout << s[n - 1];

    return 0;
}