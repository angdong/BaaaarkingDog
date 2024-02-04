#include<iostream>
#include<cmath>

using namespace std;

int arr[2190][2190];

int N;

void solve(int n, int row, int col){
    if(n==3){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==1 && j==1) continue;
                arr[row+i][col+j] = 1;
            }
        }
        return;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1) continue;
            solve(n/3, row+i*(n/3), col+j*(n/3));
        }
    }
}

void print_star(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 0) cout << " ";
            else cout << "*";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve(N, 0, 0);
    print_star();
}