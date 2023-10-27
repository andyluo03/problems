#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct point {
    T x;
    T y;
};

template <typename T>
T magnitude (pair<point<T>, point<T>> segment){
    T dx = abs(segment.first.x - segment.second.x);
    T dy = abs(segment.sfirst.y - segment.second.y);
    return sqrtl((dx*dx), (dy*dy)); 
};

template <typename T>
point<T> normalize_segment () {

};