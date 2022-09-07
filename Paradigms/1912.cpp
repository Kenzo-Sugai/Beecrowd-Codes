#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b){
  return a > b;
}

int main() {
    int N, A, n, sum, diff;
    double size, lim;
   while(cin >> N >> A){
      if(!N && !A) return 0;
      sum = 0;
      vector<int> ret;
      vector<double> corte;
      for(int i = 0; i < N; i++){
          cin >> n;
          ret.push_back(n);
          sum += n;
       }
      if(sum == A) cout << ":D" << endl;
         
      else if(A > sum) cout << "-.-" << endl;
         
      else {
        sort(ret.begin(), ret.end(), compare);
          
        int total = 0, top;
         
        while(total < A){
          top = ret[0];
          //cout << "TOP: " << top << endl;
          //cout << "ITR: ";
          corte.clear();
          for(int i = 0; i < ret.size(); i++){
            if(ret[i] == top){
              //cout << ret[i] << " ";
              corte.push_back(ret[i]);
              total++;
              ret[i]--;
            }
            else{
              //cout << endl;
              break;
            }
          }
        }
        //cout << "TOTAL: " << total << endl;
        lim = ret[0];
        size = corte.size();
        if(total == A){
          printf("%.4lf\n", lim);
        }
        else {
          diff = abs(total - A);
          total -= corte.size(); // retira o excesso
          //cout << "TOTAL: " << total << endl;
          //cout << "CORTE SIZE: " << size << endl;
          //cout << "DIF: " << diff << endl;
          double x = diff/size;
          lim += x;
          printf("%.4lf\n", lim); 
          
        }
      }
   }
}
