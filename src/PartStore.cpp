#include "PartStore.h"

void PartStore::removePartByIndex(int index) {
    if(index >= parts.size() || index < 0) {
        std::cout << "Invalid part index" << std::endl;
        return;
    }
    parts.erase(parts.begin() + index);
}

std::vector<Part> PartStore::findPartByName(std::string name) {
    std::vector<Part> foundParts;
    for(const auto& part : parts) {
        if(part.getName() == name)
            foundParts.push_back(part);
    }
    return foundParts;
}

std::vector<Part> PartStore::findPartByCategory(std::string category) {
    std::vector<Part> foundParts;
    for(const auto& part : parts) {
        if(part.getCategory() == category)
            foundParts.push_back(part);
    }
    return foundParts;
}

void PartStore::createPart(std::string name, std::string producer, std::string model,
                int category, unsigned int nUnits, float PricePerUnit,
                std::string date, std::string note) {
    Part newPart;
    newPart.setName(name);
    newPart.setProducer(producer);
    newPart.setModel(model);
    newPart.setCategory(category);
    newPart.setNumberUnits(nUnits);
    newPart.setPricePerUnit(PricePerUnit);
    newPart.setDate(date);
    newPart.setNote(note);
    parts.push_back(newPart);
}

const ::std::vector<Part> & PartStore::getParts() const {
    return parts;
}


void PartStore::display() const {

    std::cout << "Displaying all parts in the store:" << std::endl;

    for (size_t i = 0; i < parts.size(); ++i) {
        const Part &part = parts[i];
        std::cout << "Index: " << i << std::endl;
        std::cout << "Name: " << part.getName() << std::endl;
        std::cout << "Producer: " << part.getProducer() << std::endl;
        std::cout << "Model: " << part.getModel() << std::endl;
        std::cout << "Category: " << part.getCategory() << std::endl;
        std::cout << "Number of Units: " << part.getNUnits() << std::endl;
        std::cout << "Price per Unit: " << part.getPricePerUnit() << std::endl;
        std::cout << "Date: " << part.getDate() << std::endl;
        std::cout << "Note: " << part.getNote() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}

//    void PartStore::sortVector(CategoryToSort category) {
//        if (category == NAME) {
//            std::sort(parts.begin(), parts.end(), [](const Part &a, const Part &b) {
//                return a.getName() < b.getName();
//            });
//        }
//        if (category == PRODUCER) {
//            std::sort(parts.begin(), parts.end(), [](const Part &a, const Part &b) {
//                return a.getProducer() < b.getProducer();
//            });
//        }
//        if (category == MODEL) {
//            std::sort(parts.begin(), parts.end(), [](const Part &a, const Part &b) {
//                return a.getModel() < b.getModel();
//            });
//        }
//        if (category == CATEGORY) {
//            std::sort(parts.begin(), parts.end(), [](const Part &a, const Part &b) {
//                return a.getCategory() < b.getCategory();
//            });
//        }
//        if (category == nUNITS) {
//            std::sort(parts.begin(), parts.end(), [](const Part &a, const Part &b) {
//                return a.getNUnits() < b.getNUnits();
//            });
//        }
//        if (category == PRICEpU) {
//            std::sort(parts.begin(), parts.end(), [](const Part &a, const Part &b) {
//                return a.getPricePerUnit() < b.getPricePerUnit();
//            });
//        }
//        if (category == DATE) {
//            std::sort(parts.begin(), parts.end(), [](const Part &a, const Part &b) {
//                return a.getDate() < b.getDate();
//            });
//        }
//    }
