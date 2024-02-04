// 4 4
// ####
// #JF#
// #..#
// #..#
// 입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다.
// 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.

#include<iostream>
#include<queue>
#include<string>

using namespace std;

int maze[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    queue<pair<int, int>> Q_j;
    queue<pair<int, int>> Q_f;

    for(int i=0; i< R; i++){
        string maze_input;
        cin >> maze_input;
        for(int j=0; j<C; j++){
            if(maze_input[j] == '#') maze[i][j] = -1;
            if(maze_input[j] == 'J'){
                Q_j.push({i, j});
            }
            if(maze_input[j] == 'F'){
                Q_f.push({i, j});
                maze[i][j] = 1;
            }
        }
    }

    while(Q_f.size()){
        pair<int, int> pos = Q_f.front();
        Q_f.pop();

        for(int i=0; i<4; i++){
            int x_pos = pos.X + dx[i];
            int y_pos = pos.Y + dy[i];

            if(x_pos < 0 || x_pos >= R || y_pos < 0 || y_pos >= C) continue;
            // wall
            if(maze[x_pos][y_pos] == -1) continue;

            // fire update
            if(maze[x_pos][y_pos] == 0){
                maze[x_pos][y_pos] = maze[pos.X][pos.Y] + 1;
                Q_f.push({x_pos, y_pos});
            }
            // there's already fire
            else{
                if(maze[x_pos][y_pos] <= maze[pos.X][pos.Y] + 1){
                    continue;
                }
                else{
                    maze[x_pos][y_pos] = maze[pos.X][pos.Y] + 1;
                    Q_f.push({x_pos, y_pos});
                }
            }
        }
    }


    maze[Q_j.front().X][Q_j.front().Y] = 1;
    // for(int i=0; i<R; i++){
    //     for(int j=0; j<C; j++){
    //         cout << maze[i][j] << " ";

    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    while(Q_j.size()){
        pair<int, int> pos = Q_j.front();
        Q_j.pop();
        if(pos.X == R-1 || pos.Y == C-1 || pos.X == 0 || pos.Y == 0){
                cout << maze[pos.X][pos.Y];
                return 0;
        }

        for(int i=0; i<4; i++){
            int x_pos = pos.X + dx[i];
            int y_pos = pos.Y + dy[i];

            if(x_pos < 0 || x_pos >= R || y_pos < 0 || y_pos >= C) continue;
            if(maze[x_pos][y_pos] == -1) continue;

            // fire or already done
            if(maze[x_pos][y_pos] <= maze[pos.X][pos.Y] + 1 && maze[x_pos][y_pos] != 0) continue;

            // jihoon update
            maze[x_pos][y_pos] = maze[pos.X][pos.Y] +1;

            Q_j.push({x_pos, y_pos});
            if(x_pos == R-1 || y_pos == C-1 || x_pos == 0 || y_pos == 0){
                cout << maze[x_pos][y_pos];
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}