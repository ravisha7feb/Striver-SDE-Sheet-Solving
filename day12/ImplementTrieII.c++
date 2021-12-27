#include <bits/stdc++.h>
using namespace std;

class Trie {
    
    struct TrieNode {
        //TrieNode* nodes[26];
        int s = 26;
        vector<TrieNode*> nodes = vector<TrieNode*> (s, NULL);
        int word_cnt;
        int prefix_cnt;
        // Initialize your data structure here.
        TrieNode() {
            nodes.resize(sizeof(nodes), NULL);
            word_cnt = 0;
            prefix_cnt = 0;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                tmp->nodes[index] = new TrieNode();
            }
            tmp = tmp->nodes[index];
            tmp->prefix_cnt++;
        }
        tmp->word_cnt++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return 0;
            }
            tmp = tmp->nodes[index];
        }
        return tmp->word_cnt;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* tmp = root;
        for(char ch : prefix) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return 0;
            }
            tmp = tmp->nodes[index];
        }
        return tmp->prefix_cnt;
    }
    
    void erase(string word) {
        TrieNode* tmp = root;
        for(char ch: word){
            if(tmp->nodes[ch - 'a']){
                tmp = tmp->nodes[ch - 'a'];
                tmp->prefix_cnt--;
            }
            else{
                return;
            }
        }
        tmp->word_cnt--;
        tmp = NULL; //traversed the complete word so nullify it
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
int main()
{
    int n; //number of commands like insert, countWordsEqualTo etc
    cin >> n;
    Trie obj;
    while(n --) {
        int c;//command - 0, 1, 2
        cout << "Enter 0-insert, 1-countWordsEqualTo, 2-countWordsStartingWith and 3-erase:  " ;
        cin >> c;
        string word;
        cout << "Enter the word: ";
        cin >> word;
        switch(c){
            case 0:
                obj.insert(word); break;
            case 1:
                cout << word << "--" << obj.countWordsEqualTo(word) << endl; break;
            case 2:
                cout << word << "--" << obj.countWordsStartingWith(word) << endl; break;
            case 3:
                obj.erase(word);
                cout << word << " Erased" << endl; break;
            default:
                cout << "Invalid command" << endl;
        }
    }

    return 0;
}
