#include<stack>
#include<iostream>
#include<string>

using namespace std;

stack<pair<char, int>> S;

#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string pipe;
    cin >> pipe;
    int ans=0;

    for(int i=0; i<pipe.length(); i++){
        char c = pipe[i];

        if(S.empty()){
            S.push({c, i});
            // cout << "No!\n";
        }
        else{
            if(S.top().X=='(' && c==')' && S.top().Y == i-1){
                // there's razer
                S.pop();
                ans += S.size();
            }
            else if(c=='('){
                S.push({c, i});
            }
            else if(c==')'){
                S.pop();
                ans++;
            }
        }
    }
    cout << ans;
}