#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i=0; i< N; i++){
        // iterate
        int dict[26] = {};
        string w1, w2;
        cin >> w1;
        cin >> w2;
        for (auto c: w1){
            dict[c-'a']++;
        }
        for (auto c: w2){
            dict[c-'a']--;
        }
        for (int i =0; i<26; i++){
            if(dict[i]!=0){
                cout << "Impossible";
                break;
            }
            if (i==25){
                cout << "Possible";
            }
        }
        cout << "\n";
    }
}