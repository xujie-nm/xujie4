#include <iostream>
#include <string>
#include <vector>
#include "TextQuery.h"
using namespace std;

int main(int argc, const char *argv[])
{
    TextQuery qr("edict.txt");
    qr.readFile("cdict.txt");

    string word;

    while(1)
    {
        cout << "please input word: " << endl;
        cin >> word;
        cout << qr.runQuery(word) << endl;;
    
    }
    return 0;
}
