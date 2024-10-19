/*
https://adventofcode.com/2022/day/3#part2
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
void readInput(vector<string> &input);
string findShortest(vector<string> &s);
string findCommon(vector<string> &group);

int main()
{
    vector<string> input = {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg"};
    // readInput(input);

    for (int i = 0; i < input.size(); i += 3)
    {
        vector<string> group;
        for (int j = 0; j < 3; j++)
        {
            group.push_back(input[i + j]);
        }
        findCommon(group);
    }

    return 0;
}

string findCommon(vector<string> &group)
{
    char common;
    string shortest = findShortest(group);
    for (int i = 0; i < group.size(); i++)
    {
        char tmpC;
        int cCount = 0;
        if (group[i] != shortest)
        {
            for (int j = 0; j < shortest.length(); j++)
            {
                if (group[i].find(shortest[j]) != string::npos)
                {
                    
                    common = group[i][group[i].find(shortest[j])];
                }
            }
        }
    }

    for (int i = 0; i < common.size(); i++)
    {
        cout << common[i] << "-" << endl;
    }

    return "";
}
string findShortest(vector<string> &s)
{
    string shortest = s[0];
    for (string str : s)
    {
        if (str.length() < shortest.length())
        {
            shortest = str;
        }
    }
    return shortest;
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