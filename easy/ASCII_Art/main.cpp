#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    transform(T.begin(), T.end(), T.begin(), ::toupper);
    for (int i = 0; i < H; i++) 
    {
        string ROW;
        getline(cin, ROW);
        for(int j = 0; j < T.size(); j++)
        {
            char c = T[j];
            int n = (int)c - 65;
            if(n > 25 || n < 0)
            {
                for(int k = 26*L; k < 26*L+L; k++)
                    cout << ROW[k];
            }
            else
            {
                for(int k = n*L; k < n*L+L; k++)
                    cout << ROW[k];
            }
        }
        cout << endl;
    }
}