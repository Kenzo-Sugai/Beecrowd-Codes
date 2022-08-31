#include <iostream>

using namespace std;

int main(){

    int N;
    string A[2], nome[2] = {"rajesh", "sheldon"};
    string win[10] = {
        "tesoura", "papel", "pedra", "lagarto", "spock", "tesoura",
        "lagarto", "papel", "spock", "pedra"};
    string lose[10] = {
        "papel", "pedra", "lagarto", "spock", "tesoura", "lagarto",
        "papel", "spock", "pedra", "tesoura"};

    cin >> N;

    while(N--){

        cin >> A[0] >> A[1];
        bool check = false;
        for(int i = 0; i < 2; i++){
            if(A[0] == A[1]){
                cout << "empate" << endl;
                break;
            }
            for(int j = 0; j < 10; j++){
                if(A[i] == win[j] && A[1 - i] == lose[j]){
                    check = true;
                    cout << nome[i] << endl;
                    break;
                }
            }
            if(check) break;
        }
    }
}
