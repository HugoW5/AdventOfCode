/*
https://adventofcode.com/2022/day/1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readInput(vector<string> &input);

int main()
{
    vector<string> input;
    readInput(input);

    int top = 0;
    int current = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] != "")
        {
            current += stoi(input[i]);
        }
        else
        {
            if (current > top)
            {
                top = current;
            }
            current = 0;
        }
    }
    cout << top << endl;

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