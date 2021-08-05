/*
Justin Garzione
Palindrome Exercise

This program will receive a user-inputted string,
remove all pre-specified, non alphanumeric characters,
attached the remaining characters into a new string,
and determine whether or not this string is a palindrome
with a boolean return.

*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
void tokenize(char* word);
bool palindrome(char* word);

int main()
{
    char forward[40] = {'\0'};
    
    //Get input String line from user
    cout << "Enter cstring: ";
    cin.getline(forward, sizeof(forward), '\n');

    //Remove all tokens
    tokenize(forward);

    //Print tokenized string
    cout << "\n-----Results-----";
    printf("\nThe tokenized string is: %s\n", forward);

    //See if it is a palindrome
    cout << "The string is a palindrome = " << boolalpha << palindrome(forward);
    cout << "\n-----------------\n";

}
void tokenize(char * word)
{
    char forward[40] = { '\0' };
    char* tokenptr = NULL;
    tokenptr = strtok(word, " .!?");

    //Take the passed-by-reference char array and move tokenized & lowercased to forward char array
    while (tokenptr != '\0')
    {
        strcat(forward, tokenptr);
        tokenptr = strtok('\0', " .!?");
    }
    int i = 0;
    while (forward[i] != '\0')
    {
        forward[i] = tolower(forward[i]);
        i++;
    }
    strcpy(word,forward);
}
bool palindrome(char* word)
{
    bool isDrome = false;
    char reverse[40] = { '\0' };

    //Take the passed-by-reference char array, place reverse into different char array, and compare
    strcpy(reverse, word);
    int len = strlen(reverse);
    int n = len - 1;
    for (int i = 0; i < (len / 2); i++)
    {
        swap(reverse[i], reverse[n]);
        n = n - 1;
    }
    if (strcmp(word, reverse) == 0)
    {
        isDrome = true;
    }
    return isDrome;
}


