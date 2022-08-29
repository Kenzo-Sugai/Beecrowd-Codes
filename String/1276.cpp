#include <iostream>
#include <vector>

using namespace std;

int main(){
  string frase;
  while(getline(cin, frase)){
    vector<bool> alfabeto(26, false);
    for(int i = 0; i < frase.size(); i++){
      if(frase[i] >= 'a' && frase[i] <= 'z'){
        alfabeto[int(frase[i] - 97)] = true;
      }
    }
    bool seq = false, first = true;
    for(int i = 0; i < alfabeto.size(); i++){
      if(alfabeto[i] == true && seq == false){
        if(first == false){
          cout << ", ";
        }
        cout << char(i + 97);
        seq = true;
        first = false;
      }
      else if(alfabeto[i] == false && seq == true){
        cout << ":" << char(i-1 + 97);
        seq = false;
      }
      if(i == alfabeto.size() - 1 && alfabeto[i] == true && seq == true){
        cout << ":" << char(i + 97);
        seq = false;
      }
    }
    cout << endl;
  }
}