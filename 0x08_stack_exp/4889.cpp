#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> St;
string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    while(1){
        int ans = 0;
        cnt++;
        cin >> str;
        if(str[0] == '-') break;
        for(char c: str){
            if(St.empty()){
                if(c == '}'){
                    ans++;
                }
                St.push('{');
            }
            else{
                if(c == '}'){
                    if(St.top() == '{'){
                        St.pop();
                    }
                }
                else{
                    // c == '{'
                    St.push('{');
                }
            }
        }
        while(St.size()){
            ans++;
            St.pop();
            St.pop();
        }
        cout << cnt << ". " << ans << "\n";
    }

}