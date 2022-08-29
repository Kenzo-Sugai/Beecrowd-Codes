#include <iostream>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

int main(){

    int L, C, R1, R2, area, D;
    double areaC1, areaC2;
    while(cin >> L >> C >> R1 >> R2){
        if(L == 0 && C == 0 && R1 == 0 && R2 == 0){
            return 0;
        }

        D = R1*2+R2*2;
        double r = R1 + R2;

        if(D <= L && (R1 <= C && R2 <= C) || D <= C && (R1 <= L && R2 <= L)){
            cout << "S" << endl;
        }
        else{
            if(sqrt(pow(L - R1 - R2, 2) + pow(C - R1 - R2, 2)) >= R1 + R2){
                cout << "S" << endl;
            }
            else{
                cout << "N" << endl;
            }
        }
    }
}