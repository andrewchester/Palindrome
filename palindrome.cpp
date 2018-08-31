#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int countPunctuationAndSpaces(char str[])
{
  int num = 0;

  for(int i = 0; i < strlen(str); i++){
    int charValue = (int)str[i];
    if((charValue >= 32 && charValue <= 47) || (charValue >= 58 && charValue <= 64) || (charValue >= 91 && charValue <= 96) || (charValue >= 123 && charValue <= 126)){
      cout << "Character identified: " << str[i] << endl;
      num++;
    }
  }
  return num;
}

int main()
{
  char sentence[80];
  
  cout << "Enter in your sentence to test: ";
  cin.get(sentence, 80);

  cout << "Sentence entered: " << sentence << endl;
  
  cout << "Number of spaces and punctuation: " << countPunctuationAndSpaces(sentence) << endl;
  return 0;
}
