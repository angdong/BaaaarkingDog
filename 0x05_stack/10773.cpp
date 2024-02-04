#include <stack>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<int> S;
    while(N--){
        int numb;
        cin >> numb;
        if(numb == 0) S.pop();
        else S.push(numb);
    }
    int ans = 0;
    while(!S.empty()){
        ans += S.top();
        S.pop();

    }
    cout << ans;
}