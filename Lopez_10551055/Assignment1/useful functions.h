#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string lower_string(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')    //checking for uppercase characters
            str[i] = str[i] + 32;         //converting uppercase to lowercase
    }
    //cout << "\n The string in lower case: \n" << str;
    return str;
}
//
string returnType(string type)
{
    if (type == "v")
    {
        return "verb";
    }
    else if (type == "n")
    {
        return "noun";
    }
    else if (type == "a")
    {
        return "adjective";
    }
    else if (type == "adv")
    {
        return "adverb";
    }
    else if (type == "adj")
    {
        return "adjetive";
    }
    else if (type == "prep")
    {
        return "preposition";
    }
    else if (type == "pn")
    {
        return "proper noun";
    }
    else if (type == "n_and_v")
    {
        return "this word is a noun and a verb";
    }
    else if (type == "misc")
    {
        return "other words e.g. 'shh','and','but'";
    }
    else
    {
        return type;
    }
}

//returs the number of words in a string. 
int countWords(const string& str) {
    istringstream iss(str);
    int count = 0;
    string word;

    while (iss >> word) {
        count++;
    }

    return count;
}