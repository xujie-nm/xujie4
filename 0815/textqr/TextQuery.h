#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H 

#include <string>
#include <set>
#include <map>
#include <vector>


class TextQuery
{
    public:

        TextQuery(){};
        TextQuery(const std::string &filename);
        void readFile(const std::string &filename);
        std::string runQuery(const std::string &word) const;

        std::map<std::string, int >& get_word_map()
        { return wordMap_; }

    private:
        std::map<std::string, int > wordMap_;  //单词以及他们出现的行号;

};



#endif  /*TEXT_QUERY_H*/
