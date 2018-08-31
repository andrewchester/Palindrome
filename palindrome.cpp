#include <iostream>

using namespace std;

int countPunctuationAndSpaces(char str[])
{
  int num = 0;

  for(int i = 0; i < sizeof(str); i++){
    int charValue = (int)str[i];
    if((charValue >= 33 && charValue <= 47) || (charValue >= 58 && charValue <= 64) || (charValue >= 91 && charValue <= 96) || (charValue >= 123 && charValue <= 126)){
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

  cout << "Number of spaces and punctuation: " << countPunctuationAndSpaces(sentence) << endl;
  return 0;
}
