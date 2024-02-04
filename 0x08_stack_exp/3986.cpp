#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> St;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int ans=0;
    while(N--){
        string word;
        cin >> word;
        bool isValid = true;
        for(char c: word){
            if(St.empty()) St.push(c);
            else{
                if(St.top() == c) St.pop();
                else{
                    St.push(c);
                }
            }
        }
        if(St.size()) isValid =false;
        if(isValid) ans++;
        while(St.size()) St.pop();
    }
    cout << ans;
}