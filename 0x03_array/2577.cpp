#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int tmp = a*b*c;
    int res[10] = {};
    while(tmp > 0){
        res[tmp%10]++;
        tmp /= 10;
    }
    for(int a: res){
        cout << a << '\n';
    }
}