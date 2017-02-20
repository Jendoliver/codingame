#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
string getExt(string in); // gets extension of the file

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    map<string, string> table;
    
    for (int i = 0; i < N; i++) 
    {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        cerr << "EXT ="+EXT << endl;
        cerr << "MT ="+MT << endl;
        table[EXT] = MT;
    }
    for (int i = 0; i < Q; i++) 
    {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        string lowext = getExt(FNAME);
        string upext = lowext;
        transform(lowext.begin(), lowext.end(), lowext.begin(), ::tolower);
        transform(upext.begin(), upext.end(), upext.begin(), ::toupper);
        if(table.find(lowext) != table.end())
            cout << table[lowext] << endl;
        else if(table.find(upext) != table.end())
            cout << table[upext] << endl;
        else
            cout << "UNKNOWN" << endl;
    }
}

string getExt(string in)
{
    for(int i=in.size()-1; i>=0; i--)
    {
        if(in[i] == '.')
        {
            cerr << in.substr(i+1,in.size()-1) << endl;
            return in.substr(i+1,in.size()-1);
        }
    }
    return "NO_EXT";
}