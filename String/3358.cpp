#include <iostream>

using namespace std;

int main(){
  int N;
  string S;
  cin >> N;
  while(N--){
    cin >> S;
    int contador = 0;
    bool verify = false;
    for(int i = 0; i < S.size(); i++){
      if(S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u' &&
       S[i] != 'A' && S[i] != 'E' && S[i] != 'I' && S[i] != 'O' && S[i] != 'U'){
        contador++;
      }
      else{
        contador = 0;
      }
      if(contador >= 3){
        verify = true;
        break;
      }
    }
    if(verify == true){
      cout << S << " nao eh facil" << endl;
    }
    else{
      cout << S << " eh facil" << endl;
    }
  }
}