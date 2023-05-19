#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include "Dictionary.h"

using namespace std;

class ExtendedDictionary : public Dictionary
{
private:
	Word randomWord;
    int maxScore;

public:
    //Input:
    //none
    //
    //Output:
    //none
    //
    // Functionality:
    // prints all the palindrome words in the dictionary
    // 
    //Sebastian Lopez (03/05/2023)
    void printPalindromeWords();
    //Input:
    //none
    //
    //Output:
    //none
    //
    // Functionality:
    // ask the user for a word and prints all words in the dictionary that have the same last 3 letters as
    // the input word.
    // 
    //Sebastian Lopez (08/05/2023)
    void printRhymingWords()
    {
        vector<Word> dictionary = getWordsDictionary();
        // check if the dictionary is empty
        if (dictionary.empty() == true)
        {
            cout << "Dictionary is empty \n";
        }
        else
        {
            string userWord;
            while (true)
            {
                try
                {
                    //ask the user to enter a word with at least 3 letters
                    cout << "enter a word with 3 or more letters: ";
                    cin >> userWord;
                    if (userWord.length() >= 3)
                    {
                        break;
                    }
                    else
                    {
                        throw (userWord);
                    }

                }
                catch (string word)
                {
                    cout << "error: word must have at least 3 letters" << endl;
                }
                catch (...)
                {
                    cout << "error: invalid input" << endl;
                }

            }

            for (int i = 0; i < dictionary.size(); i++)
            {
                string word = dictionary[i].getName();
                int length = word.length();
                int userWordLength = userWord.length();
                bool isRhyming = true;

                //check if the last 3 leters of userWord and word match
                if (length >= 3)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        if (userWord.at(userWordLength - 1 - i) != word.at(length - 1 - i))
                        {
                            isRhyming = false;
                        }
                    }
                    // print the word if the last 3 letters match
                    if (isRhyming == true)
                    {
                        cout << word << endl;
                    }

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
    // Functionality:
    // The program will choose a random word and print it with the fourth word in the definition missing.
    // the program will ask the user to guess the missing word. If the user guesses the word correctly,
    // the program will add 10 to the user score and choose another random word. If the user's score is grater than
    // the maximun score, the program will update the maximun score. If the user fails to guess the word correctly,
    // the program will print the user's score and exit.
    // 
    //Sebastian Lopez (11/05/2023)
    void guessTheFourthWord() 
    {
        vector<Word> dictionary = getWordsDictionary();
        // check if dictionary is empty
        if (dictionary.empty() == true)
        {
            cout << "Dictionary is empty \n";
        }
        else
        {
            cout << "\n WELCOME TO THE GAME \n";
            int playerScore = 0;

            while (true)// loop till the the user fails to guess the word
            {
                while (true) // loop till the correct word has been chosen 
                {
                    //chose a random word from the dictionary 
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<> dis(0, dictionary.size() - 1);
                    int randomIndex = dis(gen);

                    //check if the word has more than 4 words in the definition
                    this->randomWord = dictionary[randomIndex];

                    int numberOfWords = countWords(dictionary[randomIndex].getDefinition());

                    if (numberOfWords >= 4)
                    {
                        break;
                    }

                }
                // print word name 
                cout << randomWord.getName() << endl;
                // print word definition with the fourth word as ____
                istringstream iss(randomWord.getDefinition());
                int count = 0;
                string word;
                string fourthWord;

                while (iss >> word) {
                    count++;
                    if (count == 4)
                    {
                        cout << "_____ ";
                        fourthWord = word;
                    }
                    else
                    {
                        cout << word << " ";
                    }
                }

                // ask user to guess the fourth word
                string userGuess;

                cout << endl << "Guess the missing word: ";
                cin >> userGuess;

                // check if the user guess is correct
                if (lower_string(userGuess) == fourthWord)
                {
                    cout << "\n CONGRATULATIONS \n"
                        << "You guessed the word correctly \n\n";
                    playerScore += 10;

                    // check if player score is grater that maxScore
                    if (playerScore > maxScore)
                    {
                        // make current playerScore the maxScore
						maxScore = playerScore;
                        cout << "YOU HAVE BEATEN THE MAXIMUM SCORE!!! \n" << endl;
					}

                }
                else
                {
                    cout << "\n WRONG ANSWER \n"
                        << "The correct answer is: " << fourthWord << endl
                        << "your score is: " << playerScore << endl;
                    break;
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
    // Functionality:
    // This function will help the user to find a word based on the information the user provides.
    // the system will ask the user for the word length, the letters that the word should have and the letters that the word should not have.
    // the user can also enter the letters that the word should have in a specific position.
    // the program then will print all the words that match the information provided by the user.
    // 
    //Sebastian Lopez (15/05/2023)
    void searchdle() 
    {
        vector<Word> dictionary = getWordsDictionary();
        // check if the dictionary is empty
        if (dictionary.empty() == true) 
        {
            cout << "Dictionary is empty \n";
        }
        else
        {
            string notInWord;
            string inWord;
            string wordLength;
            cout << "\n this programs is meant to help you to find a word based the information you provide \n";

            // check if the word length is valid lenth should be an int grater than 0
            while (true)
            {
                try
                {
                   
                    cout << "\nEnter the word's length :";
                    cin >> wordLength;

                    //ask user for the letters that the word should have
                    cout << "\nEnter the letters the word should have (please do enter only letters without spaces example 'hklx'): ";
                    cin >> inWord;
                    inWord = lower_string(inWord);

                    cout << "\nEnter the letters the word dont have (please do enter only letters without spaces example 'hklx') : ";
                    cin >> notInWord;
                    notInWord = lower_string(notInWord);


                    if (stoi(wordLength) > 0)
                    {
						break;
					}
                    else
                    {
						throw (wordLength);
					}

				}
                catch (int length)
                {
					cout << "error: word length must be an integer grater than 0" << endl;
				}
                catch (...)
                {
					cout << "error: invalid input" << endl;
				}

			}
            
            cout << "\n if you know the exact position of a letter please enter it, if you don't enter '_' :";
            string lettersPos;

            for (int i = 0; i < stoi(wordLength); i++)
            {
                string letter;
                cout << "\nletter" << i << ": ";
                cin >> letter;
                lettersPos += lower_string(letter);
                
                cout << lettersPos << endl;
            }


             
            for (int i = 0; i < dictionary.size(); i++)
            {
                string word = dictionary[i].getName();

                // check if the words have the same length	
                if (word.length() == stoi(wordLength))
                {
                    // check if the word has the same letters in the same position as the user input
					bool isSame = true;
                    for (int i = 0; i < stoi(wordLength); i++)
                    {
                        if (lettersPos.at(i) != '_')
                        {
                            if (word.at(i) != lettersPos.at(i))
                            {
								isSame = false;
							}
						}
					}
					//if the word has the same letters in the same position as the user input
                    if (isSame == true)
                    {
                        // check if the word has the letters that the user input
                        bool isInWord;

                        for (int i = 0; i < inWord.length(); i++)
                        {
                             isInWord = false;

                            for (int k = 0; k < word.length(); k++)
                            {
                                if (inWord.at(i) == word.at(k))
                                {
                                    isInWord = true;
                                }
                            }
                            // if one of the letters in not in word break;
                            if (isInWord == false) { break; };
                        }
                        // if isInword is true mening all letters are in word, print word
                        if (isInWord == true)
                        {
                            //check that the word dose not have the letters that the user input
                            bool isNotInWord = true;

                            for (int i = 0; i < notInWord.length(); i++)
                            {
                                for (int k = 0; k < word.length(); k++)
                                {
                                    if (notInWord.at(i) == word.at(k))
                                    {
                                        isNotInWord = false;
                                    }
                                }
                                
                            }
                            if (isNotInWord == true)
                            {
                                cout << word << endl;
                            }


                        }
                        
					}

				}

            }

        }

    }

};