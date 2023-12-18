const int MAX_N = 2e5+1;
bool composite[MAX_N]{false};

void sieve(){
  for(int i = 0; i < MAX_N; i++){
    //if prime
    if(!composite[i]){
      for(int j = i*2; j < MAX_N; j+=i){
        composite[j] = true;
      }
    }
  }
}