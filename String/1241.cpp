#include <iostream>

using namespace std;

int main(){
    int N;
    string A, B;
    cin >> N;
    while(N--){
        cin >> A >> B;
        bool check = true;
        for(int i = A.size() - 1; i >= 0; i--){
            if(B.size() == 0){
                break;
            }
            if(A[i] == B.back()){
                B.pop_back();
            }
            else{
                check = false;
                break;
            }
        }
        if(B.size() > 0) check = false;
        if(check) cout << "encaixa" << endl;
        else cout << "nao encaixa" << endl;
    }
}
