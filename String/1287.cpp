#include <iostream>
#include <string>

using namespace std;

int main(){

  string N, number;
  bool verificar;
  while(getline(cin, N)){
    verificar = false;
    number = "";
    for(int i = 0; i < N.size(); i++){
      
      if(N[i] == 'l')
        N[i] = '1';
      if(N[i] == 'o' || N[i] == 'O')
        N[i] = '0';
      if((N[i] >= 64 && N[i] <= 90) || (N[i] >= 97 && N[i] <= 122)){
        verificar = false;
        break;
      }
      if(N[i] >= 48 && N[i] <= 57){
        number += N[i];
        verificar = true;
      }
    }
    if(verificar == true){
      try{
        cout << stoi(number) << endl;
      } catch(exception e){
        cout << "error" << endl;
      }
    }
    if(verificar == false)
      cout << "error" << endl;
  }
}