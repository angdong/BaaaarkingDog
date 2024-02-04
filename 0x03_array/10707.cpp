#include <iostream>

using namespace std;
int arr[100];

int main(){
    int N, v, ans[201] = {};
    cin >> N;
    while(N--){
        int t;
        cin >> t;
        ans[t + 100]++;
    }
    cin >> v;
    cout << ans[v+100];
}