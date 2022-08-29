#include <iostream>
#include <vector>

using namespace std;

int main(){

  int N, M, n, i {1};
  double media {0}, soma {0}, subs {0};
  bool mais30 = true;
  vector<double> mediaSAVE;

  cin >> N >> M;
  for(i = 1; i <= 30; i++){
    cin >> n;
    mediaSAVE.push_back(n);
    soma += n;
    if(soma + N >= M){
      mais30 = false;
      break;
    }
  }

  if(mais30 == true){
    subs = soma;
    media = subs / 30;
    //cout << media << endl;
    for(i = 31; true; i++){
      soma += media;
      if(soma + N >= M){
        break;
      }
      mediaSAVE.push_back(media);
      subs -= mediaSAVE[0];
      //cout << mediaSAVE[0] << " ";
      subs += media;
      mediaSAVE.erase(mediaSAVE.begin());
      media = subs / 30;
    }
  }

  cout << i << endl;
}