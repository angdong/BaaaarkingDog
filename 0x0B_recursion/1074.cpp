#include<iostream>
#include<cmath>

using namespace std;

int N, r, c;

// int recursive_search(int n, int row, int col, int numb){
//     if(n==0){
//         if(row==r && col==c){
//             cout << numb;
//         }
//         numb++;
//         return numb;
//     }
//     // <row,col> 0 x(row, col+2^(N-1)) 0
//     // 0         0 0 0
//     // x         0 x 0
//     // 0         0 0 0
//     int idx = pow(2, n-1);
//     numb = recursive_search(n-1, row, col, numb);
//     numb = recursive_search(n-1, row, col+idx, numb);
//     numb = recursive_search(n-1, row+idx, col, numb);
//     numb = recursive_search(n-1, row+idx, col+idx, numb);
//     return numb;
// }
int numb;

void get_pos(int n, int row, int col, int cnt){
    if(row==r && col==c){
        cout << cnt;
        return;
    }
    // find where pos?
    bool isup = (row + pow(2, n-1)) > r;
    bool isleft = (col + pow(2, n-1)) > c;
    if(isup){
        if(isleft){
            get_pos(n-1, row, col, cnt);
        }
        else{
            get_pos(n-1, row, col+pow(2, n-1), cnt+ pow(2, n-1) * pow(2, n-1));
        }
    }
    else{
        if(isleft){
            get_pos(n-1, row+pow(2, n-1), col, cnt+ 2 * pow(2, n-1) * pow(2, n-1));
        }
        else{
            get_pos(n-1, row+pow(2, n-1), col+pow(2, n-1), cnt+ 3 * pow(2, n-1) * pow(2, n-1));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r >> c;
    get_pos(N, 0, 0, 0);
    // recursive_search(N, 0, 0, 0);
}

// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 X 0 0 8개 무시 + 3개 무시 -> 11