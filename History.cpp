#include "History.h"
#include <fstream>
#include <iostream>

History::History(const string& filename)
{
    historyFile = filename;
}

void History::load()
{
    searches.clear();

    ifstream file(historyFile);

    if (!file.is_open())
    {
        return;
    }

    string word;

    while (getline(file, word))
    {
        if (!word.empty())
        {
            searches.push_back(word);
        }
    }

    file.close();
}

void History::save()
{
    ofstream file(historyFile);

    if (!file.is_open())
    {
        return;
    }

    for (const string& word : searches)
    {
        file << word << endl;
    }

    file.close();
}

void History::addSearch(const string& word)
{
    searches.push_back(word);
    save();
}

vector<string> History::getHistory()
{
    return searches;
}

void History::clearHistory()
{
    searches.clear();
    save();
}

int History::totalSearches()
{
    return searches.size();
}