#include<iostream>
#include<list>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    // each time, kth member kill
    list<int> people;
    for(int i=0; i<n; i++){
        // insert ith member
        people.push_back(i+1);
    }
    
    list<int>::iterator where = people.begin();
    cout << "<";
    while(n--){
        // for(list<int>::iterator it=people.begin(); it!=people.end(); it++){
        //    cout << *it << " ";
        // }
        // kill kth
        int t = k;
        // how many jump
        while(--t){
            // iterate t time
            if (where == people.end()){ // -1 4 -1
                where = people.begin();  // 1 X
            }
            where++; // 4 -1
        }
        if (where == people.end()) where = people.begin();
        if(n) cout << * where << ", ";
        else cout << * where << ">";
        where = people.erase(where);
    }
}