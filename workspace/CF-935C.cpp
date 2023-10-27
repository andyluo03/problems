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

struct point {
	double x;
	double y;
};

double distance(point a, point b){
	double dx = abs(a.x - b.x);
	double dy = abs(a.y - b.y);
	return sqrtl(dx*dx + dy*dy);
}

inline bool within(point flat, point laptop, double R){
	return distance(flat, laptop) < R;
}

point midpoint(point a, point b){
	return {(a.x+b.x)/2, (a.y+b.y)/2};
}

void solution(){
    double R, fx, fy, lx, ly; cin >> R >> fx >> fy >> lx >> ly;

	point flat = {fx, fy};
	point laptop = {lx, ly};

	if(within(flat, laptop, R)){
		cout << flat.x << " " << flat.y << " " << R << endl;
	}else{
		point end = {0, 0};

		//normalize
		double mag = distance(flat, laptop);
		double dx = flat.x - laptop.x;
		double dy = flat.y - laptop.y;

		dx /= mag;
		dy /= mag;

		end.x += dx * R;
		end.y += dy * R;

		point center = midpoint(laptop, end);
		cout << center.x << " " << center.y << " " << distance(center, laptop);
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
