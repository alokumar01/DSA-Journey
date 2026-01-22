class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == NULL) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool dfs(string word, int idx, TrieNode* root) {
        if (!root) return false;
        if (idx == word.size()) return root->isEnd;

        char ch = word[idx];
        if (ch == '.') {
            for(int i=0; i<26; ++i) {
                if (dfs(word, idx + 1, root->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            return dfs(word, idx + 1, root->children[ch - 'a']);
        }
    }
    
    bool search(string word) {
        // TrieNode* curr = root;
        // int idx;
        // for(char c : word) {
        //     if (c == '.') {
        //         idx = 27;
        //     } else {
        //         idx = c - 'a';
        //     }

        //     if (curr->children[idx]) {
        //         return true;
        //     } else {
        //         curr->children[idx] == NULL) {
        //             return false;
        //         }
        //     }
        //     curr = curr->children[idx];
        // }
        
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

//APPROACH 

// [ Time taken: 1 hr 12 m 56 s ]
// In addWord function simple insert operation from trie data structure.

// and in search dot(.) working here is wild character so simple search like in trie will not work here so I have used here dfs:
// if wild is found then try all the possibilities and go in-depth and if that works then true otherwise false, 
// else wild char not found then simple like we do in search 