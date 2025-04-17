/**
 * @file AllLists.h
 * @brief Hlavičkový soubor obsahující deklaraci třídy AllLists pro správu více seznamů.
 *
 * @see List
 * 
 */

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

    private:
        std::vector<List> folder;               /**< Vektor instancí Listů */
        size_t count;         /**< Aktuální počet uložených seznamů. */

};