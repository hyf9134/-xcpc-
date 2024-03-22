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
    while(n--) {
    	int q;
    	std::string s;
    	std::cin >> q >> s;
    	int cnt = s[len(s) - 2] - '0';
        if(std::count(all(s), 'n') == 0)
            cnt = 0;
    	int f = 0, e = 0, res = 0;
    	std::map<char, int> name;
    	std::vector<char> nm;
    	int ERR = 0, last = 0, flag = 0;
    	while(q--) {
    		char c;
            std::cin >> c;

    		if(c == 'E') {
    			e++;
    			if(e > f)
    				ERR = 1;
    			else {
    				name[nm.back()]--;
    				nm.pop_back();
    			}
    		} else {
                char x;
                std::string y, z;
                std::cin >> x >> y >> z;
    			f++;
    			if(name[x] != 0) {
    				ERR = 1;
    			} else {
    				name[x]++;
    				nm.push_back(x);
    			}
                int cnty = std::count(all(y), 'n');
                int cntz = std::count(all(z), 'n');
    			if(f - e > last) {
                    if(cnty ==0 && cntz != 0 && !flag) {
                        last++;
                        res++;
                    } else if(cnty == 0 && cntz != 0) {
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                }
    		}
    	}
        //std::cout << cnt << ' ' << res << endl;
    	if(e != f || ERR) {
    		std::cout << "ERR" << endl;
    	} else if(cnt != res) {
    		std::cout << "No" << endl;
    	} else {
    		std::cout << "Yes" << endl;
    	}
    }

    return 0;
}