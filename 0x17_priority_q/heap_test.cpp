#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    sz++;
    heap[sz] = x;
    // 1 2 3 4 5
    int idx=sz;
    while(idx > 1 && heap[idx] < heap[idx/2]){
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }
}

int top(){
    return heap[1];
}

void pop(){
    // for(int i=1; i<=sz; i++){
    //     cout << heap[i] << " ";
    // }
    // cout << "\n";
    swap(heap[1], heap[sz]);
    sz--;
    int idx=1;
    while(2*idx<=sz){
        int new_idx = 2*idx;
        if(2*idx+1<=sz && heap[2*idx+1] < heap[2*idx]) new_idx = 2*idx+1;
        if(heap[idx] > heap[new_idx]){
            swap(heap[idx], heap[new_idx]);
            idx = new_idx;
        }
        else{
            break;
        }
    }
    // for(int i=1; i<=sz; i++){
    //     cout << heap[i] << " ";
    // }
    // cout << "\n";
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}