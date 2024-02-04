#include<iostream>
#include<stack>

using namespace std;
stack<int> S;
stack<int> S2;
int N;
int main(){
    cin >> N;
    long int ans=0;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        int my_val=0;
        int dupl = 1;
        while(!S.empty() && tmp>=S.top()){
            int top_value=S.top();
            S.pop();
            if(tmp==top_value){
                dupl += S2.top();
            }
            my_val += S2.top(); // how many duplicates
            S2.pop();
        }
        if(!S.empty()) ans++;
        ans += my_val;
        S.push(tmp);
        S2.push(dupl);
    }
    cout << ans;
}