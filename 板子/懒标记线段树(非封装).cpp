#include <bits/stdc++.h>

#define int long long


const int N = 2e5 + 10;
int tree[N << 2], tag[N << 2], a[N];

void push_up(int root, int ls, int rs) {
	tree[root] = tree[ls] + tree[rs];
}

void build(int root, int l, int r) {
	tag[root] = 0;
	if(l == r) {
		tree[root] = a[l];
		return;
	}
	int mid = l + r >> 1;
	int ls = root << 1;
	int rs = root << 1 | 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	push_up(root, ls, rs);
}

void tag_change(int root, int l, int r, int date) {
	tag[root] += date;
	tree[root] += date * (r - l + 1);
}

void push_down(int root, int l, int r, int ls, int rs) {
	if(tag[root]) {
		int mid = l + r >> 1;
		tag_change(ls, l, mid, tag[root]);
		tag_change(rs, mid + 1, r, tag[root]);
		tag[root] = 0;
	}
}

void update(int root, int l, int r, int L, int R, int date) {
	if(L <= l && r <= R) {
		tag_change(root, l, r, date);
		return;
	}
	int mid = l + r >> 1;
	int ls = root << 1;
	int rs = root << 1 | 1;
	push_down(root, l, r, ls, rs);
	if(L <= mid)
		update(ls, l, mid, L, R, date);
	if(R > mid)
		update(rs, mid + 1, r, L, R, date);
	push_up(root, ls, rs);
}

int query(int root, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return tree[root];
	}
	int mid = l + r >> 1;
	int ls = root << 1;
	int rs = root << 1 | 1;
	push_down(root, l, r, ls, rs);
	int res = 0;
	if(L <= mid) 
		res += query(ls, l, mid, L, R);
	if(R > mid)
		res += query(rs, mid + 1, r, L, R);
	return res;
}

