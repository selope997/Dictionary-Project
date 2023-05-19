#include "Extended dictionary.h"

void printPalindromeWords()
{
    vector<Word> dictionary = getWordsDictionary();

    // check if dictionary is empty
    if (dictionary.empty() == true)
    {
        cout << "Dictionary is empty \n";
    }
    else
    {

        for (int i = 0; i < dictionary.size(); i++)
        {
            string word = dictionary[i].getName();
            int length = word.length();
            int numberOfIterations = floor(length / 2);
            bool isPalindrome = true;

            for (int l = 0; l < numberOfIterations; l++)
            {
                // check is the firsts and last characters are the same
                //if one of the letters is not the same, then the word is not a palindrome
                if (word.at(l) != word.at(length - 1 - l))
                {
                    isPalindrome = false;
                }

            }
            if (isPalindrome == true)
            {
                cout << word << endl;
            }

        }
    }