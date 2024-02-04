#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string w1, w2;
    int word[30] = {};
    cin >> w1 >> w2;
    for(auto c: w1){
        word[c - 'a']++;
    }
    for(auto c: w2){
        word[c - 'a']--;
    }
    int ans = 0;
    for(auto i: word){
        ans += abs(i);
    }
    cout << ans;
}