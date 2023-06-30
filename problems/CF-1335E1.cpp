//wecu's template -- works with c++20

#include <bits/stdc++.h>
#define forn(n) for(int i = 0; i < n; i++)
#define endl "\n"

typedef long long ll;
using namespace std;

//void pc(auto& c){for_each(c.begin(), c.end(), [](auto u){cout << u << " ";});}

void solution(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> ps(26, vector<int>(n));

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < ps.size(); j++){
            if(i!=0)
                ps[j][i] = ps[j][i-1];
        }
        ps[a[i]][i]++;
    }
    
    vector<map<int, int>> fs(26); //fs[char][cnt] = highest_index!
    for(int i = 0; i < fs.size(); i++){
        for(int z = a.size()-1; z >= 0; z--){
            if(a[z] == i)
                fs[i][fs[i].size()+1] = z;
        }
    }

    int ans = 1;
    for(int i = 0; i < n; i++){
        int p_cnt = ps[a[i]][i];
        int s_ind;
        if(fs[a[i]].find(p_cnt) == fs[a[i]].end())
            s_ind = -1;
        else
            s_ind = fs[a[i]][p_cnt];
        
        //check they don't overlap! (could this be done faster w/ a )
        
        if(s_ind > i){
            int pos = 2 * p_cnt; //both sides
            int l = i+1;
            int h = s_ind-1;
            int mx = 0;
            
            if(l < h){
                for(auto pp : ps)
                    mx = max(mx, pp[h] - pp[l-1]);

                ans = max(pos+mx, ans);
            }else if(l == h){
                mx = 1;
            }

            ans = max(pos+mx, ans);
        }
    }
    

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
