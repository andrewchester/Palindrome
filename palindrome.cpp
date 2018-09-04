/*
*  Andrew Chester
*  C++ program that takes in a string and tells you if it's a palindrome
*
* Used code from: 
* http://www.cplusplus.com/reference/cstring/strtok/
* http://www.cplusplus.com/reference/algorithm/reverse/
* http://www.cplusplus.com/reference/cstring/strchr/
*/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

//Function for removing spaces/puntuation, required a lot of fiddling to avoid segmentation fault errors
char * seperateString(char * str)
{
  char * substring; //Variable for the current substring
  char * newStr; //Initialize a pointer to a char array
  newStr = new char[80]; //Initialize that char array to avoid segmentation fault error by accessing memory you haven't allocated
  substring = strtok (str," ,.-!/(){};:"); //Split the string into tokens using common punctuation/characters as deliminators
  while (substring != NULL) //Continue looping through substring until all tokens have been seperated
  {
    strcat(newStr, substring); //Concatinate all the tokens onto newStr so that we get 1 cstring at the end
    substring = strtok (NULL, " ,.-!/(){};:");
  }
  return newStr; 
}

int main()
{
  char sentence[80];
  
  cout << "Enter in your sentence to test: ";
  cin.get(sentence, 79); //Getting user input up to 79 characters then inserting null character(not sure if it automatically inserts it or not)
  sentence[80] = '\0';

  cin.clear(); //Clearing the input stream
  cin.ignore(100, '\n'); 
  
  char * str = seperateString(sentence);
  char * reversedString = str;

  reverse(reversedString, strchr(reversedString, 0));

  cout << reversedString << endl;

  return 0;
}
