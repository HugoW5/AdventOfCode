/*
https://adventofcode.com/2018/day/1
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
    int num = 0;
    for (int i = 0; i < input.size(); i++)
    {
        // cast string to int
        num += stoi(input[i]);
    }
    cout << num << endl;
    return 0;
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
