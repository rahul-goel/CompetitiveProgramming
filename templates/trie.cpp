#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
const int NIL = -1;

struct node{
   int count;
   int child[26];
   node(){
       count = 0;
       memset(child, NIL, sizeof(child));
   }
};

vector < node > data;

void insert_word(int head, string str){
    int cur = head;
    for(int i=0; i<(int)str.size(); i++){
        int child_index = str[i] - 'a';
        if(data[cur].child[child_index] == NIL){
            data[cur].child[child_index] = data.size();
            data.push_back(node());
        }
        cur = data[cur].child[child_index];
        data[cur].count++;
    }
}

int find_word(int head, string str){
    int cur = head;
    for(int i=0; i<(int)str.size(); i++){
        int child_index = str[i] - 'a';
        if(data[cur].child[child_index] == NIL)
            return 0;
        cur = data[cur].child[child_index];
    }
    return data[cur].count;
}

int main(){
    data.push_back(node());
    for(int i=0; i<10; i++){
        string str;
        cin >> str;
        insert_word(0, str);
    }
    for(int i=0; i<10; i++){
        string str;
        cin >> str;
        cout << find_word(0, str) << endl;
    }
    return 0;
}
