#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string toBinary(int x);

int main()
{
    string MESSAGE;
    string BINARY;
    getline(cin, MESSAGE);

    for(int i=0; i<MESSAGE.size(); i++)
    {
        BINARY += toBinary((int)MESSAGE[i]);
    }
    
    cerr << toUnary(BINARY) << endl;

    cout << BINARY << endl;
}

string toBinary(int x)
{
    string aux, res;
    
    do
    {
        aux += to_string(x % 2);
        x = x/2;
        
    } while(x > 1);
    
    aux += to_string(x % 2);
    
    for(int i = 0; i < aux.size(); i++)
    {
        res += aux[aux.size()-1-i];
    }
    
    cout << res << endl;
    return res;
}

string toUnary(string bin)
{
    string res;
    int i=0;
    while(i<bin.size())
    {
        if(bin[i])
        {
            res += "0 ";
            do
            {
                res += '0';
                i++;
            } while (bin[i+1] || bin.size());
            res += ' '; 
        }
        else
        {
            res += "00 ";
            do
            {
                res += '0';
                i++;
            } while (!bin[i+1] || bin.size());
            res += ' '; 
        }
    }
    return res;
}