#include <iostream>
#include <math.h>

using namespace std;

double distance(int X1, int Y1, int X2, int Y2){
  return sqrt(pow(X2-X1, 2) + pow(Y2-Y1, 2));
}

int main(){

  int 
  Xf, Yf, // Fiddlesticks cords
  Xi, Yi, // Invasor cords
  Vi, // Invasor velocidade
  R1, R2; // Raio da Ultimate e Raio dos Corvos

  while(cin >> Xf >> Yf >> Xi >> Yi >> Vi >> R1 >> R2){
      if((R1+R2) >= (distance(Xf, Yf, Xi, Yi) + Vi*1.5)){
        cout << "Y" << endl;
      }
      else   
        cout << "N" << endl;
  }
}