#include <iostream>
#include <string>
#include <vector>

using namespace std;
float stofwcom(string in); // String to Float with Comma
vector getInfo(string src); // Puts the info of the string on different positions of a vector

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    float lon = stofwcom(LON);
    string LAT;
    cin >> LAT; cin.ignore();
    float lat = stofwcom(LAT);
    int N;
    cin >> N; cin.ignore();
    
    vector info;
    float dist;
    float mindist = 1000000;
    int index;
    for (int i = 0; i < N; i++) 
    {
        string DEFIB;
        getline(cin, DEFIB);
        info = getInfo(DEFIB);
        dist = getDist(getX(),getY());
        if(dist < mindist)
        {
            mindist = dist;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}

float stofwcom(string in)
{
    for(int i=0; i<in.size(); i++)
    {
        if(in[i] == ',')
            in[i] = '.';
    }
    return stof(in);
}

float getX(float lonA, float lonB, float latA, float latB)
{
    
}

float getY(float latA, float latB)
{
    
}

float getDist(float x, float y)
{
    
}

vector getInfo(string src)
{
    vector res;
    string buffer = "";
    for(int i=0; i<src.size(); i++)
    {
        if(src[i] == ';')
            res.push_back(buffer);
        else
            buffer += src[i];
    }
    return res;
}