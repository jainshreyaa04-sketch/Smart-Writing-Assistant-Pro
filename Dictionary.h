#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include "Trie.h"

using namespace std;

class Dictionary
{
private:

    string dictionaryFile;

public:

    Dictionary(const string& filename);

    bool loadDictionary(
        Trie& trie
    );

    bool addWord(
        Trie& trie,
        const string& word
    );

    bool wordExists(
        Trie& trie,
        const string& word
    );

    int totalWords();

    bool exportDictionary(
        const string& outputFile
    );

    bool importDictionary(
        Trie& trie,
        const string& inputFile
    );
};

#endif