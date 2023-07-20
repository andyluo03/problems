//wecu's template -- works with c++20

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
//#define endl '\n'

typedef long long ll;
using namespace std;

//void pc(auto& c){for_each(c.begin(), c.end(), [](auto u){cout << u << " ";});}

void solution(){
    int n; cin >> n;

    vector<vector<int>> graph(n, vector<int>(n)); //adjacency matrix!

    cout << "? 1" << endl; //1 will be our root
    vector<int> a(n);
    int odd = 0;
    int even = 0;
    forn(n) {
        cin >> a[i]; 
        odd += a[i]%2; 
        even += (a[i]+1)%2;
    }

    vector<int> queries;
    forn(n) {
        if((a[i] + (odd < even ? 0 : 1)) % 2 && i != 0)
            queries.push_back(i);
        if(a[i] == 1)
            graph[0][i] = 1;
    }
    
    for (int i : queries) {
        cout << "? " << (i+1) << endl;
        for(int j = 0; j < n; j++){
            int t; cin >> t;
            if(t == 1){
                graph[min(i, j)][max(i, j)] = 1;
            }
        }
    }


    //avoid repeats
    cout << "!" << endl;
    for(int r = 0; r < graph.size(); r++){
        for(int c = 0; c < graph.size(); c++){
            if(graph[r][c])
                cout << (r+1) << " " << (c+1) << endl;
        }
    }
}

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
