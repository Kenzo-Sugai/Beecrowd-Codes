#include <iostream>
#include <math.h>

using namespace std;

struct ponto{
  int x;
  int y;
  int h;
};

int main(){

  ponto p1; ponto p2;
  int x1, x2, y1, y2, N, a, b, c, ver;
  cin >> x1 >> y1 >> x2 >> y2;

  cin >> N;

  p1.x = x1; p1.y = y1; p2.x = x2; p2.y = y2;

  double dist = sqrt(pow(p1.x - p2.x, 2)+pow(p1.y - p2.y, 2));

  a = (p1.y - p2.y);
  b = (p2.x - p1.x);
  c = p1.x * p2.y - p2.x * p1.y;

  ponto planetas[N];
  int casualidade = 0, oeste = 0, leste = 0, haboeste = 0, hableste = 0;
  for(int i = 0; i < N; i++){

    cin >> planetas[i].x >> planetas[i].y >> planetas[i].h;

    double local = (p2.x - p1.x) * (planetas[i].x - p1.x) - (p2.y - p1.y) * (planetas[i].y - p1.y);

    if(local > 0){
      leste++;
      hableste += planetas[i].h;
    }
    if(local < 0){
      oeste++;
      haboeste += planetas[i].h;
    }

    ver = (-1*(a*planetas[i].x+c))/b;
    if(ver == planetas[i].y){
      casualidade++;
    }
  }

  cout << "Relatorio Vogon #35987-2" << endl;
  printf("Distancia entre referencias: %.2lf anos-luz\n", dist);
  cout << "Setor Oeste:" << endl;
  cout << "- " << oeste << " planeta(s)" << endl;
  cout << "- " << haboeste << " bilhao(oes) de habitante(s)" << endl;
  cout << "Setor Leste:" << endl;
  cout << "- " << leste << " planeta(s)" << endl;
  cout << "- " << hableste << " bilhao(oes) de habitante(s)" << endl;
  cout << "Casualidades: " << casualidade << " planeta(s)" <<  endl;
}