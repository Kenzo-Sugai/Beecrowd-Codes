#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

struct pontos{
  int x;
  int y;
};

int main(){
  int N;
  double distance;
  while(cin >> N){
    if(N == 0) break;

    double menor = INT64_MAX;
    pontos plano[N];

    for(int i = 0; i < N; i++){
      cin >> plano[i].x >> plano[i].y;
    }

    for(int i = 0; i < N; i++){
      for(int j = i; j < N; j++){
        distance = sqrt(pow(plano[i].x-plano[j].x, 2)+pow(plano[i].y-plano[j].y, 2));
        if(distance < menor && distance != 0)
          menor = distance;
      }
    }
    if(menor >= 10000)
      cout << "INFINITY" << endl;
    else
      printf("%.4lf\n", menor);   
  }
}