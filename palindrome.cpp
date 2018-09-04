#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char * seperateString(char * str)
{
  char * strsubstring;
  char newSentence[80];
  strsubstring = strtok (str," ,.-");
  while (strsubstring != NULL)
  {
    strsubstring = strtok (NULL, " ,.-");
    strcat(newSentence, strsubstring);
  }

  str = newSentence;
  return str;
}

int main()
{
  char sentence[80];
  
  cout << "Enter in your sentence to test: ";
  cin.get(sentence, 80);

  cin.clear();
  cin.ignore(100, '\n');
  
  sentence = seperateString(sentence);

  cout << sentence << endl;

  return 0;
}
