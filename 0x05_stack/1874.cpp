#include<stack>
#include<iostream>
#include<vector>
using namespace std;

int arr[100001];
vector<char> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    stack<int> input_S;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        input_S.push(N-i);
    }
    // input_S 에서 하나씩 빼기(뺄 때는 S에 넣고, +추가하기)
    for(int i=0; i<N; i++){
        int now = arr[i];
        while(!input_S.empty() && now >= input_S.top()){
            v.push_back('+');
            S.push(input_S.top());
            input_S.pop();
        }
        if(now != S.top()){
            cout << "NO";
            return 0;
        }
        v.push_back('-');
        S.pop();
    }
    for(vector<char>::iterator i=v.begin(); i!=v.end(); i++){
        cout << *i << "\n";
    }
}