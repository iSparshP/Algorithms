#include <bits/stdc++.h>
using namespace std;

struct node {
    node* child[26];
    int prefix;
    vector<string> wend;

    node() {
        prefix = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }

    ~node() {
        for (int i = 0; i < 26; i++) {
            if (child[i]) {
                delete child[i];
            }
        }
    }
};

struct trie {
    node* root;

    trie() {
        root = new node;
    }

    ~trie() {
        delete root;
    }

    void insert(string s) {
        node* cur = root;
        for (int i = 0; i < s.length(); i++) {
            cur->prefix++;
            int x = s[i] - 'a';
            if (cur->child[x] == NULL) {
                cur->child[x] = new node;
            }
            cur = cur->child[x];
        }
        cur->prefix++; // Increment at the end to indicate this node is the end of a word
        cur->wend.push_back(s);
    }

    bool search(string s) {
        node* cur = root;
        for (int i = 0; i < s.length(); i++) {
            int x = s[i] - 'a';
            if (cur->child[x] == NULL) {
                return false;
            }
            cur = cur->child[x];
        }
        return cur->prefix > 0; // Word exists if the end node has a prefix count
    }

    bool deleteWord(node* cur, string s, int depth = 0) {
        if (!cur) {
            return false;
        }

        if (depth == s.length()) {
            if (cur->prefix == 0) {
                return false;
            }

            cur->wend.clear();
            cur->prefix--;

            // Check if this node has any children
            for (int i = 0; i < 26; i++) {
                if (cur->child[i]) {
                    return false;
                }
            }

            return true;
        }

        int index = s[depth] - 'a';
        if (deleteWord(cur->child[index], s, depth + 1)) {
            delete cur->child[index];
            cur->child[index] = NULL;

            // If current node is not the end of any word and has no children
            return cur->prefix == 0 && cur->wend.empty();
        }

        return false;
    }

    void deleteWord(string s) {
        deleteWord(root, s);
    }
};

int main() {
    trie t;
    t.insert("hello");
    t.insert("hi");
    t.insert("her");
    t.insert("hero");
    t.insert("heros");

    cout << "Searching 'hero': " << (t.search("hero") ? "Found" : "Not Found") << endl;
    cout << "Searching 'heros': " << (t.search("heros") ? "Found" : "Not Found") << endl;

    t.deleteWord("hero");
    cout << "After deleting 'hero'" << endl;
    cout << "Searching 'hero': " << (t.search("hero") ? "Found" : "Not Found") << endl;
    cout << "Searching 'heros': " << (t.search("heros") ? "Found" : "Not Found") << endl;

    t.deleteWord("heros");
    cout << "After deleting 'heros'" << endl;
    cout << "Searching 'heros': " << (t.search("heros") ? "Found" : "Not Found") << endl;
    cout << "Searching 'her': " << (t.search("her") ? "Found" : "Not Found") << endl;

    return 0;
}
