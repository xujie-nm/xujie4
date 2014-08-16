#ifndef CACHE_MANSGER_H_
#define CACHE_MANSGER_H_
#include <echo/MutexLock.h>
#include "cache.h"

#define NUM 4

class Cache_Manager
{
    public:

        Cache_Manager();

        void Insert_New(const std::string &key, const std::string &value);
        void Write_File(const std::string &filename);
        void Read_File(const std::string &filename);

        std::string Read_Cache(const std::string &key);

    private:
        MutexLock lock_[NUM];
        Cache cache_[NUM];
        bool isFree_[NUM];

};

#endif  /*CACHE_MANSGER_H_*/
