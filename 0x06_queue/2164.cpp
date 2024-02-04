#include<iostream>
#include<queue>

using namespace std;

queue<int> Q;

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        Q.push(i+1);
    }
    int ans;
    while(!Q.empty()){
        ans = Q.front();
        Q.pop();
        if(!Q.empty()){
            int now = Q.front();
            Q.pop();
            Q.push(now);
        }
    }
    cout << ans;
}