/*
https://adventofcode.com/2018/day/2#part2
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<string> readInput(string);

int main()
{
    vector<string> input = readInput("input.txt");
    vector<string> matches;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = i + 1; j < input.size(); j++)
        {
            string s;
            int count = 0;
            for (int k = 0; k < input[j].length(); k++)
            {
                if (input[i][k] == input[j][k])
                {
                    s += input[i][k];
                    count++;
                }
                else
                {
                    s += '-';
                }
            }
            if (count > 0)
            {
                matches.push_back(s);
            }
        }
    }

    string id;
    for (int i = 0; i < matches.size(); i++)
    {
        string s;
        for (int j = 0; j < matches[i].length(); j++)
        {
            if (matches[i][j] != '-')
            {
                s += matches[i][j];
            }
        }
        if (s.length() > id.length())
        {
            id = s;
        }
    }
    cout << id << endl;
    return 0;
}

vector<string> readInput(string path)
{
    vector<string> tmpText;
    string s;
    ifstream fs(path);
    while (getline(fs, s))
    {
        tmpText.push_back(s);
    }
    fs.close();
    return tmpText;
}
