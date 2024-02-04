#include <iostream>
#include <string>

using namespace std;

char dat[600003];
int pre[600003];
int nxt[600003];
int unused = 1;

int insert(int pos, char word){
    dat[unused] = word;
    pre[unused] = pos;
    nxt[unused] = nxt[pos];

    if(nxt[pos] != -1) pre[nxt[pos]] = unused;
    nxt[pos] = unused;
    int tmp = unused;
    unused++;
    return tmp;
}

int move_left(int pos){
    if (pre[pos] != -1)
        return pre[pos];
    else
        return pos;
}

int move_right(int pos){
    if (nxt[pos] != -1)
        return nxt[pos];
    else
        return pos;
}

int erase(int pos){
    if(pre[pos] == -1){
        return pos;
    }
    if(nxt[pos]!=-1) pre[nxt[pos]] = pre[pos];
    nxt[pre[pos]] = nxt[pos];
    // cursor position
    return pre[pos];
}

void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dat[0] = 'a';
    pre[0] = -1;
    nxt[0] = -1;

    string word;
    cin >> word;
    int pos = 0;
    for(char c: word){
        pos = insert(pos, c);
    }

    int iterate_num;
    cin >> iterate_num;

    for(int j=0; j<iterate_num; j++){
        char oper;
        cin >> oper;
        if(oper == 'L'){
            pos = move_left(pos);
        }
        else if(oper == 'D'){
            pos = move_right(pos);
        }
        else if(oper == 'B'){
            pos = erase(pos);
        }
        else if(oper == 'P'){
            cin >> oper;
            pos = insert(pos, oper);
        }
        // cout << pos << "\n";
    }
    traverse();
}