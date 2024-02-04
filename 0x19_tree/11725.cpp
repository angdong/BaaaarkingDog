#include<bits/stdc++.h>
using namespace std;

vector<int> node[100004];
int p[100004];
int N;


void dfs(int cur){
    for(auto v: node[cur]){
        if(p[cur] == v)continue;
        p[v] = cur;
        dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        node[node1].push_back(node2);
        node[node2].push_back(node1);
    }
    dfs(1);
    for(int i=2; i<=N; i++) cout << p[i] << "\n";
}