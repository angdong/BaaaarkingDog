#include<queue>
#include<iostream>
#include<string>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;

int N, M;
int maze[102][102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            maze[i][j] = str[j] - '0';
            // cout << str[j] - '0';
        }
    }
    
    Q.push({0, 0});
    while(!Q.empty()){
        pair<int, int> pos = Q.front();
        // cout << pos.X << pos.Y;
        Q.pop();

        for(int i: {0, 1, 2, 3}){
            int x_cord = pos.X + dx[i];
            int y_cord = pos.Y + dy[i];
            // cout << "[" << pos.X << ", " << pos.Y << "]\n";
            
            if(x_cord < 0 || x_cord >= N) continue;
            if(y_cord < 0 || y_cord >= M) continue;
            if(maze[x_cord][y_cord] != 1 || (x_cord ==0) && (y_cord ==0)) continue;

            maze[x_cord][y_cord] = maze[pos.X][pos.Y] + 1;
            Q.push({x_cord, y_cord});
            if(x_cord == N-1 && y_cord == M-1){
                cout << maze[x_cord][y_cord];
                return 0;
            }
        }

    }
    
}