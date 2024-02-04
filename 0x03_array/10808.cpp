#include <iostream>
#include <string>

using namespace std;

int main(){
    string my_word;
    cin >> my_word;
    int word_count[26] = {0,};
    for (int i=0; i<my_word.length(); i++){
        word_count[my_word[i] - 'a']++;
    }
    for(int i=0; i< sizeof(word_count) / sizeof(int); i++){
        cout << word_count[i] << ' ';
    }
}
