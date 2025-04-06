/*

MERGE SORT
MAIN

urls:
https://www.programiz.com/dsa/merge-sort

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "List.cpp"
#include "AllLists.cpp"


using std::cout, std::vector, std::string;


int main(int argc, char* argv[]){

    vector<std::string> files = {"0.txt", "1.txt", "2.txt"};
    
    AllLists allLists(3, files);

    List merged = allLists.mergeLists();
    
    std::cout << "Merged list:\n";
    merged.printList();

    // Očekávaný výstup: 1 2 3 4 5 6 7 8 9
    vector<int> expected = {1,2,3,4,5,6,7,8,9};
    bool success = true;

    for (size_t i = 0; i < expected.size(); ++i) {
        if (merged.getAtIndex() != expected[i]) {
            std::cout << "Chyba na indexu " << i << ": ocekavano " << expected[i] 
                      << ", bylo " << merged.getAtIndex() << "\n";
            success = false;
        }
        merged.increaseIndex();
    }

    if (success) {
        std::cout << "✅ Test úspěšný!\n";
    } else {
        std::cout << "❌ Test selhal!\n";
    }


    return 0;
}


