#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <string>

using namespace std;

class History
{
private:
    vector<string> searches;
    string historyFile;

public:

    History(const string& filename);

    void load();

    void save();

    void addSearch(const string& word);

    vector<string> getHistory();

    void clearHistory();

    int totalSearches();
};

#endif