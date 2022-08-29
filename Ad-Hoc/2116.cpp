#include <iostream>

using namespace std;

bool isPrime(int n){
  for(int i = 2; i < n; i++){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

int main(){

  int N, M;

  cin >> N >> M;
  for(int i = N; true; i--){
    if(isPrime(i)){
      N = i;
      break;
    }
  }
  for(int i = M; true; i--){
    if(isPrime(i)){
      M = i;
      break;
    }
  }
  cout << N*M << endl;
}