#include "TextQuery.h"
#include <stdio.h>
#include <echo/Exception.h>
#include <fstream>
#include <sstream>
using namespace std;

TextQuery::TextQuery(const string &filename)
{
    readFile(filename);
}

void TextQuery::readFile(const string &filename)
{
    ifstream in;
    in.open(filename.c_str());
    if(!in)
        throw Exception("open file fail");

    string word;
    int fq;
    while(in >>word >> fq )
    {
        wordMap_[word] = fq;
    }

}

string TextQuery::runQuery(const string &word) const
{
    string res;
    map<string, int >::const_iterator it;
    it = wordMap_.find(word);
    if(it == wordMap_.end())
    {
        char buf1[16];
        snprintf(buf1, sizeof buf1, "%d", 0);
        res = "word: " + word + " occur: " + buf1 + " times";

        return res;
    }
    else
    {
        char buf1[16];
        snprintf(buf1, sizeof buf1, "%d", it->second);
        res = "word: " + word + " occur: " + buf1 + " times";

        return res;
    }
}








