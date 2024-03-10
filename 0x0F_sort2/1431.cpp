#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string arr[52];
int N;

bool cmp(string a, string b){
    if(a.length() != b.length()) return a.length() < b.length();
    int a_sum = 0;
    int b_sum = 0;
    for(auto c: a){
        if(isdigit(c)) a_sum += c - '0';
    }
    for(auto c: b){
        if(isdigit(c)) b_sum += c - '0';
    }
    if(a_sum != b_sum) return a_sum < b_sum;
    return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin  >> arr[i];
    }
    sort(arr, arr+N, cmp);
    for(int i=0; i<N; i++){
        cout << arr[i] << "\n";
    }
}