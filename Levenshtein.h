#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <string>

using namespace std;

class Levenshtein
{
public:

    static int calculateDistance(
        const string& first,
        const string& second
    );

};

#endif