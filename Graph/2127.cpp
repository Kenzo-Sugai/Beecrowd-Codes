#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<climits>
 
using namespace std;
 
class Vertice{
    public:
        double w;
        int ind;

        Vertice(){};
         
        Vertice(int ind, double w){
            this->w = w;
            this->ind = ind;
        }
};
 
 
vector< vector<Vertice> > g;
 
vector<int> d;
vector<bool> cor;
vector<int> p;
 
bool comp(const int A, const int B)
{
    return d[A] > d[B];
}
 
void prim(int s)
{
    vector<int> Q;
    vector<bool> mst(g.size(), false);
    cor.resize(g.size(), false);
    p.resize(g.size(), -1);
    d.resize(g.size(), INT_MAX);
    Q.push_back(s);

    d[s] = 0;
    cor[s] = true;
    while(!Q.empty()){

        int u = Q[0];
        mst[u] = true;
        pop_heap(Q.begin(),Q.end(), comp); Q.pop_back();
         
        for(int i = 0; i < g[u].size(); i++) {

            if(p[u] != g[u][i].ind && g[u][i].w < d[g[u][i].ind] && mst[g[u][i].ind] == false){
                d[g[u][i].ind] = g[u][i].w;
                p[g[u][i].ind] = u;
            }
            if(cor[g[u][i].ind] == false){
                cor[g[u][i].ind] = true;
                Q.push_back(g[u][i].ind);
            }
        }
 
       make_heap(Q.begin(), Q.end(), comp);
    }
}
 
int main(){
	int X, Y, N, M, inst = 0;
	double w;
  while(scanf("%d %d", &N, &M) != EOF){
    inst++;
    g.resize(N+1);
	  for(int i=0;i<M;i++){
		  scanf("%d %d %lf", &X, &Y, &w);
		  g[X].push_back(Vertice(Y,w));
      g[Y].push_back(Vertice(X,w));
    }
    prim(1);
    long long int soma = 0;
    for(int i=1;i<=N;i++){
      soma = soma + d[i];
    }
    
    printf("Instancia %d\n", inst);
    printf("%ld\n", soma);
    printf("\n");

    g.clear();
    cor.clear();
    d.clear();
    p.clear();
  }
	return 0;
}
