/*
https://adventofcode.com/2018/day/1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<string> readInput(string);
bool checkDupe(vector<int>, int);
int main()
{
    vector<string> input = readInput("input.txt");

    vector<int> numbers;

    int num = 0;
    numbers.push_back(num);

    while (true)
    {
        for (int i = 0; i < input.size(); i++)
        {
            num += stoi(input[i]);
            if (checkDupe(numbers, num))
            {
                break;
            }
            numbers.push_back(num);
        }
    }
    return 0;
}

bool checkDupe(vector<int> numbers, int value)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == value)
        {
            cout << "--->" << value << endl;
            exit(0);
            return true;
        }
    }
    return false;
}

vector<string> readInput(string path)
{
    vector<string> tmpText;
    // read file  stream
    ifstream fs(path);
    string line;
    // Read each line of the file stream
    while (getline(fs, line))
    {
        tmpText.push_back(line);
    }
    fs.close();

    return tmpText;
}
