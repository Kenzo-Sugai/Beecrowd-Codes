#include <iostream>

using namespace std;

int isPrime(int n){
  int result {0};
  for(int i = 0; i < n; i++){
    int cnt {0};
    for(int j = 1; j < i; j++){
      if(j % i == 0){
        cnt++;
        if(cnt > 1){
          break;
        }
      }
    }
    if(cnt != 1){
      result++;
    }
  }
  return result;
}

int main(){

  int N, M, K;

  while(cin >> N >> M >> K){
    if(N == 0 && M == 0 & K == 0){
      return 0;
    }
    cout << abs(isPrime(M*N-1)) << endl;
  }
}