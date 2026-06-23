#include <iostream>
#include <algorithm>

#include "SpellChecker.h"
#include "History.h"
#include "Dictionary.h"
#include "UI.h"

using namespace std;

int main()
{
    UI ui;

    SpellChecker spellChecker;

    Dictionary dictionary("../data/dictionary.txt");

    History history("../data/history.txt");

    if(!spellChecker.initialize())
    {
        ui.showError("Unable to load dictionary.");
        return 0;
    }

    history.load();

    ui.showWelcome();

    int choice;

    do
    {
        ui.showMenu();

        choice = ui.getChoice();

        switch(choice)
        {

        case 1:
        {
            string word;

            cout<<"\nEnter Word : ";

            cin>>word;

            transform(
                word.begin(),
                word.end(),
                word.begin(),
                ::tolower
            );

            history.addSearch(word);

            spellChecker.recordSearch(word);

            if(spellChecker.checkWord(word))
            {
                ui.showSuccess("Correct Spelling");
            }
            else
            {
                ui.showError("Incorrect Spelling");

                vector<string> suggestions =
                    spellChecker.getSuggestions(word);

                if(!suggestions.empty())
                {
                    cout<<"\nSuggestions\n\n";

                    for(string suggestion : suggestions)
                    {
                        cout<<"• "<<suggestion<<endl;
                    }
                }
            }

            break;
        }

        case 2:
        {
            string prefix;

            cout<<"\nEnter Prefix : ";

            cin>>prefix;

            vector<string> words =
                spellChecker.autoComplete(prefix);

            if(words.empty())
            {
                ui.showError("No Suggestions");
            }
            else
            {
                cout<<"\nAuto Complete\n\n";

                for(string word : words)
                {
                    cout<<"• "<<word<<endl;
                }
            }

            break;
        }

        case 3:
        {
            string word;

            cout<<"\nEnter New Word : ";

            cin>>word;

            transform(
                word.begin(),
                word.end(),
                word.begin(),
                ::tolower
            );

            spellChecker.addCustomWord(word);

            ui.showSuccess("Word Added");

            break;
        }

        case 4:
        {
            vector<string> searches =
                history.getHistory();

            cout<<"\nSearch History\n\n";

            for(string word : searches)
            {
                cout<<"• "<<word<<endl;
            }

            break;
        }

        case 5:
        {
            ui.showStatistics(
                spellChecker.dictionarySize(),
                history.totalSearches()
            );

            break;
        }

        case 6:
        {
            if(dictionary.exportDictionary(
                "../data/export_dictionary.txt"))
            {
                ui.showSuccess(
                    "Dictionary Exported"
                );
            }
            else
            {
                ui.showError(
                    "Export Failed"
                );
            }

            break;
        }

        case 7:
        {
            string filename;

            cout<<"\nEnter File Name : ";

            cin>>filename;

            if(dictionary.importDictionary(
                spellChecker.getTrie(),
                filename))
            {
                ui.showSuccess(
                    "Dictionary Imported"
                );
            }
            else
            {
                ui.showError(
                    "Import Failed"
                );
            }

            break;
        }

        case 8:
        {
            ui.showDivider();

            cout<<"WRITING ANALYTICS\n\n";

           cout<<"Dictionary Size : "
<<spellChecker.dictionarySize()
<<endl;

cout<<"Total Words Checked : "
<<spellChecker.getTotalChecked()
<<endl;

cout<<"Correct Words : "
<<spellChecker.getCorrectWords()
<<endl;

cout<<"Incorrect Words : "
<<spellChecker.getIncorrectWords()
<<endl;

cout<<"Accuracy : "
<<spellChecker.getAccuracy()
<<" %"<<endl;

cout<<"Search History : "
<<history.totalSearches()
<<endl;

            ui.showDivider();

            break;
        }

        case 9:
        {
            ui.showSuccess(
                "Thank You For Using Smart Writing Assistant"
            );

            break;
        }

        default:
        {
            ui.showError("Invalid Choice");
        }

        }

    }
    while(choice!=9);

    return 0;
}