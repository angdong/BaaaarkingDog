#include<stack>
#include<iostream>

#define ll long long

using namespace std;

int numb;
ll h;

int main(){
    // largest histogram
    // 모인 높이의 합이 가장 큰 거를 구하기!
    int numb;
    while(true){
        cin >> numb;
        if(!numb) break;
        stack<ll> s;
        ll ans = numb; // first maximum numb
        while(numb--){
            ll h;
            cin >>h;
            s.push(h);
        }
        int cnt=0;
        ll min_val = 10000000001;
        while(numb--){
            
        }
        cout << ans;
    }
}