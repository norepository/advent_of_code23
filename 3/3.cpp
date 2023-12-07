#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool is_symbol(char value)
{

    if (value == '+' || value == '-' || value == '#' || value == '@' || value == '*' || value == '%' || value == '&' || value == '=' || value == '$' || value == '/')
        return true;
    else
        return false;
}

void foo(string current, string next, string previous, int &total, string last, string first)
{
    for (int i = (current.length() - 1); i >= 0; i--)
    {
        if (isdigit(current[i]))
        {
            int k = 1;
            while (i >= 0 && isdigit(current[i]))
            {
                if (current.compare(first) == 0)
                {
                    if ((i < current.length() - 1 && is_symbol(current[i + 1])) || (i > 0 && is_symbol(current[i - 1])) || is_symbol(next[i]) || (i < next.length() - 1 && is_symbol(next[i + 1])) || (i > 0 && is_symbol(next[i - 1])))
                    {
                        total += (current[i] - '0') * k;
                    }
                }
                else if (current.compare(last) == 0)
                {
                    if ((i < current.length() - 1 && is_symbol(current[i + 1])) || (i > 0 && is_symbol(current[i - 1])) || is_symbol(previous[i]) || (i < previous.length() - 1 && is_symbol(previous[i + 1])) || (i > 0 && is_symbol(previous[i - 1])))
                    {
                        total += (current[i] - '0') * k;
                    }
                }
                else
                {
                    if ((i < current.length() - 1 && is_symbol(current[i + 1])) || (i > 0 && is_symbol(current[i - 1])) || is_symbol(previous[i]) || (i < previous.length() - 1 && is_symbol(previous[i + 1])) || (i > 0 && is_symbol(previous[i - 1])) || is_symbol(next[i]) || (i < next.length() - 1 && is_symbol(next[i + 1])) || (i > 0 && is_symbol(next[i - 1])))
                    {
                        total += (current[i] - '0') * k;
                    }
                }
                k *= 10;
                i--;
            }
        }
    }
}

int main()
{
    ifstream inputFile;
    inputFile.open("data.txt");

    if (!inputFile.is_open())
    {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    string line;
    string lines[141];
    int total = 0, i = 0;
    while (inputFile >> line)
    {
        lines[i] = line;
        i++;
    }
    for (int i = 0; i < 140; i++)
    {
        foo(lines[i], lines[i + 1], lines[i - 1], total, lines[139], lines[0]);
        cout << endl;
    }
    cout << "Total: " << total << endl;

    inputFile.close();

    return 0;
}
