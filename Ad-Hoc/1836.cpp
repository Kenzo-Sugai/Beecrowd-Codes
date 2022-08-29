#include <iostream>
#include <math.h>

using namespace std;

int main(){

  int N, level, B, EV, IV, HP, S;
  string name;

  cin >> N;

  for(int j = 0; j < N; j++){

    cin >> name >> level;
    cout << "Caso #" << j+1 << ": " << name << " nivel " << level << endl;
    for(int i = 0; i < 4; i++){
      cin >> B >> IV >> EV;
      if(i == 0){
        HP = (((IV + B + sqrt(EV)/8 + 50) * level)/50) + 10;
        cout << "HP: " << HP << endl;
      }
      else{
        S = (((IV + B + sqrt(EV)/8) * level)/50) + 5;
        switch(i){
          case 1: cout << "AT: "; break;
          case 2: cout << "DF: "; break;
          case 3: cout << "SP: "; break;
        }
        cout << S << endl;
      }
    }
  }
}