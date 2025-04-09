#include "List.h"
#include "AllLists.h"

#include <iostream>

using std::cout, std::vector, std::string;

/**
 * @file main.cpp
 * @brief Spouštěcí soubor programu pro načítání, slučování a následné otestování seznamů ze souborů.
 * 
 * Tento program přijímá názvy souborů jako argumenty příkazové řádky(načítá celé čísla).
 * Vytvoří více seznamů, sloučí je do jednoho a následně otestuje, zda slučovací algoritmus proběhl správně.
 * 
 * @author Jan Cigánek
 * @date 9.4.2025
 * 
 * @version 1.0
 * 
 * @see List
 * @see AllLists
 * 
 * Kompilace:
 * ```
 * mkdir build && cd build 
 * cmake ..
 * make 
 * ```
 *
 * Spuštění:
 * ```
 * ./MergeLists soubor1 soubor2 ...
 * ```
 * 
 * 
 * @par Použité zdroje:
 * - https://www.programiz.com/dsa/merge-sort
 * - https://www.doxygen.nl/manual/index.html
 * 
 */

/**
 * @brief Hlavní funkce programu.
 * 
 * @param argc Počet argumentů příkazové řádky.
 * @param argv Pole argumentů (názvy souborů bez přípony a cesty).
 * 
 * @details Program očekává názvy souborů jako argumenty, přičemž soubory jsou automaticky hledány
 * ve složce `../test_data/` a doplní se přípona `.txt`. Vytvoří se instance třídy `AllLists`,
 * která načte všechny seznamy, provede jejich sloučení do jednoho výsledného seznamu a vytiskne
 * výsledek. Následně se výsledek otestuje pomocí metody `testMerge()`.
 */


int main(int argc, char* argv[]){

    vector<string> files;

    // Vytvoření úplných cest k souborům.
    for(size_t i = 1;i < argc; i++){
        files.push_back(string("../test_data/") + argv[i] + ".txt");
    }

    // Vytvoření instance AllLists se zadanými soubory.
    AllLists allLists(argc - 1, files);

    // Sloučení všech seznamů do jednoho.
    List merged = allLists.mergeLists();
    

    // Výpis sloučeného seznamu.
    cout << "-----MERGED LIST-----\n";
    merged.printList();


    // Tesstování správnosti algoritmu.
    merged.testMerge(files);
    
    return 0;
}

