#include<string>
#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S;

    int N;
    cin >> N;
    string oper;
    while(N--){
        // iterate
        cin >> oper;
        if(oper=="push"){
            int val;
            cin >> val;
            S.push(val);
        }
        else{
            if(oper=="pop"){
                if(S.empty()) cout << -1;
                else{
                    cout << S.top();
                    S.pop();
                }
            }
            else if(oper=="size"){
                cout << S.size();
            }
            else if(oper=="empty"){
                cout << S.empty();
            }
            else{
                // top
                if(S.empty()) cout << -1;
                else cout << S.top();
            }
            cout << "\n";
        }
        
    }
}