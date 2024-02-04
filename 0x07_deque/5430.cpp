#include<deque>
#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        string p;
        cin >> p;

        int num_array;
        cin >> num_array;

        string ans = "";
        deque<int> DQ;

        bool reverse = false;
        bool error = false;
        
        // array input
        string arr;
        cin >> arr;
        string tmp_val = "";
        for(int i=1; i<arr.length(); i++){
            if(arr[i]==',' || arr[i]==']'){
                if(tmp_val != ""){
                    DQ.push_back(stoi(tmp_val));
                }
                tmp_val = "";
            }
            else{
                tmp_val += arr[i];
            }
        }

        for(auto c: p){
            if(c == 'R'){
                reverse = !reverse;
            }
            if(c == 'D'){
                if(DQ.size()){
                    if(reverse) DQ.pop_back();
                    else DQ.pop_front();
                }
                else{
                    cout << "error";
                    error =true;
                    break;
                }
            }
        }
        if(!error){
            cout << "[";
            while(DQ.size()){
                if(reverse){
                    cout << DQ.back();
                    DQ.pop_back();
                }
                else{
                    cout << DQ.front();
                    DQ.pop_front();
                }
                if(!DQ.empty()) cout << ",";
            }
            cout << "]";
        }
        cout << "\n";
    }
}