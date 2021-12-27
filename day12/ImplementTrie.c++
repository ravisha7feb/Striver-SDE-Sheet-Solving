#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    //map<char, Trie*> next = {};
    Trie* next[26] = {NULL};
    bool isword = false;
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next[ch - 'a']) {
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next[ch - 'a']) { return false; }
            node = node->next[ch - 'a'];
        }
        return node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next[ch - 'a']) { return false; }
            node = node->next[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
    int n; //number of commands like insert, search or startsWith
    cin >> n;
    Trie obj;
    while(n --) {
        int c;//command - 0, 1, 2
        cout << "Enter 0 for insert, 1 for search and 2 for startsWith:  " ;
        cin >> c;
        string word;
        cout << "Enter the word: ";
        cin >> word;
        switch(c){
            case 0:
                obj.insert(word); break;
            case 1:
                cout << word << "--" << obj.search(word) << endl; break;
            case 2:
                cout << word << "--" << obj.startsWith(word) << endl; break;
        }
    }

    return 0;
}
