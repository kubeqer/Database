#ifndef BAZA_DANYCH_PARTSTORE_H
#define BAZA_DANYCH_PARTSTORE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Part.h"

//enum CategoryToSort {
//    NAME, PRODUCER, MODEL, CATEGORY, nUNITS, PRICEpU, DATE
//};

class PartStore {
    std::vector<Part> parts;
public:
    // creates a new part and adds it to the store.
    void createPart(std::string name, std::string producer, std::string model,
                    int category, unsigned int nUnits, float PricePerUnit,
                    std::string date, std::string note);

    // removes a part from the store by index.
    void removePartByIndex(int index);

    // finds parts in the store by name
    std::vector<Part> findPartByName(std::string name);

    // finds parts in the store by category.
    std::vector<Part> findPartByCategory(std::string category);

    // gets a constant reference to the vector of parts in the store.
    const std::vector<Part> &getParts() const;


    //Currently not using this method
//    void sortVector(CategoryToSort category);

    // displays information about all parts in the store.
    void display() const;
};

#endif //BAZA_DANYCH_PARTSTORE_H
