#pragma once

#include "List.h"

#include <limits>


class AllLists{
    public:
        AllLists(int k, std::vector<std::string> filenames);
        ~AllLists();

        List mergeLists();
        size_t wholeSize();
        List getList(int index); 

    private:
        List* folder;
        unsigned int capacity;
        unsigned int count;

        static unsigned int defaultCapacity;

};