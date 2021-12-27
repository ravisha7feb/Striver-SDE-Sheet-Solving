#include<bits/stdc++.h>
using namespace std;

class Trie{
    struct TrieNode{
        //vector<TrieNode*> nodes = vector<TrieNode*> (26, NULL); vector gave TLE so chose arrays
        TrieNode* nodes[26] = {NULL};
        bool isWord = false;
    };
    TrieNode* root ;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* tmp = root;
        for(char ch: word){
            if(!tmp->nodes[ch - 'a'])
                tmp->nodes[ch - 'a'] = new TrieNode() ;
            tmp = tmp->nodes[ch - 'a'];
        }
        tmp->isWord = true;
    }
    bool checkAllPref(string word){
        TrieNode* tmp = root;

        for(char ch: word){
            
            if(!tmp->nodes[ch - 'a']) return false;	
            tmp = tmp->nodes[ch - 'a'];
            if(!tmp->isWord) return false;
            
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    int maxLen = 0;
    string ans = "";
    Trie obj;
    for(string word: a){
        obj.insert(word);
    }
    for(string word: a){
        if(obj.checkAllPref(word)){
            if(maxLen < word.length()){
                maxLen = word.length();
                ans = word;
            }
            else if( maxLen == word.length() && ans > word)
                ans = word;
        }
    }
    if(maxLen == 0) return "None";
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << completeString(n, v) << endl;
    return 0;
}
