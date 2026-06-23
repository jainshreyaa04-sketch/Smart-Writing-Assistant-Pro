#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <string>
#include <vector>
#include <unordered_map>

#include "Trie.h"
#include "Dictionary.h"
#include "Levenshtein.h"

using namespace std;

class SpellChecker
{
private:

    Trie trie;

    Dictionary dictionary;

    unordered_map<string,int> frequency;

    vector<string> history;

    int totalChecked = 0;
    int correctWords = 0;
    int incorrectWords = 0;

    void saveFrequency();
    void loadFrequency();

    void saveHistory();
    void loadHistory();

    vector<string> rankSuggestions(
        const vector<string>& words,
        const string& input
    );

public:

    SpellChecker();

    bool initialize();

    bool checkWord(const string& word);

    vector<string> autoComplete(
        const string& prefix
    );

    vector<string> getSuggestions(
        const string& word
    );

    void addCustomWord(
        const string& word
    );

    void recordSearch(
        const string& word
    );

    vector<string> getRecentSearches();

    int getWordFrequency(
        const string& word
    );

    int dictionarySize();

    Trie& getTrie();

    void updateStatistics(bool correct);

    int getTotalChecked();

    int getCorrectWords();

    int getIncorrectWords();

    double getAccuracy();
};

#endif