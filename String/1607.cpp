#include <iostream>

using namespace std;

int main(){

  int N;
  string A, B;

  cin >> N;

  while(N--){
    cin >> A >> B;
    int soma = 0;
    for(int i = 0; i < A.size(); i++){
      if(A[i] < B[i]){
        soma += B[i] - A[i];
      }
      else if(A[i] > B[i]){
        soma += 26 - std::abs(A[i] - B[i]);
      }
      else{
        soma += 0;
      }
    }
    cout << soma << endl;
  }
}