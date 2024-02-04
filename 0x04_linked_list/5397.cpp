#include <iostream>
#include <string>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // eng, <, >, -
    int N;
    cin >> N;
    
    while(N--){
        list<char> password;
        string input_password;
        cin >> input_password;
        list<char>::iterator cursor = password.begin();
        for(char c: input_password){
            if(c == '<'){
                // go left
                if(cursor!=password.begin()) cursor--;
            }
            else if(c == '>'){
                // go right
                if(cursor!=password.end()) cursor++;
            }
            else if(c == '-'){
                // delete
                if(cursor!=password.begin()){
                    cursor--;
                    cursor = password.erase(cursor);
                }
            }
            else{
                // typing
                cursor = password.insert(cursor, c);
                cursor++;
            }
        }
        for(cursor=password.begin(); cursor!=password.end(); cursor++){
            cout << *cursor;
        }
        cout << "\n";
    }
}