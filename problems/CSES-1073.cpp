#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    multiset<int> t;

    for(int i = 0; i < n; i++){
        int c; 
        cin >> c;

        auto z = t.upper_bound(c);

        t.insert(c);

        if(z != t.end())
            t.erase(z);
    }

    cout << t.size();
}