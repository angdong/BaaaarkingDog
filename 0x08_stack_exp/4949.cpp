#include<iostream>
#include<stack>

using namespace std;

stack<char> S;

int main(){
    string str;

    while(1){
        bool is_false = false;
        getline(cin, str);
        if(str == ".") break;
        for(char c: str){
            if(c == '[' || c == '('){
                S.push(c);
            }
            else if(c == ']'){
                if(!S.empty() && S.top() == '['){
                    S.pop();
                }
                else{
                    is_false=true;
                    break;
                }
            }
            else if(c == ')'){
                if(!S.empty() && S.top() == '('){
                    S.pop();
                }
                else{
                    is_false=true;
                    break;
                }
            }
        }
        if(is_false || !S.empty()) cout << "no";
        else cout << "yes";
        cout << "\n";
        while(!S.empty()) S.pop();
    }
    
}