#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

struct Ponto{
    int x;
    int y;
};

class Aresta{
public:
    int v1;
    int v2;
    double w;

    Aresta(int v1, int v2, double w){
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

double peso_dist(Ponto p1, Ponto p2){
  return sqrt(pow(p1.x - p2.x, 2)+pow(p1.y - p2.y, 2));
}

int find(int k){
    if(conj[k]== -1)
        return k;
    return find(conj[k]);
}
double soma = 0;

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
    int c,n, x, y;
    double dist;
    while(cin >> n){
    vector<Ponto> pontos;

       for(int i = 0; i < n; i++){
         cin >> x >> y;
         pontos.push_back({x,y});
       }

       for(int i = 0; i < pontos.size()-1; i++){

           Ponto p1 = pontos[i];

           for(int j = i+1; j < pontos.size(); j++){

               Ponto p2 = pontos[j];
               dist = peso_dist(p1, p2);
               A.push_back({i,j,dist});
           }
       }

       sort(A.begin(), A.end(), comp);

       kruskal(A.size());

       cout << fixed << setprecision(2) << soma << endl;

       A.clear();
       conj.clear();
       pontos.clear();
    }
    return 0;
}