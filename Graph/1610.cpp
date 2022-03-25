#include <iostream>
#include <list>
#include <queue>
#include <vector>
#define BRANCO 0
#define CINZA 1
#define PRETO 2
using namespace std;
int tempo,D;
vector <int> cor;
vector <int> p;
vector <int> d;
vector <int> f;
bool verify = false;
bool naoeporra = false;
vector<vector <int> > g;
void DFS_Visit(int u){
  //cout << u << " - " << cor[u] << endl;
	cor[u]=CINZA;
	tempo=tempo+1;
	d[u]=tempo;
  //cout << "C" << endl;
	for(int i=0;i<g[u].size();i++){
    //cout << g[u][i] << " - " << cor[g[u][i]] << endl;
    //cout << g[u][i] << endl;
		if(cor[g[u][i]] == BRANCO){
			p[g[u][i]]=u;
			DFS_Visit(g[u][i]);
		}
    if(cor[g[u][i]] == CINZA){
      verify = true;
      return;
    }
	}
  cor[u]=PRETO;
	f[u]=tempo;
	tempo++;
}
void DFS(int ini, int D){
	tempo=-1;
  cor.resize(D+1);
  d.resize(D+1);
  p.resize(D+1);
  f.resize(D+1);
	for(int i=1;i<=D;i++){
		cor[i]=BRANCO;
		d[i]=0;
		p[i]=-1;
	}
  //cout << "B" << endl;
    for(int i = 1; i <= D; i++){
        if(cor[i] == BRANCO){
            DFS_Visit(i);
        }
    }
}
int main() {
    int A, B, x, y, T, D, P;
    cin >> T;
    while(T--){
        bool naoeporra = false;
        g.clear();
        cin >> D >> P;
	    g.resize(D+1);
        for(int i = 0; i < P; i++){
            cin >> A >> B;
            /*
            for(int k = 0; k < g[A].size(); k++){
                cout << g[A][k];
                if(g[A][k] == B){
                naoeporra = true;
                break;
                }
            }
            */
            g[A].push_back(B);
            /*
            if(naoeporra == false){
                cout << "AAAA" << endl;
                g[A].push_back(B);
            }
            else{
                naoeporra = false;
            }
            */
        }
        //cout << "A" << endl;
	    DFS(1, D);
        if(verify == false){
            cout << "NAO" << endl;
        }
        if(verify == true){
            cout << "SIM" << endl;
            verify = false;
        }
    }
}
