/*
https://adventofcode.com/2022/day/1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void readInput(vector<string> &input);

int main()
{
    vector<string> input;
    readInput(input);
    vector<int> counted;
    int current = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] != "")
        {
            current += stoi(input[i]);
        }
        else
        {
            counted.push_back(current);
            current = 0;
        }
    }

    sort(counted.rbegin(), counted.rend());

    int topThree = counted[0] + counted[1] + counted[2];
    cout << topThree << endl;
    return 0;
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