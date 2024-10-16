/*
https://adventofcode.com/2018/day/2
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
    int two = 0;
    int three = 0;

    for (int i = 0; i < input.size(); i++)
    {
        bool found2 = false;
        bool found3 = false;
        for (int j = 0; j < input[i].length(); j++)
        {
            int count = 0;
            char c = input[i][j];
            for (int k = 0; k < input[i].length(); k++)
            {
                if (c == input[i][k])
                {
                    count++;
                }
            }
            if (count == 2 && !found2)
            {
                two++;
                found2 = true;
            }
            if (count == 3 && !found3)
            {
                three++;
                found3 = true;
            }
        }
    }

    cout << "Checksum: " << two*three << endl;
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
