#include <bits/stdc++.h>
using namespace std;

// Define the number of bits for the integer
const int LN = 31; // Assuming a 32-bit integer, you can adjust as needed

struct node {
    node* child[2];
    int cnt = 0;
    node() {
        child[0] = NULL;
        child[1] = NULL;
    }
};

struct trie {
    node* root;
    
    trie() {
        root = new node;
    }

    // Destructor to free memory
    ~trie() {
        freeMemory(root);
    }

    void freeMemory(node* cur) {
        if (!cur) return;
        freeMemory(cur->child[0]);
        freeMemory(cur->child[1]);
        delete cur;
    }

    void insert(int n) {
        node* cur = root;
        for (int i = LN - 1; i >= 0; --i) {
            cur->cnt++;
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[x] == NULL) {
                cur->child[x] = new node;
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }

    void remove(int n) {
        node* cur = root;
        for (int i = LN - 1; i >= 0; --i) {
            cur->cnt--;
            int x = (n & (1 << i)) ? 1 : 0;
            cur = cur->child[x];
        }
        cur->cnt--;
    }

    // Optional: Check if a number exists in the trie
    bool exists(int n) {
        node* cur = root;
        for (int i = LN - 1; i >= 0; --i) {
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[x] == NULL || cur->child[x]->cnt == 0) {
                return false;
            }
            cur = cur->child[x];
        }
        return cur->cnt > 0;
    }
};

int main() {
    trie t;
    t.insert(10);
    t.insert(15);
    t.remove(10);

    cout << "Exists 10: " << t.exists(10) << endl; // Should output 0 (false)
    cout << "Exists 15: " << t.exists(15) << endl; // Should output 1 (true)

    return 0;
}
