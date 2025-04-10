#include "List.h"
#include "AllLists.h"

#include <iostream>

using std::cout, std::vector, std::string;

/**
 * @mainpage Algoritmy I - Projekt - Slévání seznamů
 * 
 * Tento program přijímá názvy souborů jako argumenty příkazové řádky(načítá celé čísla).
 * Vytvoří více seznamů, sloučí je do jednoho a následně otestuje, zda slučovací algoritmus proběhl správně.
 * 
 * @author Jan Cigánek
 * @date 10.4.2025
 * 
 * @version 1.1
 * 
 * @see List
 * @see AllLists
 * 
 * 
 * ## Algoritmus slévání seznamů
 * Algoritmus funguje následovně:
 * - Z každého seznamu se vezme aktuální hodnota (na daném indexu)
 * - Vybere se nejmenší z těchto hodnot a vloží se do výsledného seznamu
 * - Index v odpovídajícím seznamu se posune na další pozici
 * - Pokud už nějaký seznam nelze dál zpracovat, je označen jako "prázdný"
 * - Když už všechny seznamy kromě jednoho jsou prázdné, tak se zbytek jeho obsahu rovnou zkopíruje 
 *
 * Algoritmus je podobný jako merge fáze u MergeSortu, ale je funkční pro více než dva seznamy.
 * 
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
 * @file main.cpp
 * @brief Spouštěcí soubor programu pro načítání, slučování a následné otestování seznamů ze souborů.
 * 
 * @param argc Počet argumentů příkazové řádky.
 * @param argv Pole argumentů (názvy souborů bez přípony a cesty - cesta k souborům je pevně dána v programu).
 * 
 * @details Program očekává názvy souborů jako argumenty, přičemž soubory jsou automaticky hledány
 * ve složce `../test_data/` a doplní se přípona `.txt`. Vytvoří se instance třídy `AllLists`,
 * která načte všechny seznamy, provede jejich sloučení do jednoho výsledného seznamu a vytiskne
 * výsledek. Následně se výsledek otestuje pomocí metody `testMerge()`.
 */


int main(int argc, char* argv[]){

    vector<string> files;

    // Vytvoření úplných cest k souborům.
    string path = "../test_data/";    // Zde lze změnit cesta k požadovaným souborům se seznamy
    for(int i = 1;i < argc; i++){
        files.push_back(string(path) + argv[i] + ".txt");
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

