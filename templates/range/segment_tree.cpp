#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
const int MAXN = 1123456;

template<typename T>
class Segtree{
	private:
		vector<T> arr;

		//LLONG_MAX if min, LLONG_MIN if max, and 0 if sum
		const T base = LLONG_MAX; 
		T compare(T a, T b){
			//CURRENTLY SET TO MIN
			return min(a, b);
		}

		void build(vector<T>& input, int v, int tl, int tr){
			if(tl == tr){
				arr[v] = input[tl];
			}else{
				int tm = (tl+tr)/2; 
				build(input, v*2, tl, tm);
				build(input, v*2+1, tm+1, tr);
				arr[v] = compare(arr[v*2], arr[v*2+1]);
			}
		}

		T query(int v, int tl, int tr, int l, int r){
			if(l > r) return base;
			if(l == tl && r == tr) return arr[v];
			int tm = (tl + tr)/2;
			return compare(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
		}

		void update(int v, int tl, int tr, int pos, int new_val){
			if(tl == tr){
				arr[v] = new_val;
			}else{
				int tm = (tl+tr)/2;
				if(pos <= tm)
					update(v*2, tl, tm, pos, new_val);
				else
					update(v*2+1, tm+1, tr, pos, new_val);
				arr[v] = compare(arr[v*2], arr[v*2+1]);
			}
		}

	public:
		Segtree(vector<T> input){
			this->arr = vector<T>(4 * input.size());
			build(input, 1, 0, input.size()-1);
		}

		T query(int l, int r){
			return query(1, 0, (arr.size()/4)-1, l, r);
		}

		void update(int pos, int new_val){
			update(1, 0, (arr.size()/4)-1, pos, new_val);
		}
};