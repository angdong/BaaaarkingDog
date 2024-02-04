#include<string>
#include<iostream>
#include<stack>

using namespace std;

stack<int> St;

int convert(char c){
    if(c == '[') return -4;
    if(c == '(') return -3;
    if(c == ')') return -2;
    else return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    for(char c: str){
        if(St.empty()){
            St.push(convert(c));
        }
        else{
            if(c=='(' || c=='[') St.push(convert(c));
            if(c==']'){
                
                int tmp = 0;
                while(!St.empty()){
                    if(St.top() > 0){
                        tmp += St.top();
                        // cout << "[" << St.top() << "]";
                        St.pop();
                    }
                    else if(St.top() == convert('[')){
                        // done!
                        St.pop();
                        int res = tmp > 0? 3*tmp: 3;
                        St.push(res);
                        // cout << res << "\n";
                        break;
                    }
                    else{
                        cout << 0;
                        return 0;
                    }
                }
                if(St.empty()){
                    cout << 0;
                    return 0;
                }
            }
            if(c==')'){
                
                int tmp = 0;
                while(!St.empty()){
                    if(St.top() > 0){
                        tmp += St.top();
                        // cout << "[" << St.top() << "]";
                        St.pop();
                    }
                    else if(St.top() == convert('(')){
                        // done!
                        St.pop();
                        int res = tmp > 0? 2*tmp: 2;
                        St.push(res);
                        // cout << res << "\n";
                        break;
                    }
                    else{
                        cout << 0;
                        return 0;
                    }
                }
                if(St.empty()){
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    // cout << "hey";
    int ans = 0;

    if(St.empty()){
        cout << 0;
        return 0;
    }
    while(!St.empty()){
        // cannot go
        if(St.top() < 0){
            cout << 0;
            return 0;
        }
        ans += St.top();
        St.pop();
    }
    cout << ans;
    return 0;
}