/*
https://adventofcode.com/2018/day/4
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Time
{
public:
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    Time(int year, int month, int day, int hour, int minute)
    {
        Year = year;
        Month = month;
        Day = day;
        Hour = hour;
        Minute = minute;
    }
    string GetTime()
    {
        return to_string(Year) + "-" + to_string(Month) + "-" + to_string(Day) + " " + to_string(Hour) + ":" + to_string(Minute);
    }
};
class Guard
{
public:
    string Id;
    int sleepMinutes;
    vector<Time> TimeStamps;
    vector<string> Actions;
    Guard(string id_)
    {
        Id = id_;
    }
    void AddTime(string time)
    {
        int year = stoi(time.substr(1, 4));
        int month = stoi(time.substr(6, 2));
        int day = stoi(time.substr(9, 2));
        int hour = stoi(time.substr(12, 2));
        int minute = stoi(time.substr(15, 2));
        TimeStamps.push_back(Time(year, month, day, hour, minute));
    }
    void AddAction(string action)
    {
        Actions.push_back(action);
    }
};

bool isBefore(Time &t1, Time &t2);
bool isSorted(vector<Time> &time);

void sortTime(vector<Guard> &guards);
void readInput(string path, vector<string> &inp);

int main()
{
    vector<Guard> guards;
    vector<string> input;
    readInput("input.txt", input);

    int currentGuard = -1;
    for (int i = 0; i < input.size(); i++)
    {

        if (input[i].find('#') == 25)
        {
            // get id
            string tmpid = input[i].substr(26);
            tmpid = tmpid.substr(0, tmpid.find(' '));
            // add new guard
            currentGuard++;
            guards.push_back(Guard(tmpid));
        }
        else
        {
            // add time
            string time = input[i].substr(0, input[i].find(']') + 1);
            guards[currentGuard].AddTime(time);
            // add action
            string action = input[i].substr(input[i].find(']') + 2);
            action = action.substr(0, action.find(' '));
            guards[currentGuard].AddAction(action);
        }
    }

    cout << "Unsorted: " << endl;
    for (int i = 0; i < guards.size(); i++)
    {
        cout << guards[i].Id << ":{" << endl;
        for (int j = 0; j < guards[i].TimeStamps.size(); j++)
        {
            cout << guards[i].TimeStamps[j].GetTime() << " : " << guards[i].Actions[j] << endl;
        }
        cout << "}" << endl;
    }
    sortTime(guards);
    cout << "----------------------------" << endl;
    cout << "sorted: " << endl;
    for (int i = 0; i < guards.size(); i++)
    {
        cout << guards[i].Id << ":{" << endl;
        for (int j = 0; j < guards[i].TimeStamps.size(); j++)
        {
            cout << guards[i].TimeStamps[j].GetTime() << " : " << guards[i].Actions[j] << endl;
        }
        cout << "}" << endl;
    }

    return 0;
}
// checks if t1 was before t2
bool isBefore(Time &t1, Time &t2)
{
    // total minutes
    int t1Sum = 0;
    t1Sum += t1.Year * 365 * 24 * 60;
    t1Sum += t1.Month * 30 * 24 * 60;
    t1Sum += t1.Day * 24 * 60;
    t1Sum += t1.Hour * 60;
    t1Sum += t1.Minute;

    int t2Sum = 0;
    t2Sum += t2.Year * 365 * 24 * 60;
    t2Sum += t2.Month * 30 * 24 * 60;
    t2Sum += t2.Day * 24 * 60;
    t2Sum += t2.Hour * 60;
    t2Sum += t2.Minute;
    if (t1Sum > t2Sum)
    {
        return false;
    }
    return true;
}

void sortTime(vector<Guard> &guards)
{
    for (int i = 0; i < guards.size(); i++)
    {
        if (guards[i].TimeStamps.size() > 1)
        {

            while (!isSorted(guards[i].TimeStamps))
            {
                for (int j = 0; j < guards[i].TimeStamps.size() - 1; j++)
                {
                    if (isBefore(guards[i].TimeStamps[j + 1], guards[i].TimeStamps[j]))
                    {
                        // switch
                        Time tmpTime1 = guards[i].TimeStamps[j + 1];
                        Time tmpTime2 = guards[i].TimeStamps[j];

                        guards[i].TimeStamps[j] = tmpTime1;
                        guards[i].TimeStamps[j + 1] = tmpTime2;

                        string tmpAction1 = guards[i].Actions[j + 1];
                        string tmpAction2 = guards[i].Actions[j];

                        guards[i].Actions[j] = tmpAction1;
                        guards[i].Actions[j + 1] = tmpAction2;
                    }
                }
            }
        }
    }
}

bool isSorted(vector<Time> &time)
{
    if (time.size() <= 1)
    {
        return true;
    }

    for (int i = 0; i < time.size() - 1; i++)
    {
        if (!isBefore(time[i], time[i + 1]))
        {
            return false;
        }
    }
    return true;
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
