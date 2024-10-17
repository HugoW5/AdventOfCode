#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set> // For more efficient overlap tracking

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
void readInput(string path, vector<string> &inp);

vector<string> input;
unordered_set<string> overlapingPostions;
vector<FabricPiece> notOverlapped;

int main()
{
    readInput("input.txt", input);

    vector<FabricPiece> pieces;

    for (int i = 0; i < input.size(); i++)
    {
        string s = input[i];
        // id
        string id = s.substr(1, s.find(" @") - 1);
        // get positionss
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
    unordered_set<string> overlapPositions; // the overlapping positions

    vector<bool> overlapsDetected(pieces.size(), false); // track pieces that overlap

    for (int i = 0; i < pieces.size(); i++)
    {
        for (int j = i + 1; j < pieces.size(); j++)
        {
            bool overlap = false;

            int iRight = pieces[i].Xpos + pieces[i].Width;
            int iBottom = pieces[i].Ypos + pieces[i].Height;

            int jRight = pieces[j].Xpos + pieces[j].Width;
            int jBottom = pieces[j].Ypos + pieces[j].Height;

            if (pieces[i].Xpos < jRight && iRight > pieces[j].Xpos &&
                pieces[i].Ypos < jBottom && iBottom > pieces[j].Ypos)
            {
                overlap = true;

                // Mark both pieces as having overlaps
                overlapsDetected[i] = true;
                overlapsDetected[j] = true;

                // Calculate the coordinates of the overlap
                int overlapX1 = max(pieces[i].Xpos, pieces[j].Xpos);
                int overlapX2 = min(iRight, jRight);
                int overlapY1 = max(pieces[i].Ypos, pieces[j].Ypos);
                int overlapY2 = min(iBottom, jBottom);

                // Store the overlapping coordinates
                for (int x = overlapX1; x < overlapX2; x++)
                {
                    for (int y = overlapY1; y < overlapY2; y++)
                    {
                        string coord = to_string(x) + ',' + to_string(y);
                        overlapPositions.insert(coord); // Insert into set
                    }
                }
            }
        }
    }

    for (int i = 0; i < pieces.size(); i++)
    {
        if (!overlapsDetected[i])
        {
            notOverlapped.push_back(pieces[i]);
            cout << "Non-overlapping ID: " << pieces[i].Id << endl;
        }
    }

    cout << "Total overlapping squares: " << overlapPositions.size() << endl;
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
