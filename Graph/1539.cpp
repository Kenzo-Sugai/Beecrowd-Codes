#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Ponto{
    int x;
    int y;
};

class Aresta{
public:
    int v1;
    int v2;
    int w;

    Aresta(int v1, int v2, int w){
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
    }
};

vector< Aresta > A;
vector<int> conj;

bool comp(Aresta a, Aresta b){
    return a.w < b.w;
}

int find(int k){
    if(conj[k]== -1)
        return k;
    return find(conj[k]);
}
int soma = 0;

void kruskal(int m){
    conj.resize(m, -1);
    int conta = 0;
    soma = 0;

    for (int i = 0; i < A.size() ; ++i) {
        int v_1 = find(A[i].v1);
        int v_2 = find(A[i].v2);

        if(v_1 != v_2){
            soma += A[i].w;
            conj[v_1] = v_2;
            conta++;
        }
        if(conta == m-1)
            return; 
    }
}

int main() {
    int n, m, x, y, c, z, N;

    while(true){
      cin >> N;
      vector<Ponto> pontos;
      if(N == 0){
        break;
      }
      A.clear();
      conj.clear();
      for(int i = 0; i < N ; ++i){
        cin >> x >> y >> z;
        A.push_back(Aresta(x, y, z));
      }
      cin >> c;
      for(int i = 0; i < c; i++){
        int qnt = 0;
        //cout << "A" << endl;
        cin >> x >> y;
        double w = sqrt(pow(A[x-1].v1 - A[y-1].v1, 2)+pow(A[x-1].v2 - A[y-1].v2, 2));
        //cout << "w: " << w << endl;
        if(w <= A[x-1].w){
          cout << int(w) << endl;
        }
        else{
          cout << -1 << endl;
        }
      }
    }
    return 0;
} 