#include<queue>
#include<iostream>

using namespace std;

int arr[502][502];
bool is_visit[502][502];

#define X first;
#define Y second;

int main(){
    int n, m;

    for(int i=0; i<502; i++){
        fill(is_visit[i], is_visit[i] + 501, false);
    }
    cin >> n >> m;
    queue<pair<int, int>> Q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            if(tmp==1) Q.push({i, j});
        }
    }
    int max_val = 0;
    int paint_num = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!Q.empty()){
        int x_pos = Q.front().Y;
        int y_pos = Q.front().X;

        Q.pop();
        if (is_visit[y_pos][x_pos]) continue;
        paint_num++;
        // cout << y_pos << ", " << x_pos << "\n";

        int tmp_val=1;
        queue<pair<int, int>> Q2;
        Q2.push({y_pos, x_pos});
        is_visit[y_pos][x_pos] = true;

        while(!Q2.empty()){
            int now_x = Q2.front().Y;
            int now_y = Q2.front().X;
            Q2.pop();
            // cout << "<" << now_y << ", " << now_x << ">" << "\n";
            for(int idx: {0, 1, 2, 3}){
                int tmp_x = now_x + dx[idx];
                int tmp_y = now_y + dy[idx];
                // cout << "[" << tmp_y << ", " << tmp_x << "]" << "\n";
                if(tmp_x < 0 || tmp_x >= m) continue;
                if(tmp_y < 0 || tmp_y >= n) continue;

                if(arr[tmp_y][tmp_x] != 1 || is_visit[tmp_y][tmp_x]){
                    continue;
                }
                else{
                    tmp_val++;
                    is_visit[tmp_y][tmp_x] = true;
                    Q2.push({tmp_y, tmp_x});
                }
            }
        }
        if(max_val < tmp_val) max_val = tmp_val;
    }
    cout << paint_num << "\n" << max_val;
}