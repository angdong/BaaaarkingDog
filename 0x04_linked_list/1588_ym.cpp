#include <bits/stdc++.h>
using namespace std;

int N, K, len=0;

int pre[5001];
int nxt[5001];

vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i=1; i<=N; ++i){
        pre[i] = (i==1)? N: i-1;
        nxt[i] = (i==N)? 1: i+1;
    }
    len = N;

    int i = 1;
    for(int cur=1; len; cur=nxt[cur]){
        if(i==K){
            // eliminate
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            --len;
            i = 1;
            v.push_back(cur);
        }
        else{
            i++;
        }
    }
    cout << "<";
    for(size_t i=0; i<v.size(); ++i){
        cout << v[i];
        if(i<v.size()-1) cout << ", ";
    }
    cout<<">";
}