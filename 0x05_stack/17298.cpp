#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v;
    vector<int> ans(N, -1);
    int i=0;
    while(i < N){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        i++;
    }
    // v -> array
    i = 0;
    stack<int> S;
    while(i < N){
        int j = i-1;
        if(S.empty()){}
        else{
            // not empty
            while(!S.empty()){
                // check previous value
                if(v[i] > S.top()){
                    while(ans[j] != -1){
                        // if there's no val
                        j--;
                    }
                    ans[j] = v[i];
                    S.pop();
                }
                else{
                    break;
                }
            }
        }
        S.push(v[i]);
        i++;
    }
    for(vector<int>::iterator i=ans.begin(); i!=ans.end(); i++){
        cout << *i << " ";
    }

}