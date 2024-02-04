#include<iostream>
#include<algorithm>

using namespace std;

int N;
long long cnt;
long long max_cnt;
long long val;
long long max_val;
long long arr[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    val = arr[0];
    max_val = arr[0];
    cnt++;
    max_cnt = cnt;
    for(int i=1; i<N; i++){
        if(val == arr[i]){
            cnt++;
            if(max_cnt < cnt){
                max_cnt = cnt;
                max_val = arr[i];
            }
        }
        else{
            cnt=1;
            val = arr[i];
        }
    }
    cout << max_val;
}