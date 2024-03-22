#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define len(x) (x).size()
#define endl '\n'
#define lowbit(x) ((x) & - (x))

//using namespace std;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

std::string pow(int n) {
	std::string s;
	int flag = 0;
	while(n != 0) {
		int t = std::log2(n);
		if(flag)
			s += '+';
		if(t == 0) {
			s += "2(0)";
		} else if(t == 1) {
			s += "2";
		} else {
			s += "2(";
			s += pow(t);
			s += ")";
		}
		flag = 1;
		n -= std::pow(2, t);
	}
	return s;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //std::cout.precision(10);
    int n;
    std::cin >> n;
    std::cout << pow(n);
    return 0;
}