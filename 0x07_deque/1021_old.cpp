#include <iostream>
#include<deque>

using namespace std;

deque<int> DQ;
int N;
int K;

int what_val(int idx, int q_size){
    if(idx <= 0){
        while(idx <= 0) idx+=q_size;
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        DQ.push_back(i+1);
    }
    cin >> K;
    int ans=0;
    int idx_calibrate = 0;
    for(int i=1; i<=K; i++){
        int now_value;
        cin >> now_value;
        if(DQ.size() == 1){
            break;
        }
        if(what_val(now_value+idx_calibrate, DQ.size())%DQ.size() == 1){}
        else{
            if(what_val(now_value+idx_calibrate, DQ.size())%DQ.size() > DQ.size()/2 + 1){
                // now position
                while(what_val(now_value+idx_calibrate, DQ.size())%DQ.size() != 1){
                    idx_calibrate++;
                    int back = DQ.back();
                    DQ.pop_back();
                    DQ.push_front(back);
                    ans++;
                    cout<<"here ";
                }
            }
            else{
                while(what_val(now_value+idx_calibrate, DQ.size())%DQ.size() != 1){
                    idx_calibrate--;
                    int front = DQ.front();
                    DQ.pop_front();
                    DQ.push_back(front);
                    ans++;
                    cout << idx_calibrate << DQ.size() << now_value;
                    cout<<"there! ";
                }
            }
            cout<<"\n";
        }
        idx_calibrate--;
        DQ.pop_front();
    }
    cout << ans;
}