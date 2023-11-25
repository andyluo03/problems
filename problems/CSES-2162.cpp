//wecu's template -- works with c++17

#include <bits/stdc++.h>

#define forn(n) for(int i = 0; i < n; i++)
#define endl '\n'

using namespace std;
using ll  = long long;
using pi  = pair<int, int>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;

void pv(vi a) {
    #ifdef DEBUG 
    forn(a.size()){cout << a[i] << ", ";} cout << endl; 
    #endif
}

struct Node {
    Node* prev; //i should probably start using unique_ptrs haha
    Node* next;
    int val;

    Node(int v){
        val = v;
    }
};

void solution(){
    int n; cin >> n;

    if(n == 1){
        cout << 1;
        return;
    }

    //construct!
    Node* root = new Node(1);

    {
        Node* cur = root;
        for(int i = 2; i <= n; i++){
            cur->next = new Node(i);
            cur->next->prev = cur;
            cur = cur->next;
        }

        cur->next = root;
        root->prev = cur;
    }

    Node* cur = root;
    for(int i = 0; i < n; i++){
        //move cur forwards
        cur = cur->next;
        //print value
        cout << cur->val << " ";
        
        Node* before = cur->prev;
        Node* after = cur->next;

        before->next = after;
        after->prev = before;

        cur = after;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    //cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
