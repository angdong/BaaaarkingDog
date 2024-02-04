#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> in_S;
    stack<int> out_S;
    cin >> N;
    vector<int> v(N ,-1);
    int i=0;
    while(i<N){
        i++;
        int tmp;
        cin >> tmp;
        in_S.push(tmp);
    }

    while(N--){
        //
        int now = in_S.top();
        in_S.pop();
        if(!out_S.empty()){
            // not empty -> compare
            while(!out_S.empty() && now >= out_S.top()){
                // extract every time to align ascending order
                out_S.pop();
            }
            if(!out_S.empty()){
                v[N] = out_S.top();
            }
        }
        // first or not
        out_S.push(now);
    }
    for(auto a: v) cout << a << " ";
}