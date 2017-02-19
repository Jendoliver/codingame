#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
float detora(float x); // Degrees to Radians
float stofwcom(string in); // String to Float with Comma
float getX(float lonA, float lonB, float latA, float latB);
float getY(float latA, float latB);
float getDist(float x, float y);
vector<string> getInfo(string src); // Puts the info of the string on different positions of a vector

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
    
    vector<vector<string>> info;
    float dist;
    float mindist = 1000000;
    int index;
    for (int i = 0; i < N; i++) 
    {
        string DEFIB;
        getline(cin, DEFIB);
        info.push_back(getInfo(DEFIB));
        dist = getDist(getX(lon,stofwcom(info[i][4]),lat,stofwcom(info[i][5])),getY(lat,stofwcom(info[i][5])));
        if(dist < mindist)
        {
            mindist = dist;
            index = i;
        }
    }

    cout << info[index][1] << endl;
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

float detora(float x)
{
    return (x*2*M_PI)/360;
}

float getX(float lonA, float lonB, float latA, float latB)
{
    return (detora(lonB) - detora(lonA)) * (cos((detora(lonA) + detora(lonB)) / 2));
}

float getY(float latA, float latB)
{
    return (detora(latB) - detora(latA));
}

float getDist(float x, float y)
{
    return sqrt(pow(x,2)+pow(y,2)) * 6371;
}

vector<string> getInfo(string src)
{
    vector<string> res;
    string buffer = "";
    for(int i=0; i<src.size(); i++)
    {
        if(src[i] == ';')
        {
            res.push_back(buffer);
            buffer = "";
        }
        else
            buffer += src[i];
    }
    res.push_back(buffer);
    return res;
}