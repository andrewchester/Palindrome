/*
*  Andrew Chester
*  C++ program that takes in a string and tells you if it's a palindrome
*
* Used code from: 
* http://www.cplusplus.com/reference/cstring/strtok/
* http://www.cplusplus.com/reference/cstring/strcmp/
*/

#include <iostream>
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
//Reverse string function
char * reverseString(char * str)
{
  char * newStr; //Create a char * pointer
  newStr = new char[strlen(str)]; //Initialize the pointer

  //For loop for reversing the characters in the array
  int j = 0;
  for(int i = strlen(str) - 1; i >= 0; i--)
  {
    newStr[j] = str[i];
    j++;
  }
  return newStr;
}

//A function to make the string lowercase
void makeLower(char * str)
{
  //Loops over str
  for(int i = 0; i < strlen(str); i++)
  {
    int asciiValue = (int)str[i]; //Get the ascii value of the character
    if(asciiValue >= 65 && asciiValue <= 90) //If it's uppercase
      str[i] = (char)(asciiValue + 32); //Make it lowercase by increasing the ascii value by 32
  }
}

int main()
{
  char sentence[80];
  
  cout << "Enter in your sentence to test: ";
  cin.get(sentence, 79); //Getting user input up to 79 characters then inserting null character(not sure if it automatically inserts it or not)
  sentence[80] = '\0';

  cin.clear(); //Clearing the input stream
  cin.ignore(100, '\n'); 
  
  char * str = seperateString(sentence); //Runs the seperateString method to remove spaces and other characters
  char * reversedStr = reverseString(str); //Reverses the string

  //Making strings lowercase
  makeLower(str);
  makeLower(reversedStr);

  //Compare the strings and tell the user if they're palindromes
  if(strcmp(str, reversedStr) == 0)
  {
    cout << "Palindrome." << endl;
  }
  else
  {
    cout << "Not a palindrome." << endl;
  }

  return 0;
}
