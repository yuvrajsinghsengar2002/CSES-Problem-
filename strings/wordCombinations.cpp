#include <bits/stdc++.h>
using namespace std;

const int NMAX = 5e3;
const int MOD = 1e9 + 7;

struct node {
    node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void putKey(char ch, node* newNode) {
        links[ch - 'a'] = newNode;
    }

    node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }
};

class Trie {
private:
    node *root;

public:
    Trie() {
        root = new node();
    }

    void insert(string word) {
        node* nodePtr = root;
        for (char c : word) {
            if (!nodePtr->containsKey(c)) {
                nodePtr->putKey(c, new node());
            }
            nodePtr = nodePtr->get(c);
        }
        nodePtr->setEnd();
    }

    bool search(string word) {
        node* nodePtr = root;
        for (char c : word) {
            if (!nodePtr->containsKey(c)) {
                return false;
            }
            nodePtr = nodePtr->get(c);
        }
        return nodePtr->flag;
    }

    node* getRoot() {
        return root;
    }
};

int main() {
    string s;
    int n;
    cin >> s >> n;

    Trie trie;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    // dp[i] = how many ways can s[i..s.size()] be formed?
    vector<int> dp(s.size() + 1);
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        node* nodePtr = trie.getRoot();

        // Check if the s[i..j] is a word in the dictionary.
        for (int j = i; j < s.size(); j++) {
            // If the char doesn't exist in the trie break.
            if (!nodePtr->containsKey(s[j])) {
                break;
            }
            // Move to the next node.
            nodePtr = nodePtr->get(s[j]);

            /*
             * If nodePtr->flag is true then it's the end of a word.
             * Let's add to dp[i] the number of ways s[j+1...s.size()] can be
             * formed.
             */
            if (nodePtr->flag) {
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
    }

    cout << dp[0] << endl;
}
