/*

MERGE SORT
MAIN

urls:
https://www.programiz.com/dsa/merge-sort

*/

#include "List.h"
#include "AllLists.h"

#include <iostream>

using std::cout, std::vector, std::string;


int main(int argc, char* argv[]){

    vector<string> files;
    for(size_t i = 1;i < argc; i++){
        files.push_back(string("../test_data/") + argv[i] + ".txt");
    }

    AllLists allLists(argc - 1, files);

    List merged = allLists.mergeLists();
    
    cout << "-----MERGED LIST-----\n";
    merged.printList();

    merged.testMerge(files);
    


    return 0;
}

