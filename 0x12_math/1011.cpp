#include<iostream>

using namespace std;

int T;

void solve(){
    int x, y;
    cin >> x >> y;
    int num_cnt = 0;
    int whole_cnt = 0;
    int tmp_numb=1;
    while(x != y){
        whole_cnt++;
        int diff = y-x;
        if(diff <= tmp_numb){
            break;
        }
        if(diff > tmp_numb && num_cnt >= 2){
            tmp_numb++;
            num_cnt=0;
        }
        x += tmp_numb;
        num_cnt++;
    }
    cout<<whole_cnt<<"\n";
    // 1 2 3 4 5
    // 13 -> 1 1 -> 2 2 -> 3 3 -> (3/2/1)1남으면 어캄?
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        solve();
    }
}