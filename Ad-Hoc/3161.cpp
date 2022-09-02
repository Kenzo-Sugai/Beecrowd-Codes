#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

struct check_fruit {
    string fruit_name;
    bool isLike;
};

string reverse(string str){
    string aux = "";
    for(int i = str.size() - 1; i >= 0; i--)
        aux += str[i];
    return aux;
}

int main(){

    int F, C;
    string f, line;

    cin >> F >> C;

    vector<check_fruit> frutas;
    for(int i = 0; i < F; i++){
        cin >> f;
        for(int j = 0; j < f.size(); j++)
            f[j] = tolower(f[j]);
        frutas.push_back({f, false});
    }

    for(int i = 0; i < C; i++){
        cin >> line;
        for(int j = 0; j < line.size(); j++)
            line[j] = tolower(line[j]);
        for(int j = 0; j < frutas.size(); j++){
            int cnt = 0;
            if(!frutas[j].isLike){
                for(int k = 0; k < line.size(); k++){
                    //cout << frutas[j].fruit_name[cnt] << " " << line[k] << endl;
                    if(frutas[j].fruit_name[cnt] == line[k]){
                        cnt++;
                    }
                    else{
                        cnt = 0;
                        if(frutas[j].fruit_name[cnt] == line[k]){
                            cnt++;
                        }
                    }
                    if(cnt == frutas[j].fruit_name.size()){
                        frutas[j].isLike = true;
                        break;
                    }
                    else if(k == line.size() - 1){
                        //cout << "reverso: " << endl;
                        line = reverse(line);
                        for(int k = 0; k < line.size(); k++){
                            //cout << frutas[j].fruit_name[cnt] << " " << line[k] << endl;
                            if(frutas[j].fruit_name[cnt] == line[k]){
                                cnt++;
                            }
                            else{
                                cnt = 0;
                                if(frutas[j].fruit_name[cnt] == line[k]){
                                    cnt++;
                                }
                            }
                            if(cnt == frutas[j].fruit_name.size()){
                                frutas[j].isLike = true;
                                break;
                            }
                        }
                    }   
                }
            }
        }
    }

    for(int i = 0; i < frutas.size(); i++){
        if(frutas[i].isLike)
            cout << "Sheldon come a fruta " << frutas[i].fruit_name << endl;
        else
            cout << "Sheldon detesta a fruta " << frutas[i].fruit_name << endl;
    }
}
