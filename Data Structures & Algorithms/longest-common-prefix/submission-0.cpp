class Solution {
public:
    struct Node {
        map<char, Node*> nei;
        map<char, int> cnt;
        bool isend = false;
    };

    Node* root;

    void insert(string word) {
        Node* t = root;

        for (char x : word) {
            // Count how many words have x at this position
            t->cnt[x]++;

            if (t->nei.find(x) == t->nei.end()) {
                t->nei[x] = new Node();
            }

            t = t->nei[x];
        }

        t->isend = true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        root = new Node();

        int sz = strs.size();

        if (sz == 0)
            return "";

        for (auto& x : strs) {
            insert(x);
        }

        string ans = "";
        Node* t = root;

        while (t) {
            bool found = false;

            for (char x = 'a'; x <= 'z'; x++) {
                if (t->cnt[x] == sz) {
                    ans += x;
                    t = t->nei[x];
                    found = true;
                    break;
                }
            }

            if (!found)
                break;
        }

        return ans;
    }
};