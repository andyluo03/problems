//wecu's template -- works with c++20

#include <bits/stdc++.h>
#define forn(n) for(int i = 0; i < n; i++)
#define endl '\n'
#define int long long

typedef long long ll;
using namespace std;

//void pc(auto& c){for_each(c.begin(), c.end(), [](auto u){cout << u << " ";});}

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

void solution(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    forn(n){cin >> a[i];}
    SegmentTree s(a);
    forn(q){
        int t, j, k;
        cin >> t >> j >> k;
        if(t == 1){
            s.update(j-1, k);
        }else{
            cout << s.query(j-1, k-1) << endl;
        }
    }
}

#undef int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    //cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
