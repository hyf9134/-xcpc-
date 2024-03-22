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
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    for(double i = -100.00; i <= 100.00; i += 0.001) {
        double t = a * i * i * i + b * i * i + c * i + d;
        double k = i + 0.001;
        double tt = a * k * k * k + b * k * k + c * k + d;
        if(t * tt < 0)
            printf("%.2lf ", i);
    }

    return 0;
}