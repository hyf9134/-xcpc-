// 打*的 据情况修改
#include<bits/stdc++.h>
using i64 = long long;


const i64 MAXN = 1e5+5;
i64 A[MAXN];

struct tnode {
    int l, r;   //当前节点所管辖范围
    i64 lazy;  // *当前节点的懒标记
    i64 sum;   // *当前节点所管辖区间的sum
};

tnode operator + (const tnode &x, const tnode &y) { // *重载+ 用于合并区间
    tnode temp;
    
    temp.l = x.l;
    temp.r = y.r;
    temp.lazy = 0;

    // temp.sum = x.sum + y.sum; // 求和
    
    return temp;
}

struct Segment_Tree {
    tnode t[4*MAXN];

    void init_lazy(int root) { //*初始化懒标记
        t[root].lazy = 0;
        return;
    }

    void union_lazy(int root, int son) { // *用当前节点的lazy修改son的lazy
        i64 temp;
        temp = t[root].lazy + t[son].lazy;
        t[son].lazy = temp;
        return;
    }

    void sum_lazy(int root) { // *根据懒标记更新sum
        i64 len = t[root].r - t[root].l + 1;
        t[root].sum += len * t[root].lazy;
        return;
    }
    
    void push_down(int root) { // 向下更新懒标记
        if (t[root].lazy != 0) { // *当root存在懒标记
            sum_lazy(root);//根据懒标记 把当前节点的sum值进行修改

            if (t[root].l != t[root].r) { // 当前节点不是叶子结点时 把标记向下传递给左右孩子
                int ls = root << 1;
                int rs = root << 1 | 1;

                union_lazy(root, ls);
                union_lazy(root, rs);
            }

            init_lazy(root);//清空当前节点的懒标记
        }
        return;
    }

    void push_up(int root, int ls, int rs) { // *从下向上传递区间值 更新root的sum

        push_down(ls);
        push_down(rs);

        tnode temp = t[ls] + t[rs];
        t[root].sum = temp.sum;

        return;
    }

    void build(int root, int l, int r) {
        //初始化当前节点
        t[root].l = l;
        t[root].r = r;
        init_lazy(root);

        if (l == r) { // *到达叶子结点，直接赋值
           t[root].sum = A[l];
           return;
        }
        
        int mid = l + (r - l >> 1);
        int ls = root << 1;
        int rs = root << 1 | 1;

        build(ls, l, mid);
        build(rs, mid + 1, r);

        push_up(root, ls, rs);
        return;
    }
    void update(int root, int l, int r, i64 date) { // *区间修改
        push_down(root);// 向下传 更新sum并清空标记

        if (l == t[root].l && r == t[root].r) { //区间符合
            t[root].lazy = date; // 打上标记
            return;
        }

        int mid = t[root].l + (t[root].r - t[root].l >> 1);
        int ls = root << 1;
        int rs = root << 1 | 1;
        
        if (r <= mid)
            update(ls, l, r, date);
        else if (l > mid) 
            update(rs, l, r, date);
        else {
            update(ls, l, mid, date); 
            update(rs, mid + 1, r, date);
        }

        push_up(root, ls, rs);
        return;
    }

    tnode sum_l_to_r(int root, int l, int r) {
        push_down(root);
        if (t[root].l == l && t[root].r == r) {
            return t[root];
        }
        int mid = t[root].l + (t[root].r - t[root].l >> 1);
        int ls = root << 1;
        int rs = root << 1 | 1;
        if (r <= mid)//递归左子树(t[root].l, mid)
            return sum_l_to_r(ls, l, r);
        else if (l > mid)//递归右子树(mid + 1, t[root].r)
            return sum_l_to_r(rs, l, r);
        else 
            return sum_l_to_r(ls, l, mid) + sum_l_to_r(rs, mid + 1, r);
    }


};
Segment_Tree stree;