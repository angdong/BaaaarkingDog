#include <iostream>
#include<queue>
#include<string>

using namespace std;

queue<int> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--){
        string oper;
        cin >> oper;
        if(oper == "push"){
            int tmp;
            cin >> tmp;
            Q.push(tmp);
        }
        else if(oper=="pop"){
            if(!Q.size()) cout << -1 << "\n";
            else{
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if(oper=="size"){
            cout << Q.size() << "\n";
        }
        else if(oper=="empty"){
            if(!Q.size()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(oper=="front"){
            if(!Q.size()) cout << -1 << "\n";
            else cout << Q.front() << "\n";
        }
        else{
            // back
            if(!Q.size()) cout << -1 << "\n";
            else cout << Q.back() << "\n";
        }
    }
}