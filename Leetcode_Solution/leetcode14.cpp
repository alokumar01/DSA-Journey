class Solution {
public:
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

    class Trie {
    private:
        TrieNode* root;
    public:
        Trie() { 
            root = new TrieNode(); 
        }

        void insert(string word) {
            TrieNode* curr = root;

            for (char c : word) {
                int idx = c - 'a';
                if (curr->children[idx] == NULL) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->isEnd = true;
        };

        string lcp() {
            string prefix = "";
            TrieNode* curr = root;
            while(true) {
                int cnt = 0, nextIdx = -1;
                for(int i=0; i<26; i++) {
                    if (curr->children[i] != NULL) {
                        cnt++;
                        nextIdx = i;
                    }
                }
                if(cnt != 1 || curr->isEnd)
                    break;

                prefix.push_back('a' + nextIdx);
                curr = curr->children[nextIdx];
            }
            return prefix;
        }
    };

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        Trie t;
        for (const string& word : strs) {
            t.insert(word);
        }
        
        return t.lcp();
    }
};

// Time complexity - O(N * L)
//Space complexity - O(N * L);

//Another approach
//use vertical or horizontal scanning to reduce the space complexity to O(1);