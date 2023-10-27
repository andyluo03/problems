#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
using namespace std;
 
using ll = long long;
using ld = long double;
#define sz(x) (ld)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define in(box,x) (bool)(box.find(x) != box.end())
 
struct dsu {
	vector<int> parent, size;
 
	dsu(int n) {
		parent.resize(n+1); size.resize(n+1,1);
		for (int i = 0; i <= n; i++) parent[i] = i;
	}
 
	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}
 
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
};
 
bool dfs(int curr, int prev, vector<bool>& seen, vector<int>& color, vector<vector<int>>& adj) {
	if (seen[curr]) return (color[curr] != color[prev]);
	seen[curr] = true;
	color[curr] = (color[prev] == 1 ? 2 : 1);
	for (auto i : adj[curr]) {
		if (!dfs(i, curr, seen, color, adj)) return false;
	}
	return true;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	dsu mydsu(m);
	vector<int> locked, unlocked;
	for (int i = 1; i <= n; i++) {
		int a; cin>>a;
		if (a == 1) unlocked.pb(i);
		else locked.pb(i);
	}
	vector<vector<int>> switches(n+1);
	for (int i = 1; i <= m; i++) {
		int x; cin>>x;
		while (x--) {
			int a; cin>>a;
			switches[a].pb(i);
		}
	}
	for (auto i : unlocked) {
		int a = switches[i][0], b = switches[i][1];
		mydsu.union_sets(a,b);
	}	
	vector<vector<int>> adj(m+1);
	for (auto i : locked) {
		int a = mydsu.find_set(switches[i][0]), b = mydsu.find_set(switches[i][1]);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<bool> seen(m+1,false);
	seen[0] = true; 
	vector<int> color(m+1);
	color[0] = 1;
	for (int i = 1; i <= m; i++) {
		if (!seen[i]) {
			if (!dfs(i, 0, seen, color, adj)) {
				cout << "NO\n"; return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}