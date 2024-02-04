#include<iostream>
#include<deque>
#define X first
#define Y second

using namespace std;

int min_val(deque<pair<int, int>>& d, int i, int L){
    while(d.front().Y <= i-L ){
        // pop front
        d.pop_front();
    }
    return d.front().X;
}

void get_ascending_order(deque<pair<int, int>>& DQ, int tmp, int i){
    while(!DQ.empty() && DQ.back().X >= tmp) DQ.pop_back();
    DQ.push_back({tmp, i});
}

int N, L;
deque<pair<int, int>> DQ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // queue에 있을 수 있는 원소의 개수 -> 최대 L개
    cin >> N >> L;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        get_ascending_order(DQ, tmp, i);
        cout << min_val(DQ, i, L) << " ";
    }
}