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
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        table[EXT] = MT;
    }
    for (int i = 0; i < Q; i++) 
    {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        string ext = getExt(FNAME);
        transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        if(table.find(ext) != table.end())
            cout << table[ext] << endl;
        else
            cout << "UNKNOWN" << endl;
    }
}

string getExt(string in)
{
    for(int i=in.size()-1; i>=0; i--)
    {
        if(in[i] == '.')
            return in.substr(i+1,in.size()-1);
    }
    return "NO_EXT";
}