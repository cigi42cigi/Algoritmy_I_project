#pragma once

#include "List.h"

class AllLists{
    public:
        AllLists(int k,const std::vector<std::string> filenames);
        ~AllLists();

        List mergeLists();
        size_t wholeSize();
        List getList(const unsigned int index);

    private:
        List* folder;
        unsigned int capacity;
        unsigned int count;

        static unsigned int defaultCapacity;
};