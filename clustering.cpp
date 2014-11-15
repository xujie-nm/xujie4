#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <stdlib.h>

using namespace std;

map<int, pair<float, float> > inital(const string &filename)
{
    ifstream in;
    in.open(filename.c_str());
    string line;
    int ID = 0;
    map<int, pair<float, float> > inital1;
    while(getline(in, line))
    {
        string str_x = "";
        string str_y = "";
        bool is_x = false;
        bool is_y = false;
        for (int i = 0; i < line.size(); i++) 
        {
            if(line[i] == '=' && line[i - 1] == 'x')
            {
                is_x = true;
                is_y = false;
            }
            else if(line[i] == '=' && line[i - 1] == 'y')
            {
                is_x = false;
                is_y = true;
            }
            else if(line[i] == 'r')
            {
                is_x = false;
                is_y = false;
                break;
            }
            else if(line[i] == 'c')
            {
                is_x = false;
                is_y = false;
            }

            if(is_x && line[i] != '=')
            {
                str_x += line[i];
            }
            else if(is_y && line[i] != '=')
            {
                str_y += line[i];
            }

        }
        float x = atof(str_x.c_str());
        float y = atof(str_y.c_str());
        inital1.insert(make_pair(ID, make_pair(x, y)));
        ID++;
    }
    in.close();
    return inital1;
}

map<int, vector<int> > partition(map<int, pair<float, float> > &result1, int range)
{
    map<int, vector<int> > result2;
    
    for(map<int, pair<float, float> >::iterator it = result1.begin(); 
                                     it != result1.end(); ++it)
    {
        //cout << *it << endl;
        int x_sub = int(it->second.first) / range;
        int y_sub = int(it->second.second) / range;
        //cout << x_sub << "   " << y_sub << endl;
        int sqare_ID;
        if(x_sub * y_sub >= 0)
        {
           sqare_ID = x_sub * range * 100 + y_sub ;
        }
        else{
            if(x_sub < 0)
            {
               sqare_ID = -1 * x_sub * (range * 1000) + y_sub;
            }
            else
            {
                sqare_ID = x_sub * (range * 1000) - y_sub;
            }
        }
        result2[sqare_ID].push_back(it->first);
    }

    return result2;
    
}

int main(int argc, const char *argv[])
{
    map<int, pair<float, float> > result;
    result = inital("data.txt");
    
    map<int, vector<int> > result2;
    result2 = partition(result, 30);
    int sum = 0;
    int max = 0;
    int min = 0;

    ofstream out;
    out.open("result2.txt");
    for(map<int, vector<int> >::iterator it = result2.begin(); 
                                it != result2.end(); ++it)
    {
        sum += it->second.size();
        out << "Sqare_ID = " << it->first << "  numbers = " << it->second.size()  << endl;  
        if(it-> second.size() > max)
            max = it->second.size();
        
        if(it->second.size() <= 2)
        {
            ofstream out1;
            out1.open("First.txt", ios::app);
            for(vector<int>::iterator it_vec = it->second.begin(); it_vec != it->second.end(); ++it_vec)
            {
                out1 << result[*it_vec].first << " "
                    << result[*it_vec].second << endl;
            }
            out1.close();     
        }
        else if(it->second.size() <= 5)
        {
            ofstream out2;
            out2.open("Second.txt", ios::app);
            for(vector<int>::iterator it_vec = it->second.begin(); it_vec != it->second.end(); ++it_vec)
            {
                out2 << result[*it_vec].first << " "
                    << result[*it_vec].second << endl;
            }
            out2.close();     
        }
        else if(it->second.size() <= 9)
        {
            ofstream out3;
            out3.open("Third.txt", ios::app);
            for(vector<int>::iterator it_vec = it->second.begin(); it_vec != it->second.end(); ++it_vec)
            {
                out3 << result[*it_vec].first << " "
                    << result[*it_vec].second << endl;
            }
            out3.close();     
        }
        else if(it->second.size() <= 13)
        {
            ofstream out4;
            out4.open("Fourth.txt", ios::app);
            for(vector<int>::iterator it_vec = it->second.begin(); it_vec != it->second.end(); ++it_vec)
            {
                out4 << result[*it_vec].first << " "
                    << result[*it_vec].second << endl;
            }
            out4.close();     
        }
        else if(it->second.size() <= 17)
        {
            ofstream out5;
            out5.open("Fifth.txt", ios::app);
            for(vector<int>::iterator it_vec = it->second.begin(); it_vec != it->second.end(); ++it_vec)
            {
                out5 << result[*it_vec].first << " "
                    << result[*it_vec].second << endl;
            }
            out5.close();     
        }

    }    
    out << max << endl;
    out << sum << endl;
    return 0;
}
