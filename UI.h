#ifndef UI_H
#define UI_H

#include <string>

using namespace std;

class UI
{
public:

    void showWelcome();

    void showMenu();

    void showDivider();

    void showSuccess(
        const string& message
    );

    void showError(
        const string& message
    );

    void showInfo(
        const string& message
    );

    void showStatistics(
        int dictionarySize,
        int totalSearches
    );

    int getChoice();
};

#endif