#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> extractString(string temps);
int findClosestToZero(vector<int> list);

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);
    vector<int> tlist; // The list of temperatures as integers
    tlist = extractString(temps);
    cout << findClosestToZero(tlist) << endl;
}

vector<int> extractString(string temps)
{
    vector<int> res; // Vector of the parsed temperatures
    string num = "";
    for(int i = 0; i < temps.length(); i++)
    {
        if(temps[i] == ' ') // Whitespace
        {
            res.push_back(atoi(num.c_str())); // Push the int value gathered from the string to the result vector
            cerr << num << endl;
            num = ""; // Restart the num buffer
        }
        else
            num += temps[i];
    }
    res.push_back(atoi(num.c_str()));
    return res;
}

int findClosestToZero(vector<int> list)
{
    int mindif = 5526; // Minimum difference between a value and 0
    int closest; // Closest temperature to 0
    for(int i = 0; i < list.size(); i++)
    {
        if(abs(list[i]) < mindif)
        {
            mindif = abs(list[i]);
            closest = list[i];
        }
        if(list[i] == mindif) // Case negatives
        {
            mindif = abs(list[i]);
            closest = list[i];
        }
    }
    return closest;
}