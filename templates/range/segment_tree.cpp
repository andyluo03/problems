#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    private:
    vector<int> tree;
    int n;
    const int BASE = 0;
    int left(int node){return 2*node;}
    int right(int node){return 2*node+1;}
    int mid(int left, int right){return left+(right-left)/2;}
    int join(int a, int b){return a+b;}
    void build(int node, int node_l, int node_r, vector<int>& arr){
        if(node_l == node_r){tree[node] = arr[node_l]; return;}
        int m = mid(node_l, node_r);
        build(left(node), node_l, m, arr);
        build(right(node), m+1, node_r, arr);
        tree[node] = join(tree[left(node)], tree[right(node)]);
    }

    void update(int node, int node_l, int node_r, int index, int val){
        if(node_l == node_r){tree[node] = val; return;}
        int m = mid(node_l, node_r);
        if(m >= index) {update(left(node), node_l, m, index, val);}
        else {update(right(node), m+1, node_r, index, val);}
        tree[node] = join(tree[left(node)], tree[right(node)]);
    }

    int query(int node, int node_l, int node_r, int l, int r){
        if(l > r) return BASE;
        if(node_l == l && node_r == r)  return tree[node];
        int m = mid(node_l, node_r);
        return join(query(left(node), node_l, m, l, min(m,r)),
                    query(right(node), m+1, node_r, max(l, m+1), r));
    }

    public:
    SegmentTree(vector<int>& arr) : tree{vector<int>(4*arr.size()+1)}, n{(int) arr.size()-1} {
        build(1, 0, arr.size()-1, arr);
    }

    void update(int index, int val){
        update(1, 0, n, index, val);
    }

    int query(int l, int r){
        return query(1, 0, n, l, r);
    }

    void print(){
        for(int i : tree)
            cout << i << " ";
        cout << "\n";
    }
};

int main(){
    vector<int> b = {1, 2, 3, 4, 5, 6, 7};
    SegmentTree test(b);
    test.print();
}