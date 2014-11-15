#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TextQuery.h"
using namespace std;

int main(int argc, const char *argv[])
{
    map<string, int> res;

    ifstream fin;
    fin.open("in.txt");

    if(!fin)
    {
        cout << "open in.txt fail" << endl;
        return 0;
    }
    string word;
    while(fin >> word)
    {
        ++res[word];
    }

    ofstream fos;
    fos.open("edict.txt");

    if(!fos)
    {
        cout << "open edict.txt fail" << endl;
        return 0;
    }

    for(map<string, int>::iterator it = res.begin(); it != res.end(); ++it)
    {
        fos << it->first << " "  << it->second << endl;   
    }

    fin.close();
    fos.close();


    return 0;
}
