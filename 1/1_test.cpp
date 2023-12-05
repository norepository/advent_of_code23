#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void first_part(string word, int &first, int &last, int &total)
{
  cout << word << endl;
  for (int i = 0; i < word.length(); i++)
  {
    if (isdigit(word[i]))
      last = word[i] - '0';
  }
  for (int i = word.length(); i >= 0; i--)
  {

    if (isdigit(word[i]))
      first = word[i] - '0';
  }
  cout << "First: " << first << endl;
  cout << "Last: " << last << endl;

  total = total + (first * 10) + last;
}

void second_part(string word, int &first, int &last, int &total)
{
  cout << word << endl;
  string A[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  for (int i = 0; i < word.length(); i++)
  {
    int foo = i;
    for (int j = 0; j < 10; j++)
    {
      for (int k = 0; k < A[j].length(); k++)
      {

        if (word[foo] != A[j][k])
        {
          last = word[i];
          break;
        }
        else
        {
          while (foo < word.length())
          {
            bool check = true;
            while (word[foo] == A[j][k])
            {
              check = false;
              foo++;
              k++;
            }
          }
        }
      }
    }
    cout << "Last: " << last << endl;
  }
}

void second_part(string word, int &first, int &last, int &total)
{
  cout << word << endl;
  string A[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  for (int i = 0; i < word.length(); i++)
  {
    bool check = true;
    for (int j = 0; j < 10; j++)
    {
      for (int k = 0; k < A[i].length(); k++)
      {
        if (word[i] == A[j][k])
        {
          for (int m = i + 1; m < word.length(); m++)
          {

          }
        }
      }
    }
  }
}

int main()
{
  // Open the file
  ifstream inputFile("data.txt");

  // Check if the file is open
  if (!inputFile.is_open())
  {
    cerr << "Unable to open file." << endl;
    return 1; // Return an error code
  }

  // Read each word from the file
  string word;
  int first, last;
  int total = 0;
  while (inputFile >> word)
  {

    second_part(word, first, last, total);
    cout << "Total: " << total << endl;
  }

  // Close the file
  inputFile.close();

  return 0; // Return success
}
