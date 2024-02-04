#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> editor;
    list<char>::iterator cursor;
    
    string first_word;
    cin >> first_word;

    for(char c: first_word){
        // insert members
        editor.push_back(c);
    }
    cursor = editor.end();
    
    int iter_num;
    cin >> iter_num;
    for(int i=0; i<iter_num; i++){
        char oper;
        cin >> oper;
        if(oper == 'L'){
            // move left
            if(cursor != editor.begin()) cursor--;
        }
        else if(oper =='D'){
            // mover right
            if(cursor != editor.end()) cursor++;
        }
        else if(oper =='B'){
            // erase
            if(cursor != editor.begin()){
                cursor--;
                cursor = editor.erase(cursor);
            }
        }
        else{
            cin >> oper;
            // insert oper;
            cursor = editor.insert(cursor, oper);
            cursor++;
        }
        // cout << * cursor;
    }
    for(auto iter = editor.begin(); iter != editor.end(); iter++){
        cout << *iter;
    }
}