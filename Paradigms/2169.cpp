#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, double> armas {
  {"HANDGUN", 2.0},
  {"RED9", 3.5},
  {"BLACKTAIL", 3.5},
  {"MATILDA", 2.0},
  {"HANDCANNON", 60.0},
  {"STRIKER", 12.0},
  {"TMP", 1.2},
  {"RIFLE", 12.0}
};

map<string, int> monstros {
  {"GANADOS", 50},
  {"COBRAS", 40},
  {"ZEALOT", 75},
  {"COLMILLOS", 60},
  {"GARRADOR", 125},
  {"LASPLAGAS", 100},
  {"GATLINGMAN", 150},
  {"REGENERATOR", 250},
  {"ELGIGANTE", 500},
  {"DR.SALVADOR", 350},
};

struct conteudo {

  int valor;
  int peso;
};

int N, v, w, tam;
vector<conteudo> mochila; // Mochila com pesos e valores

int Knapsack(int v_size, int tamanho){

  vector<vector<int>> cash(v_size + 1, vector<int>(tamanho + 1)); // Matriz de possibilidades da Mochila

  for(int i = 0; i <= N; i++){

    for(int w = 0; w <= tamanho; w++){

      if(i == 0 or w == 0) cash[i][w] = 0;
        
      else if(mochila[i - 1].peso <= w)
        cash[i][w] = max(mochila[i - 1].valor +
        cash[i - 1][w - mochila[i - 1].peso],
        cash[i - 1][w]);
        
      else cash[i][w] = cash[i - 1][w];
    }
  }
  return cash[v_size][tamanho];
}


int main(){
  
  string nome;
  int M;

  while(cin >> N){
    for(int i = 0; i < N; i++){
      cin >> nome >> w;
      v = armas[nome]*w;
      mochila.push_back({v, w});
    }

    cin >> M;
    int total = 0;
    for(int i = 0; i < M; i++){
      cin >> nome >> w;
      total += monstros[nome]*w;
    }

    cin >> tam;

    int resp = Knapsack(N, tam);

    if(resp >= total){
      cout << "Missao completada com sucesso" << endl;
    } else{
      cout << "You Are Dead" << endl;
    }

    cout << endl;
    mochila.clear();
  } // Quantidade de Itens

}
