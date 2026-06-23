#include "Trie.h"

Trie::Trie()
{
    root = new TrieNode();
}

TrieNode* Trie::getRoot()
{
    return root;
}

void Trie::insertWord(const string& word)
{
    TrieNode* current = root;

    for(char ch : word)
    {
        if(current->children.find(ch) == current->children.end())
        {
            current->children[ch] = new TrieNode();
        }

        current = current->children[ch];
    }

    current->isEndOfWord = true;
}

bool Trie::searchWord(const string& word)
{
    TrieNode* current = root;

    for(char ch : word)
    {
        if(current->children.find(ch) == current->children.end())
        {
            return false;
        }

        current = current->children[ch];
    }

    return current->isEndOfWord;
}

bool Trie::startsWith(const string& prefix)
{
    TrieNode* current = root;

    for(char ch : prefix)
    {
        if(current->children.find(ch) == current->children.end())
        {
            return false;
        }

        current = current->children[ch];
    }

    return true;
}

void Trie::collectWords(
        TrieNode* node,
        string currentWord,
        vector<string>& suggestions)
{
    if(node->isEndOfWord)
    {
        suggestions.push_back(currentWord);
    }

    for(auto child : node->children)
    {
        collectWords(
            child.second,
            currentWord + child.first,
            suggestions
        );
    }
}

vector<string> Trie::autoComplete(const string& prefix)
{
    vector<string> suggestions;

    TrieNode* current = root;

    for(char ch : prefix)
    {
        if(current->children.find(ch) == current->children.end())
        {
            return suggestions;
        }

        current = current->children[ch];
    }

    collectWords(current, prefix, suggestions);

    return suggestions;
}