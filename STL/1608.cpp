#include <iostream>
#include <vector>
using namespace std;

// Sumário:
// T = Quantidade de casos
// D = Dinheiro da Dona Maria
// I = Número de ingredientes
// B = Tipos de bolos existentes

int main() {
  int T, D, I, B, valor, n, index, value, bolos = 0, contador = 0, total  = 0, maior = 0;
  int ing[100];
  cin >> T;
  for(int i = 0; i < T; i++){
    cin >> D >> I >> B;
    for(int j = 0; j < I; j++){
      cin >> valor;
      ing[j] = valor;
    }
    maior = 0;
    for(int k = 0; k < B; k++){
      //cout << "BOLOS = " << k << endl;
      cin >> n;
      for(int t = 0; t < n; t++){
        cin >> index;
        cin >> value;
        bolos = value*ing[index] + bolos;
      }
      //cout << "BOLO: " << bolos << " D: " << D << endl;
      if(bolos <= D){
        total = bolos;
        while(total <= D){
          contador++;
          total = bolos + total;
        }
      }
      bolos = 0;
      //cout << "CONTADOR = " << contador << endl;
      if(contador > maior){
        maior = contador;
      }
      contador = 0;
    }
    cout << maior << endl;
  } 
}
