#include<iostream>
#include<algorithm>

using namespace std;

int arr[100005];
int N, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    cin >> M;
    sort(arr, arr+N);
    while(M--){
        int target;
        cin >> target;
        cout << binary_search(arr, arr+N, target) << "\n";
    }
}