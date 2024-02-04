#include<iostream>
#include<deque>
#include<string>

using namespace std;
int N;

deque<int> DQ;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        string oper;
        cin >> oper;
        if(oper=="push_front"){
            int tmp;
            cin >> tmp;
            DQ.push_front(tmp);
        }
        else if(oper=="push_back"){
            int tmp;
            cin >> tmp;
            DQ.push_back(tmp);
        }
        else if(oper=="pop_front"){
            if(DQ.empty()) cout << -1;
            else{
                cout << DQ.front();
                DQ.pop_front();
            }
            cout << "\n";
        }
        else if(oper=="pop_back"){
            if(DQ.empty()) cout << -1;
            else{
                cout << DQ.back();
                DQ.pop_back();
            }
            cout << "\n";
        }
        else if(oper=="size"){
            cout << DQ.size();
            cout << "\n";
        }
        else if(oper=="empty"){
            if(DQ.empty()) cout << 1;
            else cout << 0;
            cout << "\n";
        }
        else if(oper=="front"){
            if(DQ.empty()) cout << -1;
            else cout << DQ.front();
            cout << "\n";
        }
        else if(oper=="back"){
            if(DQ.empty()) cout << -1;
            else cout << DQ.back();
            cout << "\n";
            
        }
    }
}