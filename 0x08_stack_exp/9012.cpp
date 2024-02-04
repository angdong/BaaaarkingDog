#include<string>
#include<stack>
#include<iostream>

using namespace std;

int N;
stack<int> St;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        string str;
        cin >> str;
        bool isValid = true;
        for(char c: str){
            if(St.empty()) St.push(c);
            else{
                if(c == ')'){
                    if(St.top() == '(') St.pop();
                    else{
                        isValid = false;
                        break;
                    }
                }
                else{
                    St.push(c);
                }
            }
        }
        if(St.size()) isValid = false;
        if(isValid) cout << "YES";
        else cout << "NO";
        cout << "\n";
        while(St.size()) St.pop();
    }
}