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
    int t = n;
    for(int i = 1; i <= n + 1; i++) {
    	int x;
    	std::cin >> x;
    	if(!x) {
    		t--;
    		continue;
    	}
        if(i == n + 1) {
            if(x > 0 && i != 1) {
                std::cout << '+' << x;
            } else {
                std::cout << x;
            }
            break;   
        }
        if(t == 1) {
            if(x == 1 && i == 1)
                std::cout << "x";
            else if(x == 1 && i != 1)
                std::cout << "+" << "x";
            else if(x == -1)
                std::cout << "-x";
            else if(x > 0 && i != 1)
                std::cout << "+" << x << "x";
            else
                std::cout << x << "x";
            t--;
            continue;  
        }
    	if(x == 1 && i == 1)
    		std::cout << "x^" << t;
        else if(x == 1 && i != 1)
            std::cout << "+" << "x^" << t;
        else if(x == -1)
            std::cout << "-x^" << t;
    	else if(x > 0 && i != 1)
    		std::cout << "+" << x << "x^" << t;
        else
            std::cout << x << "x^" << t;
    	t--;
    }

    return 0;
}