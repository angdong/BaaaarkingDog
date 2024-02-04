#include<iostream>
#include<queue>

using namespace std;
int road[100002];
// 메모리 초과...;;

int N, K;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    fill(road, road+100001, 0);
    queue<int> Q;
    Q.push(N);

    while(road[K] == 0 && N!=K){
        int pos = Q.front();
        Q.pop();
        for(int i: {pos-1, pos+1, 2*pos}){
            if(i < 0 || i > 100000) continue;
            if(road[i] != 0 || i==N) continue;

            road[i] = road[pos]+1;
            Q.push(i);
        }
    }
    cout << road[K];
}