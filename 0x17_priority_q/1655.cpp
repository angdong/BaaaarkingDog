#include<bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
int sz=0;

void push(int x){
    arr[++sz] = x;
    // 넣고 정렬 실시
    int idx=sz;
    while(idx > 1){
        if(arr[idx] < arr[idx/2]){
            int tmp = arr[idx/2];
            swap(arr[idx], arr[idx/2]);
            if(idx%2==1){
                // sort
                swap(arr[idx], arr[idx-1]);
            }
            idx/=2;
        }
        else break;
    }
    // 속해야 할 중간 노드까지 도달(여기서 또 정렬을 해야 함)
    // 1 1
    // 2 2 3
    // 3 4 5 6 7
    // 4 8 9 10 11 12 13 14 15
    int pow2=1;
    while(idx -2*pow2 >=0){
        pow2*=2;
    }
    sort(arr+pow2, arr+pow2*2);
}

int mid(int i){
    int idx = i%2==0? i/2: i/2+1;
    return arr[idx];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fill(arr, arr+100005, 10001);
    for(int i=1; i<=N; i++){
        int x;
        cin >> x;
        push(x);
        cout << mid(sz) << "\n";
        for(int j=1; j<=sz; j++){
            cout << "[" << arr[j] << "] ";
        }
        cout << "\n";
    }
}