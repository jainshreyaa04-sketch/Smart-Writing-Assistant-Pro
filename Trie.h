#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
private:
    TrieNode* root;

    void collectWords(TrieNode* node,
                      string currentWord,
                      vector<string>& suggestions);

public:
    Trie();

    void insertWord(const string& word);

    bool searchWord(const string& word);

    bool startsWith(const string& prefix);

    vector<string> autoComplete(const string& prefix);

    TrieNode* getRoot();
};

#endif