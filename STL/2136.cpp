#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> nomes;
vector<string> yes;
vector<string> no;

bool find(string n){

  for(int i = 0; i < nomes.size(); i++){
    if(nomes[i] == n){
      return true;
    }
  }
  return false;

}

int main(){

  string nome, type, amigo;
  int maior {0};
  bool value;

  while(cin >> nome){
    if(nome == "FIM"){
      break;
    }
    cin >> type;
    if(type == "YES") value = true;
    if(type == "NO") value = false;

    if(!find(nome)){
      nomes.push_back(nome);
      if(value){
        if(nome.size() > maior){
          maior = nome.size();
          amigo = nome;
        }
        yes.push_back(nome);
      }
      else{
        no.push_back(nome);
      }
    }
  }

  sort(yes.begin(), yes.end());
  sort(no.begin(), no.end());

  for(int i = 0; i < yes.size(); i++){
    cout << yes[i] << endl;
  }
  for(int i = 0; i < no.size(); i++){
    cout << no[i] << endl;
  }
  cout << endl;
  cout << "Amigo do Habay:" << endl;
  cout << amigo << endl;
}