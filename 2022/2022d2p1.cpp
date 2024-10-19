/*
https://adventofcode.com/2022/day/2
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void readInput(vector<string> &input);
int indexOf(char c, char array[3]);

int main()
{
    // Rock Paper Scissors
    char opponent[3] = {'A', 'B', 'C'};
    char player[3] = {'X', 'Y', 'Z'};

    vector<string> input;
    readInput(input);

    int score = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        bool win = false;
        int p = indexOf(input[i][2], player);
        int o = indexOf(input[i][0], opponent);
        score += (p + 1);
        if (o == p)
        {
            score += 3;
        }
        if (o == 0 && p == 1)
        {
            win = true;
        }
        if (o == 1 && p == 2)
        {
            win = true;
        }
        if (o == 2 && p == 0)
        {
            win = true;
        }
        if (win)
        {
            score += 6;
        }
    }

    cout << "Score: " << score << endl;
    return 0;
}

int indexOf(char c, char array[3])
{
    for (int i = 0; i < 3; i++)
    {
        if (c == array[i])
        {
            return i;
        }
    }
    return -1;
}

void readInput(vector<string> &input)
{
    string s;
    ifstream fs("input.txt");
    while (getline(fs, s))
    {
        input.push_back(s);
    }
    fs.close();
}