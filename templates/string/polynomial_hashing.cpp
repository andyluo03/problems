#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <map>

std::random_device rng;

struct PolyHash {
    std::vector<uint64_t> prefix, suffix;

    PolyHash(std::string str){
        
    }
};

int main () {
    std::string example = "onetwothreefour";

    PolyHash H(example);
    
}