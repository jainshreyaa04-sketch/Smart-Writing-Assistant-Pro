#include "SpellChecker.h"

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

SpellChecker::SpellChecker()
    : dictionary("../data/dictionary.txt")
{
}

bool SpellChecker::initialize()
{
    loadFrequency();
    loadHistory();

    return dictionary.loadDictionary(trie);
}

bool SpellChecker::checkWord(const string& word)
{
    bool result = trie.searchWord(word);

    updateStatistics(result);

    return result;
}

vector<string> SpellChecker::autoComplete(
    const string& prefix)
{
    return trie.autoComplete(prefix);
}

vector<string> SpellChecker::rankSuggestions(
    const vector<string>& words,
    const string& input)
{
    vector<pair<int,string>> ranked;

    for(const string& word : words)
    {
        int distance =
            Levenshtein::calculateDistance(
                input,
                word
            );

        ranked.push_back(
            {distance, word}
        );
    }

    sort(
        ranked.begin(),
        ranked.end(),
        [](const pair<int,string>& a,
           const pair<int,string>& b)
        {
            if(a.first != b.first)
                return a.first < b.first;

            return a.second < b.second;
        }
    );

    vector<string> result;

    for(auto item : ranked)
    {
        result.push_back(item.second);

        if(result.size() == 5)
            break;
    }

    return result;
}

vector<string> SpellChecker::getSuggestions(
    const string& word)
{
    vector<string> words =
        trie.autoComplete(word);

    return rankSuggestions(words, word);
}

void SpellChecker::addCustomWord(
    const string& word)
{
    dictionary.addWord(trie, word);
}

void SpellChecker::recordSearch(
    const string& word)
{
    history.push_back(word);

    frequency[word]++;

    saveHistory();

    saveFrequency();
}

vector<string> SpellChecker::getRecentSearches()
{
    return history;
}

int SpellChecker::getWordFrequency(
    const string& word)
{
    if(frequency.find(word) == frequency.end())
        return 0;

    return frequency[word];
}

int SpellChecker::dictionarySize()
{
    return dictionary.totalWords();
}
void SpellChecker::saveFrequency()
{
    ofstream file("../data/frequency.txt");

    if(!file.is_open())
        return;

    for(const auto& item : frequency)
    {
        file << item.first
             << " "
             << item.second
             << endl;
    }

    file.close();
}

void SpellChecker::loadFrequency()
{
    ifstream file("../data/frequency.txt");

    if(!file.is_open())
        return;

    frequency.clear();

    string word;
    int count;

    while(file >> word >> count)
    {
        frequency[word] = count;
    }

    file.close();
}

void SpellChecker::saveHistory()
{
    ofstream file("../data/history.txt");

    if(!file.is_open())
        return;

    for(const string& word : history)
    {
        file << word << endl;
    }

    file.close();
}

void SpellChecker::loadHistory()
{
    ifstream file("../data/history.txt");

    if(!file.is_open())
        return;

    history.clear();

    string word;

    while(file >> word)
    {
        history.push_back(word);
    }

    file.close();
}

Trie& SpellChecker::getTrie()
{
    return trie;
}

void SpellChecker::updateStatistics(bool correct)
{
    totalChecked++;

    if(correct)
        correctWords++;
    else
        incorrectWords++;
}
int SpellChecker::getTotalChecked()
{
    return totalChecked;
}

int SpellChecker::getCorrectWords()
{
    return correctWords;
}

int SpellChecker::getIncorrectWords()
{
    return incorrectWords;
}

double SpellChecker::getAccuracy()
{
    if(totalChecked == 0)
        return 0.0;

    return (static_cast<double>(correctWords) * 100.0) / totalChecked;
}