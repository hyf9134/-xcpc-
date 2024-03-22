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
    	int id, y,s,w,z;
    	bool operator < (const node x) {
    		if(x.y == this -> y && x.z == this -> z)
    			return this -> id < x.id;
    		if(x.z == this -> z)
    			return this -> y > x.y;
    		return this -> z > x.z;
    	}
    };
    int n;
    std::cin >> n;
    std::vector<node> a(n);
    for(int i = 0; i < n; i++) {
    	int y, s, w;
    	std::cin >> y >> s >> w;
    	a[i] = {i + 1, y, s, w, y + s + w};
    }
    std::sort(all(a));
    for(int i = 0; i < 5; i++) {
    	std::cout << a[i].id << ' ' << a[i].z << endl;
    }


    return 0;
}