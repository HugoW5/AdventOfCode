/*
https://adventofcode.com/2022/day/3
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

void readInput(vector<string> &input);
string removeDuplicates(const string &str);

int main()
{
    vector<string> input;
    readInput(input);

    int sum = 0;

    for (size_t i = 0; i < input.size(); i++)
    {
        string dupes = "";

        string firstHalf, secondHalf = "";
        int half = input[i].length() / 2;
        firstHalf = input[i].substr(0, half);
        secondHalf = input[i].substr(half, input[i].length());

        for (char fh : firstHalf)
        {
            for (char sh : secondHalf)
            {
                if (fh == sh)
                {
                    dupes += sh;
                }
            }
        }
        string compressedDupes = removeDuplicates(dupes);

        for (int i = 0; i < compressedDupes.length(); i++)
        {
            int priority = (int)compressedDupes[i];
            if (priority < 97)
            {
                sum += (priority - 38);
            }
            if (priority >= 97)
            {
                sum += (priority - 96);
            }
        }
    }
    cout << "Total: " << sum << endl;
    return 0;
}

string removeDuplicates(const string &str)
{
    unordered_set<char> seen;
    string result;
    for (char ch : str)
    {
        if (seen.find(ch) == seen.end())
        {
            seen.insert(ch);
            result += ch;
        }
    }
    return result;
}
void readInput(vector<string> &input)
{
    string s;
    ifstream fs("input.txt");
    while (getline(fs, s))
    {
        input.push_back(s);
    }
}