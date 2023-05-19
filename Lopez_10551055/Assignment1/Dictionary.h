#include <iostream>
#include <string>
#include <fstream>
#include "useful functions.h"
using namespace std;

class Dictionary
{
private:
	string fileName;
	vector<Word> wordsDictionary;
    Word oneWord;

public:
    Dictionary(){};
	Dictionary(string fileName) { this->fileName = fileName; }
	void setFileName(string fileName) { this->fileName = fileName; }
	string getFileName() { return this->fileName; }
    vector<Word> getWordsDictionary () { return this->wordsDictionary; }
    //Input:
    //none
    //
    //Output:
    //none
    //
    // Functionality:
    // load the dictionary from the file which is this->fileName
    // 
    //Sebastian Lopez (11/03/2023)
	void loadDictionary()
	{

        long lineNumber;
        string record;
        string tag = "<word>";
        bool wordFound = false;
        long wordFoundlineNumber;


        cout << "Attempting to read text file...\n";

        ifstream myfile(this->fileName);
        wordsDictionary.clear();
        

        if (myfile.is_open())
        {
            wordFoundlineNumber = 0;
            lineNumber = 0;
            while (!myfile.eof())
            {
                getline(myfile, record);

                // if wordFound is true then the 3 next lines will fill name, definition and type
                if (wordFound == true)
                {
                    if (lineNumber == wordFoundlineNumber + 1)
                    {
                        oneWord.setName(record);
                        wordFound = true;
                    }
                    else if (lineNumber == wordFoundlineNumber + 2)
                    {
                        oneWord.setDefinition(record);
                        wordFound = true;
                    }
                    else if (lineNumber == wordFoundlineNumber + 3)
                    {
                        oneWord.setType(record);
                        wordFound = false;

                        wordsDictionary.push_back(oneWord);
                    }
                }



                if (record == tag)
                {
                    wordFoundlineNumber = lineNumber;
                    wordFound = true;

                }


                ++lineNumber;
            }
            myfile.close();
        }
        else 
        {
            cout << "Unable to open file \n";
            cout << "Please check the file name and try again, remamber to add '.txt' at the end of the file name \n";
        } 

	}
    //Input:
    // None
    // 
    //Output:
    //none
    //
    //Functionallity:
    // This function will ask the user to enter a word name, then the program will loop the dictionary
    // to look for the word that the user has entered, if the word has been found in the dictionary the
    // program will display the word name, type and description of the word as it is in the disctionary.  
    //
    //Sebastian Lopez (13/03/2023)
    void searchWord()
    {
        //if Dictionary is empty
        if (this->wordsDictionary.empty() == true)
        {
            cout << "Dictionary is empty \n";
        }
        else
        {
            string search;
            bool wordFound = false;

            cout << "please type the word you are looking for: ";
            cin >> search;
            search = lower_string(search);

            // loop the Dictionary to see if any name matches with 'search'  
            for (int i = 0; i < this->wordsDictionary.size(); i++)
            {
                
                if (this->wordsDictionary[i].getName() == search)
                {
                    wordFound = true; // if the word has been found, set 'wordFound' to 'true'

                    cout << "Name: " << this->wordsDictionary[i].getName() << "\n"
                        << "Type: " << "[" << returnType(this->wordsDictionary[i].getType()) << "]" << "\n"
                        << "Description: " << this->wordsDictionary[i].getDefinition() << "\n";

                }

            }

            // if the word was not found print "word not found"
            if (!wordFound)
            {
                cout << "Word not found" << endl;
            }

        }

    }
    //Input:
    // none
    //
    //Output:
    //none
    //
    //Functionallity:
    // this function will loop every word name in the dictionary to check how many cahracters "z"
    // there are in each word name, if the word has more than 3 or more it will be printed.
    //
    //Sebastian Lopez (16/03/2023)
    void wordsWithMoreThan3Z()
    {
        if (this->wordsDictionary.empty() == true)
        {
            cout << "Dictionary is empty \n";
        }
        else
        {
            for (int i = 0; i < this->wordsDictionary.size(); i++)
            {
                int numberOf_Z = 0; // this variable will track the number of "z" characters in a word
                int length = this->wordsDictionary[i].getName().length();
                string word = this->wordsDictionary[i].getName();

                for (int i = 0; i < length; i++)
                {
                    if (word.at(i) == 'z')
                    {
                        numberOf_Z++;
                    }

                }

                if (numberOf_Z > 3)
                {
                    cout << this->wordsDictionary[i].getName() << endl;
                }

            }
        }

    }
    //Input:
    //none
    //
    //Output:
    //none
    //
    //Functionallity:
    //This function allows the user to create a new word and add it to the Dictionary.
    // once the work has been added to the Dictionary, the program will ask the user to enter the name
    // of a new file, then the program will create a new file and write the Dictionary to the file.
    // 
    //Sebastian Lopez (22/03/2023)
    void addWord() 
    {
        if (this->wordsDictionary.empty() == true)
        {
            cout << "Dictionary is empty \n";
        }
        else
        {
            string name;
            string type;
            string definition;

            cout << "enter the word name: ";
            cin >> name;
            this->oneWord.setName(name);

            cout << "enter the word type: ";
            cin >> type;
            this->oneWord.setType(type);

            cout << "enter the definition : ";
            getline(cin >> ws, definition);
            this->oneWord.setDefinition(definition);

            bool wordFound = false;
            bool wordType = false;

            // if oneWord.type is equal to 'v', 'n', 'adv', 'prep' or 'pn' the type is valid   
            if (this->oneWord.getType() == "v" || this->oneWord.getType() == "n" || this->oneWord.getType() == "adv" || this->oneWord.getType() == "adj"
                || this->oneWord.getType() == "prep" || this->oneWord.getType() == "pn" || this->oneWord.getType() == "n_and_v" || this->oneWord.getType() == "misc")
            {
                wordType = true;
            }
            else
            {
                cout << "error: invalid word type, enter 'v','n', 'adv', 'adj', 'prep', 'pn', 'n_and_v' or 'misc'" << endl;
            }

            // loop the Dictionary to see if the word already exist
            for (int i = 0; i < this->wordsDictionary.size(); i++)
            {
                if (this->wordsDictionary[i].getName() == this->oneWord.getName())
                {
                    wordFound = true; // if the word has been found, set 'wordFound' to 'true'
                    cout << "error: word exist, elvated privileges required to edit existing words" << endl;

                }

            }

            // if the word does not exist and the type is valid then add the word to the Dictionary
            if (wordType == true && wordFound == false)
            {
                this->wordsDictionary.push_back(this->oneWord);

                //ask user for a new file name
                string fileName;

                cout << "enter a new file name with out the extention (.txt will be added automoatically) : ";
                cin >> fileName;

                //create a new file with the new fileName
                fstream file;

                file.open(fileName + ".txt", ios::app);


                if (file.is_open())
                {

                    // add the words from Dictionary to the new file 
                    for (int i = 0; i < this->wordsDictionary.size(); i++)
                    {
                        file << "<word>\n";
                        file << this->wordsDictionary[i].getName() << "\n";
                        file << this->wordsDictionary[i].getDefinition() << "\n";
                        file << this->wordsDictionary[i].getType() << "\n";
                        file << "</word>\n";
                    }

                    cout << "File created and data got written to file \n";

                }
                file.close();
            }
            
        }
    }

};

