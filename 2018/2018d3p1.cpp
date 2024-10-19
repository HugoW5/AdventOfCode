/*
https://adventofcode.com/2018/day/3
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FabricPiece
{
public:
    string Id;
    int Xpos;
    int Ypos;
    int Width;
    int Height;
    FabricPiece(int x, int y, int width_, int height_, string id_)
    {
        Id = id_;
        Xpos = x;
        Ypos = y;
        Width = width_;
        Height = height_;
    }
};

void calculateOverlaps(vector<FabricPiece> &pieces);
bool alreadyFound(string s, vector<string> &overlapingPostions);
void readInput(string path, vector<string> &inp);

vector<string> input;

int main()
{
    vector<FabricPiece> pieces;
    readInput("input.txt", input);
    for (int i = 0; i < input.size(); i++)
    {
        string s = input[i];
        // id
        string id = s.substr(1, s.find(" @") - 1);
        // get postions
        string pos = s.substr(s.find("@ ") + 1, s.find(':') - s.find("@ ") - 1);
        // x,y
        int x = stoi(pos.substr(0, pos.find(',')));
        int y = stoi(pos.substr(pos.find(',') + 1, pos.length()));
        // width, height
        string dimensions = s.substr(s.find(':') + 2, s.length());
        int width = stoi(dimensions.substr(0, dimensions.find('x')));
        int height = stoi(dimensions.substr(dimensions.find('x') + 1, dimensions.length()));
        // add objects to vector
        pieces.push_back(FabricPiece(x, y, width, height, id));
    }

    calculateOverlaps(pieces);

    return 0;
}

void calculateOverlaps(vector<FabricPiece> &pieces)
{
    // 107043

    vector<string> overlapingPostions;

    for (int i = 0; i < pieces.size(); i++)
    {
        for (int j = i + 1; j < pieces.size(); j++)
        {
            bool overlap = false;

            int iRight = pieces[i].Xpos + pieces[i].Width;
            int iBottom = pieces[i].Ypos + pieces[i].Height;

            int jRight = pieces[j].Xpos + pieces[j].Width;
            int jBottom = pieces[j].Ypos + pieces[j].Height;

            if (pieces[i].Xpos < jRight && iRight > pieces[j].Xpos)
            {
                if (pieces[i].Ypos < jBottom && iBottom > pieces[j].Ypos)
                {
                    overlap = true;
                }
            }
            if (overlap)
            {
                // x1 --> x2
                int overlapX1 = max(pieces[i].Xpos, pieces[j].Xpos);
                int overlapX2 = min(iRight, jRight);
                // y1 --> y2
                int overlapY1 = max(pieces[i].Ypos, pieces[j].Ypos);
                int overlapY2 = min(iBottom, jBottom);

                // find coordinates of overlaps
                string s;
                for (int x1 = overlapX1; x1 < overlapX2; x1++)
                {
                    s = "";
                    for (int y1 = overlapY1; y1 < overlapY2; y1++)
                    {
                        s = to_string(x1) + ',' + to_string(y1);
                        if (!alreadyFound(s, overlapingPostions))
                        {
                            overlapingPostions.push_back(s);
                        }
                    }
                }
            }
        }
    }

    cout << "Total: " << overlapingPostions.size() << endl;
}

bool alreadyFound(string s, vector<string> &overlapingPostions)
{
    for (int i = 0; i < overlapingPostions.size(); i++)
    {
        if (overlapingPostions[i] == s)
        {
            return true;
        }
    }
    return false;
}

void readInput(string path, vector<string> &inp)
{
    string s;
    ifstream fs(path);
    while (getline(fs, s))
    {
        inp.push_back(s);
    }
    fs.close();
}
