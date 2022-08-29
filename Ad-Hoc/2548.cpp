#include <iostream>
#include <algorithm>

using namespace std;

int main(){


int N, M;
while(cin >> N >> M){
  int valor[N];
  for(int i = 0; i < N; i++){
    cin >> valor[i];
  }
  sort(valor, valor + N);
  int sum = 0;
  for(int i = N - 1; M > 0; i--){
    sum += valor[i];
    M--;
  }
  cout << sum << endl;
}

}