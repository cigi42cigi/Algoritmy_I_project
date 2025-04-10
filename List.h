/**
 * @file List.h
 * @brief Hlavičkový soubor obsahující deklaraci třídy List pro správu seznamu.
 *
 */

#pragma once

#include <vector>
#include <string>

/**
 * @class List
 * @brief Třída reprezentující seznam celých čísel, s podporou průchodu pomocí indexu.
 *
 * Používá se k načtení čísel ze souboru nebo ze vstupního vektoru a poskytuje základní operace
 * jako je získání hodnoty na indexu, posun indexu, kontrola prázdnosti, velikost seznamu nebo výpis.
 *    
 */

class List{
    public:
        /**
        * @brief Konstruktor vytvoří List z daného vektoru čísel.
        * @param inputData Vektor celých čísel.
        */
        List(const std::vector<int> inputData);

        /**
        * @brief Konstruktor načte čísla ze souboru a tvoří vektor čísel.
        * @param filename Cesta k textovému souboru, kde jsou čísla po řádcích.
        */
        List(const std::string& filename);

        /**
        * @brief Výchozí konstruktor vytvoří prázdný List s indexem 0.
        */
        List();


        /**
        * @brief Vrací aktuální pozici indexu v seznamu.
        * @return Celé číslo reprezentující pozici.
        */
        int getIndex();

        /**
        * @brief Vytiskne všechna čísla v seznamu na standardní výstup.
        */
        void printList();

        /**
        * @brief Posune index o jedno místo doprava.
        */
        void increaseIndex();

        /**
        * @brief Vrací číslo na aktuální pozici indexu.
        * @return Hodnota ze seznamu na aktuální pozici.
        */
        int getAtIndex();

        /**
        * @brief Vrací počet všech hodnot v seznamu.
        * @return Velikost seznamu.
        */
        size_t getSize();

        /**
        * @brief Zjistí, zda jsem prošel celý seznam (podle indexu).
        * @return true pokud je index za posledním prvkem, jinak false.
        */
        bool isEmpty();

        /**
        * @brief Vrací celý uložený vektor čísel.
        * @return Vektor celých čísel.
        */
        std::vector<int> getData();



        /**
        * @brief Vypisuje výsledek všech seznamů sloučených za sebe a následně seřazených.
        * @param files Seznam souborů, ze kterých se testovací data načítají.
        * @note Výpisem kontroluje, zda jsou data shodná(funkce určená pouze pro již mergnutý seznam).
        */
        void testMerge(const std::vector<std::string>& files);

    private:
        std::vector<int> data;  /**< Vektor uchovávající načtená čísla. */
        unsigned int index;     /**< Aktuální pozice v seznamu. */
};