// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Word.h"
#include "Extended dictionary.h"
//#include "useful functions.h"
using namespace std;



int main()
{
    //Dictionary myDisctionary();
    ExtendedDictionary *myDictionary = new ExtendedDictionary();
    string fileName;
    string answer;
    int task;

    while(true)
    {
        
        cout << "Hello, What task do you want to perform?\n" << " type 1 for task1\n" << " type 2 for task2\n"
            << " type 3 for task3\n" << " type 4 for task4\n" << " type 5 for task5\n" << " type 6 for task6\n"
            << " type 7 for task7\n" << " type 8 for task8\n";
        if (!(cin >> task)) {
            cout << "Invalid input. Please enter an number.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
            continue; // Go back to the start of the loop
        }


        switch (task)
        {
        case 1:
            cout << "Task 1\n";

            
            //answer = lower_string(answer);


            while (true) 
            {
                // are user to choose typing a file name or use a defoult file name
                cout << "Do you want to use a defoult file name? (y/n) ";
                cin >> answer;

                if (answer == "y")
                {
                    fileName = "dictionary_2023S1.txt";
                    break;
                }
                else if (answer == "n")
                {
                    cout << "enter the file name : ";
                    cin >> fileName;
                    break;
                }
                else
                { 
                    cout << "Invalid input. Please enter y or n.\n";
                    cin.clear(); // Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
                    continue; // Go back to the start of the loop
                }

            }
            
            myDictionary->setFileName(fileName);//setFileName(fileName);
            myDictionary->loadDictionary();
            break;

        case 2:
            cout << "Task 2\n";
            myDictionary->searchWord();
            break;
        case 3:
            cout << "Task 3\n";
            myDictionary->wordsWithMoreThan3Z();
            break;
        case 4:
            cout << "Task 4\n";
            myDictionary->addWord();
            break;
        case 5:
            cout << "Task 5\n";
            myDictionary->printPalindromeWords();
            
            break;
        case 6:
            cout << "Task 6\n";
            myDictionary->printRhymingWords();
            break;
        case 7:
            cout << "Task 7\n";
            myDictionary->guessTheFourthWord();
            
            break;
        case 8:
            cout << "Task 8\n";
            myDictionary->searchdle();
            break;
        default:
            cout << "Invalid task\n";
            // ask for input again
            cout << task;
            break;

        }
    } 
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
