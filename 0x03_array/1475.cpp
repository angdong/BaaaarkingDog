#include <iostream>
#include <string>

using namespace std;

int num_set[9];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // set => 0~9 exist
    // N <= 1,000,000
    // 6 can be 9 and vice versa!

    // normal case
    string number;
    cin >> number;
    for (auto c: number){
        num_set[c - '0']++;
    }
    num_set[6] += num_set[9];
    if (num_set[6] % 2 == 0){
        //
        num_set[6] /= 2;
    }
    else{
        num_set[6] /= 2;
        num_set[6]++;
    }
    int max_num = -1;
    for (int i=0; i<9; i++){
        if (num_set[i] > max_num){
            max_num = num_set[i];
        }
    }
    cout << max_num;
}