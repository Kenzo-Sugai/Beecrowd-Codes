#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct cordenadas{
  int x;
  int y;
};

int main(){

  int casos, b, x, y, N;
  cin >> casos;

  while(casos--){
    double distance, limite = INT64_MAX;
    cin >> b;
    vector<cordenadas> bolas;
    for(int i = 0; i <= b; i++){
      cin >> x >> y;
      bolas.push_back({x, y});
    }

    for(int i = 1; i <= b; i++){
      distance = sqrt(pow(bolas[0].x-bolas[i].x, 2)+pow(bolas[0].y-bolas[i].y, 2));
      if(distance < limite){
        limite = distance;
        N = i;
      }
    }

    cout << N << endl;


  }

}