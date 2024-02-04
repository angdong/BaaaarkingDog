#include <iostream>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long int ans=0;
    stack<int> S;
    cin >> N;
    int current_build = 0;
    while(N--){
        int now;
        cin >> now;
        while(!S.empty() && now >= S.top()){
            current_build--;
            S.pop();
        }
        ans += current_build;
        S.push(now);
        current_build++;
        // cout << "Now [" << 6-N << "]" << current_build << "\n";
    }
    cout << ans;
}