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
using pi  = pair<int, int>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;

void pv(vi a) {
    #ifdef DEBUG 
    forn(a.size()){cout << a[i] << ", ";} cout << endl; 
    #endif
}

struct node {
    char val;
    int cnt[26];
    vector<int> edges;
};

void solution(){
    int n, m; cin >> n >> m;
    string a; cin >> a;
    vector<node> graph(n);
    for(int i = 0; i < a.size(); i++){
        graph[i].val = a[i];
    }

    vector<int> indegrees(n);
    set<int> visited;
    int ans = 0;

    forn(m){
        int start, end; cin >> start >> end;
        graph[start-1].edges.push_back(end-1);
        indegrees[end-1]++;
    }

    queue<int> q;
    for(int i = 0; i < indegrees.size(); i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }

    while(q.size()){
        auto& c = graph[q.front()];
        c.cnt[c.val - 'a']++;

        if(visited.find(q.front()) != visited.end()){
            cout << -1;
            return;
        }

        for(int i : c.edges){
            for(int chr = 0; chr < 26; chr++){
                graph[i].cnt[chr] = max(graph[i].cnt[chr], c.cnt[chr]);
            }

            indegrees[i]--;
            if(indegrees[i] == 0)
                q.push(i);
        }

        for(int chr = 0; chr < 26; chr++)
            ans = max(ans, c.cnt[chr]);
        visited.insert(q.front());
        q.pop();
    }

    if(visited.size() != n){
        cout << -1;
    }else{
        cout << ans;
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
