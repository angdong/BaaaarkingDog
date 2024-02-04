#include<bits/stdc++.h>
using namespace std;

deque<int> DQ;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N;
    for(int i=1; i<=N; i++) DQ.push_back(i);
    cin >> K;

    while(K--){
        int now_val;
        cin >> now_val;
        int tmp_ans=0;
        while(DQ.front() != now_val){
            DQ.push_back(DQ.front());
            DQ.pop_front();
            tmp_ans++;
        }
        ans += min(tmp_ans, int(DQ.size())-tmp_ans);
        DQ.pop_front();
    }
    cout << ans;
}