#include "Cache_Manager.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Cache_Manager::Cache_Manager()
{
    for (int i = 0; i < NUM; i++) 
    {
        isFree_[i] = true;  
    }
}

void Cache_Manager::Insert_New(const string &key, const string &value)
{
    int i;
    for (i = 0; i < NUM; i++) 
    {
        if(isFree_[i] = true)
        {
            isFree_[i] = false;
            lock_[i].lock();
            cache_[i].insert_new(key, value);
            lock_[i].unlock();
            isFree_[i] = true;
            break;
        }
    }
   if(i == 4)
   {
        cout << "cache full" << endl;
        return;
   }

}

void Cache_Manager::Write_File(const string &filename)
{
   ofstream fos;
   fos.open(filename.c_str());
   if(!fos)
   {
        cout << "open fail" << endl;
        return ;
   }
   fos.close();

   for (int i = 0; i < NUM; i++) 
   {
        if(isFree_[i] == true) 
        {
            cache_[i].write_file(filename);
        }
   }
}

void Cache_Manager::Read_File(const string &filename)
{
    ifstream fis;
    fis.open(filename.c_str());
    if(!fis)
    {
        cout << "open fail" << endl;
    }
    for (int i = 0; i < NUM; i++) 
    {
        cache_[i].read_file(fis);   
    }
}

string Cache_Manager::Read_Cache(const string &key)
{
    string res;
    for (int i = 0; i < NUM; i++) 
    {
        if(isFree_[i] == true)
        {
            res = cache_[i].read_cache(key) ;
            if(res != string(""))
                return res;
        }
    }
}
