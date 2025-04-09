#pragma once

#include "List.h"



/**
 * @class AllLists
 * @brief Třída sloužící pro správu více seznamů (List) a jejich slučování.
 * 
 * Tato třída reprezentuje kolekci více seznamů a umožňuje jejich sloučení do jednoho seřazeného seznamu.
 * 
 * @see List
 * 
 */

class AllLists{
    public:
        /**
        * @brief Konstruktor vytvoří více seznamů ze souborů.
        * 
        * @param k Počet seznamů.
        * @param filenames Vektor názvů souborů, ze kterých se načítají data.
        */
        AllLists(int k,const std::vector<std::string> filenames);

        /**
        * @brief Destruktor uvolní paměť alokovanou pro seznamy.
        */
        ~AllLists();


        /**
        * @brief Sloučí všechny seznamy do jednoho setříděného seznamu.
        * 
        * @return List Setříděný výsledný seznam.
        * @note Nejdůležitější metoda celého projektu.
        * 
        */
        List mergeLists();

        /**
        * @brief Spočítá celkový počet prvků ve všech seznamech součtem velikostí jednotlivých seznamů.
        * 
        * @return size_t Celková velikost dat.
        */
        size_t wholeSize();

        /**
        * @brief Vrátí konkrétní seznam podle indexu.
        * 
        * @param index Index požadovaného seznamu.
        * @return List Kopie seznamu na daném indexu.
        */
        List getList(const unsigned int index);

    private:
        List* folder;               /**< Ukazatel na pole seznamů. */
        unsigned int capacity;      /**< Kapacita pole seznamů. */
        unsigned int count;         /**< Aktuální počet uložených seznamů. */

        static unsigned int defaultCapacity;    /**< Výchozí kapacita pole. */
};