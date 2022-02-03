#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

  unordered_map<string, int> amigos;
  unordered_map<int, string> amigos2;
  int n, G, ctr = 1, contador = 0;
  bool verify = false;
  string start;
  vector<bool> cor(1000, false);

  vector <vector<int> > g;

  g.resize(1000);

  cin >> n >> G;

  vector<int> dist(1000, G+1);

  for(int i = 0; i < n; i++){
    string p1, p2;
    cin >> p1 >> p2;
    if(i == 0){
      start = p1;
    }

    if(amigos.count(p1) == 0){
      amigos.emplace(p1, ctr);
      amigos2.emplace(ctr, p1);
      ctr++;
    }
    if(amigos.count(p2) == 0){
      amigos.emplace(p2, ctr);
      amigos2.emplace(ctr, p2);
      ctr++;
    }
    //cout << p1 << " - " << amigos[p1] << endl;
    //cout << p2 << " - " << amigos[p2] << endl;
    g[amigos[p1]].push_back(amigos[p2]);
    g[amigos[p2]].push_back(amigos[p1]); 
  }

  queue<int> Q;

  Q.push(1);

  cor[1] = true;
  dist[1] = 0;

  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    for(int i = 0; i < g[u].size(); i++){
      if(!cor[g[u][i]]){
        //cout << u << " " << dist[u] << " " <<  g[u][i] << endl;
        dist[g[u][i]] = dist[u] +1;
        cor[g[u][i]] = true;
        Q.push(g[u][i]);
      }
    }
  }

  vector<string> sort_string;
  vector<string>::iterator itr;

  for(int i = 2; i < cor.size(); i++){

    if(dist[i] <= G){
      sort_string.push_back(amigos2[i]);
      contador++;
    }
  }
  sort(sort_string.begin(), sort_string.end());
  cout << contador << endl;

  for(itr = sort_string.begin(); itr != sort_string.end(); ++itr){
    cout << *itr << endl;
  }
} 
