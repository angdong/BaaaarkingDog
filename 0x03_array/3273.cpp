#include <iostream>

using namespace std;

int arr[100001];
bool occur[2000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // a1~an nums
    // ai + aj = x satisfying pair calculate
    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;

    int ans=0;

    for(int i=0; i<num; i++){
        if(x-arr[i] > 0 && occur[x-arr[i]]) ans++;
        occur[arr[i]] = true;
    }
    cout << ans;
}