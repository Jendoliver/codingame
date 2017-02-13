#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define NUM_VALUES 27

using namespace std;
string convert(string magicPhrase);

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string magicPhrase;
    getline(cin, magicPhrase);
    string instructions = convert(magicPhrase);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    //cout << "+.>-." << endl;
    //cerr << instructions.length() << endl;
    cout << instructions << endl;
}

string convert(string magicPhrase)
{ // A: 65, Z: 90
    int x; //ASCII value
    string res = "";
    for (int i = 0; i < magicPhrase.length()-1; i++) // every shit but the last one
    {
        x = int(magicPhrase[i]);
        if(x == 32) // space
            res += ".>";
        else
        {
            x = x-64;
            for(int j = 0; j < x; j++)
                res += "+";
            res += ".>";
        }
    }
    x = int(magicPhrase[magicPhrase.length()-1]);
    if(x == 32) // space
        res += ".";
    else
    {
        x = x-64;
        for(int j = 0; j < x; j++)
            res += "+";
        res += ".";
    }
    return res;
}

/*string convert(string magicPhrase)
{
    // Space: 32 (but 64), A: 65, Z: 90
    int lastx, x, dx; //ASCII value
    string res = "";
    cerr << "pasa naf" << endl;
    x = int(magicPhrase[0]);
    if(x == 32) // space
        x = 64;
    dx = x - lastx;
    if(dx > 0)
    {
        cerr << "pasa naf 2" << endl;
        if(dx > 13)
            {
                cerr << "pasa naf dx > 13" << endl;
                for(int k = 0; k < (NUM_VALUES - dx); k++)
                    res += "-";
            }
        else
        {
            cerr << "pasa naf else" << endl;
            for(int j = 0; j < dx; j++)
                res += "+";
        }
    }
    else if(dx < 0)
    {
        cerr << "pasa naf dx < 0" << endl;
        if(dx < -13)
        {
            for(int k = 0; k < (NUM_VALUES - dx*(-1)); k++)
                res += "+";
        }
        else
        {
            for(int j = 0; j > dx; j--)
                res += "-";
        }
    }
    res += ".";
    lastx = x;
    for (int i = 0; i < magicPhrase.length(); i++)
    {
        x = int(magicPhrase[i]);
        if(x == 32) // space
            x = 64;
        dx = x - lastx;
        if(dx > 0)
        {
            cerr << "pasa naf 2" << endl;
            if(dx > 13)
                {
                    cerr << "pasa naf dx > 13" << endl;
                    for(int k = 0; k < (NUM_VALUES - dx); k++)
                        res += "-";
                }
            else
            {
                cerr << "pasa naf else" << endl;
                for(int j = 0; j < dx; j++)
                    res += "+";
            }
        }
        else if(dx < 0)
        {
            cerr << "pasa naf dx < 0" << endl;
            if(dx < -13)
            {
                for(int k = 0; k < (NUM_VALUES - dx*(-1)); k++)
                    res += "+";
            }
            else
            {
                for(int j = 0; j > dx; j--)
                    res += "-";
            }
        }
        res += ".";
        lastx = x;
    }
}*/