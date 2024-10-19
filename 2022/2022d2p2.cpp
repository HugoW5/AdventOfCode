/*
https://adventofcode.com/2022/day/2
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
void readInput(vector<string> &input);
int indexOf(char c, char array[3]);
void calculateOutcome(int &p, int *scorePtr);
int getCorresponding(int n, char opt);

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
        int p = indexOf(input[i][2], player);
        int o = indexOf(input[i][0], opponent);

        int *scorePtr = &score;
        calculateOutcome(p, scorePtr);
    }

    cout << "Score: " << score << endl;
    return 0;
}

void calculateOutcome(int &p, int *scorePtr)
{
    int tmpScore = 0;
    // lose
    if (p == 0)
    {
        tmpScore = getCorresponding(p, 'l');
    }
    // win
    if (p == 1)
    {
        *scorePtr += 6;
        tmpScore = getCorresponding(p, 'w');
    }
    // tie
    if (p == 2)
    {
        *scorePtr += 3;
        tmpScore = getCorresponding(p, 't');
    }
    *scorePtr += p;
}

int getCorresponding(int n, char opt)
{
    int tmpScore = n;
    switch (opt)
    {
    case 'l':
        tmpScore -= 1;
        if (tmpScore < 0)
        {
            tmpScore = 2;
        }
        break;
    case 'w':
        tmpScore += 1;
        if (tmpScore > 2)
        {
            tmpScore = 0;
        }
        break;
    case 't':
        tmpScore = n;
        break;
    }
    return tmpScore;
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