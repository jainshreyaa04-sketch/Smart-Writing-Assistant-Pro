#include "UI.h"
#include <iostream>

using namespace std;

void UI::showDivider()
{
    cout << "\n============================================================\n";
}

void UI::showWelcome()
{
    showDivider();

    cout << "          SMART WRITING ASSISTANT PRO\n";
    cout << "              Developed by Shreya Jain\n";

    showDivider();
}

void UI::showMenu()
{
    cout << "\nChoose an Option\n\n";

    cout << "1. Spell Check Word\n";
    cout << "2. Auto Complete\n";
    cout << "3. Add Custom Word\n";
    cout << "4. View Search History\n";
    cout << "5. Dictionary Statistics\n";
    cout << "6. Export Dictionary\n";
    cout << "7. Import Dictionary\n";
    cout << "8. Writing Analytics\n";
    cout << "9. Exit\n";

    cout << "\nEnter Choice : ";
}

void UI::showSuccess(const string& message)
{
    cout << "\n[SUCCESS] " << message << endl;
}

void UI::showError(const string& message)
{
    cout << "\n[ERROR] " << message << endl;
}

void UI::showInfo(const string& message)
{
    cout << "\n[INFO] " << message << endl;
}

void UI::showStatistics(
    int dictionarySize,
    int totalSearches)
{
    showDivider();

    cout << "Dictionary Size : "
         << dictionarySize << endl;

    cout << "Total Searches : "
         << totalSearches << endl;

    showDivider();
}

int UI::getChoice()
{
    int choice;

    cin >> choice;

    cin.ignore();

    return choice;
}