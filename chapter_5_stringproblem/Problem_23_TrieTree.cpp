#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode{
    private:
        int path;
        int end;
        vector<TrieNode*> map;

    public:
        TrieNode()
        {
            path = 0;
            end = 0;
        }
        ~TrieNode(){}
};

class Trie{
    private:
        TrieNode* root;

    public:
        Trie()
        {
            root = new TrieNode();
        }

        ~Trie()
        {
            delete root;
        }

        void insert(string word)
        {
            if(word.empty())
                return;

            TrieNode* node = root;
            int index = 0;
            for(int i = 0; i < word.size(); i++)
            {
                index = word[i] - 'a';
                if(node.map[index] == NULL)
                {
                    node.map[index] = new TrieNode();
                }
                node = node.map[index];
                node.path++;
            }
            node.end++;
        }
};

int main()
{
    return 0;
}
