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

    int query_max(int n) {
        node* cur = root;
        long long int ans = 0;  // Use `long long int` for larger numbers
        for (int i = LN - 1; i >= 0; --i) {
            int x = (n & (1 << i)) ? 1 : 0;
            if (cur->child[1 ^ x] != NULL) { // Choose opposite branch if possible
                ans ^= 1 << i;
                cur = cur->child[1 ^ x];
            } else {
                cur = cur->child[x];
            }
        }
        return ans;
    }
};

int main() {
    trie t;
    t.insert(10);
    t.insert(15);
    t.insert(5);

    cout << "Max XOR with 10: " << t.query_max(10) << endl; // Should output max XOR value
    cout << "Max XOR with 15: " << t.query_max(15) << endl; // Should output max XOR value

    return 0;
}
