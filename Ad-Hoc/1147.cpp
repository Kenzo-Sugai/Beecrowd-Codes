#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  string c, p, c1;
  int p1, p2, c2, cavalo;

  while(cin >> c){
    int mov {0};
    c1 = c[0];
    c2 = int(c[1] - 97);
    cavalo = stoi(c1) * 10 + c2;
    vector<vector<bool>>cor;
    cor.resize(8);
    for(int i = 0; i < 8; i++){
      cor[i].resize(8);
    }
    for(int i = 0; i < 8; i++){
      cin >> p;
      p1 = int(p[0] - 49);
      p2 = int(p[1] - 97);
      cout << p1 << " " << p2 << endl;
      cor[p1][p2] = true;
    }
    if(cavalo + 12 <= 77){
      p1 = cavalo + 23;
      p2 = cavalo + 21;
      if(p1 <= 77 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 <= 77 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
    if(cavalo + 21 <= 77){
      p1 = cavalo + 32;
      p2 = cavalo + 30;
      if(p1 <= 77 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 <= 77 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
    if(cavalo + 8 <= 77){
      p1 = cavalo + 19;
      p2 = cavalo + 17;
      if(p1 <= 77 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 <= 77 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
    if(cavalo - 12 >= 0){
      p1 = cavalo - 3;
      p2 = cavalo - 1;
      if(p1 >= 0 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 >= 0 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
    if(cavalo - 21 >= 0){
      p1 = cavalo - 12;
      p2 = cavalo - 11;
      if(p1 >= 0 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 >= 0 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
    if(cavalo + 19 <= 77){
      p1 = cavalo + 20;
      p2 = cavalo + 18;
      if(p1 <= 77 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 <= 77 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
    if(cavalo - 19 >= 0){
      p1 = cavalo - 8;
      p2 = cavalo - 11;
      if(p1 >= 0 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 >= 0 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
    if(cavalo - 8 >= 0){
      p1 = cavalo - ;
      p2 = cavalo + 21;
      if(p1 <= 77 && !(cor[p1 / 10][p1 - ((p1 /10) * 10)] == true) && p2 <= 77 && !(cor[p2 / 10][p2 - ((p2 /10) * 10)] == true)){
        mov++;
      }
    }
  }
}