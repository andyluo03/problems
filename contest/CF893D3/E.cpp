//wecu's template -- works with c++17

#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define forn(n) for(int i = 0; i < n; i++)
#define endl '\n'

using namespace std;
using ll  = long long;
using pii  = pair<int, int>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;

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
    int join(int a, int b){return a^b;}
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

void pv(vi a) {
    #ifdef DEBUG 
    forn(a.size()){cout << a[i] << ", ";} cout << endl; 
    #endif
}

//interval container ?
//2 is ALL ENCOMPASSING!
//AMORTIZED POWER!!!!   
void solution(){
    int n; cin >> n;
    vector<int> a(n);
    forn(n){cin >> a[i];}
    string s; cin >> s;

    int q; cin >> q;

    ll one_ans = 0;
    ll zero_ans = 0;

    vector<int> ot_(n);
    vector<int> zt_(n);

    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            zero_ans ^= a[i];
            zt_[i] = a[i];
        }else{
            one_ans ^= a[i];
            ot_[i] = a[i];
        }
    }

    SegmentTree ones(ot_); //we only need it for queries tho... lol
    SegmentTree twos(zt_);

    while(q){
        int t; cin >> t; 

        if(t == 1){
            int l, r; cin >> l >> r;
            l--; r--;

            one_ans ^= ones.query(l, r);
            one_ans ^= twos.query(l, r);
            zero_ans ^= ones.query(l, r);
            zero_ans ^= twos.query(l, r);
        }else{
            int m; cin >> m;
            if(m == 0){
                cout << zero_ans << " ";
            }else{
                cout << one_ans << " ";
            }
        }
        q--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
