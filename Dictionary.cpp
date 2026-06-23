#include "Dictionary.h"

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Dictionary::Dictionary(const string& filename)
{
    dictionaryFile = filename;
}

bool Dictionary::loadDictionary(Trie& trie)
{
    ifstream file(dictionaryFile);

    if(!file.is_open())
    {
        cout<<"Error loading dictionary!"<<endl;
        return false;
    }

    string word;

    while(file>>word)
    {
        transform(
            word.begin(),
            word.end(),
            word.begin(),
            ::tolower
        );

        trie.insertWord(word);
    }

    file.close();

    return true;
}

bool Dictionary::addWord(
    Trie& trie,
    const string& word)
{
    if(trie.searchWord(word))
        return false;

    ofstream file(
        dictionaryFile,
        ios::app
    );

    if(!file.is_open())
        return false;

    file<<word<<endl;

    file.close();

    trie.insertWord(word);

    return true;
}

bool Dictionary::wordExists(
    Trie& trie,
    const string& word)
{
    return trie.searchWord(word);
}

int Dictionary::totalWords()
{
    ifstream file(dictionaryFile);

    if(!file.is_open())
        return 0;

    int count=0;

    string word;

    while(file>>word)
        count++;

    file.close();

    return count;
}

bool Dictionary::exportDictionary(
    const string& outputFile)
{
    ifstream input(dictionaryFile);

    if(!input.is_open())
        return false;

    ofstream output(outputFile);

    if(!output.is_open())
        return false;

    string word;

    while(input>>word)
    {
        output<<word<<endl;
    }

    input.close();
    output.close();

    return true;
}

bool Dictionary::importDictionary(
    Trie& trie,
    const string& inputFile)
{
    ifstream input(inputFile);

    if(!input.is_open())
        return false;

    ofstream output(
        dictionaryFile,
        ios::app
    );

    if(!output.is_open())
        return false;

    string word;

    while(input>>word)
    {
        if(!trie.searchWord(word))
        {
            trie.insertWord(word);

            output<<word<<endl;
        }
    }

    input.close();
    output.close();

    return true;
}