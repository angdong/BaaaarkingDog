#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

int main(){
    // priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10); pq.push(2); pq.push(5); pq.push(9);
    cout << pq.top() << '\n';
    pq.pop();
    cout << pq.size() << '\n';
    if(pq.empty()) cout << "PQ empty";
    else cout << "PQ not empty";
    pq.pop();
    cout << pq.top() << '\n';
    pq.push(5); pq.push(15);
    cout << pq.top() << '\n';
}