// 처음부터 토마토 다 익어 있음 -> 0
// 토마토가 모두 익지는 못함 -> -1
// 토마토가 익을 때 필요한 최소 날짜 출력
#include<iostream>
#include<queue>

using namespace std;

queue<pair<int,int>> Q;
#define X first
#define Y second

int N, M;
int tomato_box[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    int num_tomato = 0;
    int no_tomato = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int tmp;
            cin >> tmp;
            tomato_box[i][j] = tmp;
            if(tmp == -1){
                no_tomato++;
            }
            else if(tmp == 1){
                Q.push({i, j});
            }
        }
    }
    num_tomato = N * M - no_tomato;
    // already done
    if(Q.size() == num_tomato){
        cout << 0;
        return 0;
    }
    int last_val;
    while(!Q.empty()){
        num_tomato--; // got tomato
        pair<int, int> pos = Q.front();
        last_val = tomato_box[pos.X][pos.Y];
        Q.pop();

        for(int i: {0, 1, 2, 3}){
            int n_x = pos.X + dx[i];
            int n_y = pos.Y + dy[i];

            // out of range
            if(n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;

            // already done or cannot go
            if(tomato_box[n_x][n_y] != 0) continue;

            // can go further!
            tomato_box[n_x][n_y] = tomato_box[pos.X][pos.Y] + 1;
            Q.push({n_x, n_y});
        }
    }
    // exist not ripen tomato
    if(num_tomato) cout << -1;
    else{
        cout << last_val-1;
    }
}