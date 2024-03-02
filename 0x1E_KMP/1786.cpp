#include<iostream>
#include<string>
#include<vector>

using namespace std;

string T, P;

vector<int> getPi(string p){
    int m = (int)p.size();
    int j = 0;
    vector<int> pi(m, 0);
    for(int i=1; i<m; i++){
        while(j>0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> KMP(string t, string p){
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)t.size();
    int m = (int)p.size();
    int j = 0;
    for(int i=0; i<n; i++){
        while(j>0 && t[i]!=p[j]){
            j = pi[j-1];
        }
        if(t[i] == p[j]){
            if(j==m-1){
                ans.push_back(i-m+1);
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ans;
}

int main(){
    getline(cin, T);
    getline(cin, P);
    auto matched = KMP(T, P);
    cout << (int)matched.size() << "\n";
    for(auto v: matched){
        cout << v+1 << " ";
    }
    return 0;
}