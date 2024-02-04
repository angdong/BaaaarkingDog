#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int student[2][6];
    for (int i=0; i<2; i++){
        fill(student[i], student[i] + 6, 0);
    }
    // for (int i=0; i<2; i++){
    //     for (int j=0; j<6; j++){
    //         cout << student[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int N, K;
    cin >> N >> K; // N: num(1 <= N <= 1,000), 
    // K: max num in a room(1< K <= 1,000)
    int ans = 0;
    for(int i=0; i<N; i++){
        // each student
        // sex and grade
        int sex, grade;
        cin >> sex >> grade;
        student[sex][grade-1]++;
        if (student[sex][grade-1] % K == 1)
            ans++;
    }
    cout << ans;
}