#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N, Pi;
    int mindif = 100000;
    vector<int> list;
    
    cin >> N; cin.ignore();
    for(int i = 0; i < N; i++)
    {
        cin >> Pi;
        list.push_back(Pi); cin.ignore();
    }
        
    sort(list.begin(), list.end());
    for(int i = 0; i < list.size()-1; i++)
    {
        if(list[i+1] - list[i] < mindif)
            mindif = list[i+1] - list[i];
    }
    cout << mindif << endl;
}