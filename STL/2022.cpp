#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
  string nome;
  double preco;
  int escala;
};

bool comparar(item a, item b){
  return a.escala > b.escala;
}

int main(){
  string nome, n;
  double preco;
  int escala;
  int presentes;
  while(cin >> nome >> presentes){
    vector<item> lista;
    for(int i = 0; i < presentes; i++){
      getline(cin, n);
      cin >> preco >> escala;
      lista.push_back({n, preco, escala});
    }
    sort(lista.begin(), lista.end(), comparar);

    cout << "Lista de " << nome << endl;
    for(int i = 0; i < presentes; i++){
      cout << lista[i].nome << " - " << lista[i].preco << endl;
    }
  }
}