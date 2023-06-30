#include <bits/stdc++.h>
#define forn(n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
template<class T>
void pvec(vector<T> v){for(auto a : v) cout << a << " ";}

void solution(){
    int n; cin >> n;

    vector<int> a(n);
    forn(n){cin>>a[i];}

    if(n <= 2){
        cout << "YES";
        return;
    }

    //slime
    vector<pair<int, int>> blob; //blob[i].first = max, blob[i].second = min;

    int z = 0;
    if(n%2){
        blob.push_back({a[0], a[0]});
        z++;
    }

    for(int i = z; i < a.size()-1; i+=2){
        blob.push_back({max(a[i], a[i+1]), min(a[i], a[i+1])});
    }

    for(int i = 1; i < blob.size(); i++){
        if(blob[i].second < blob[i-1].first){
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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