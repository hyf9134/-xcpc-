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
    struct node {
        double x, y;
    };
    int n;
    std::cin >> n;
    std::vector<node> a(n + 1);
    for(int i = 1; i <= n; i++) {
        double x, y;
        std::cin >> x >> y;
        a[i] = {x, y};
    }
    std::sort(a.begin() + 1, a.end(), [&](node A, node B){
        if(A.x == B.x)
            return A.y < B.y;
        return A.x < B.x;
    });
    auto dis = [&](node A, node B) {
        return std::hypot(A.x - B.x, A.y - B.y);
    };
    auto merge = [&](auto self, int l, int r) -> double {
        if(l == r)
            return 0x3f3f3f3f;
        if(l + 1 == r) {
            return dis(a[l], a[r]);
        }
        int mid = l + r >> 1;
        double d = std::min(self(self, l, mid), self(self, mid + 1, r));
        std::vector<node> b;
        for(int i = l; i <= r; i++) {
            if(std::abs(a[i].x - a[mid].x) < d)
                b.push_back(a[i]);
        }
        std::sort(all(b), [&](node A, node B) {
            if(A.y == B.y)
                return A.x < B.x;
            return A.y < B.y;
        });
        for(int i = 0; i < len(b); i++) {
            for(int j = i + 1; j < len(b); j++) {
                if(std::abs(b[i].y - b[j].y) >= d)
                    break;
                d = std::min(d, dis(b[i], b[j]));
            }
        }
        return d;
    };
    printf("%.4lf\n", merge(merge, 1, n));

    return 0;
}