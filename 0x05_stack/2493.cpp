#include<stack>
#include<iostream>
#include<vector>

using namespace std;

int arr[500001];

stack<int> S;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> v(N, 0);
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    for(int i=0; i<N; i++){
        while(!S.empty() && arr[i] > arr[S.top()]) S.pop();
        if(!S.empty()) v[i] = S.top()+1; // index set
        S.push(i);
    }
    for(size_t i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}