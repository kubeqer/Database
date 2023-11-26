#ifndef BAZA_DANYCH_PART_H
#define BAZA_DANYCH_PART_H
#include <string>
#include <vector>

class Part
{
    std::string Name; //limited to 256 characters
    std::string Producer; //limited to 256 characters
    std::string Model; //limited to 50 characters
    std::string Category; //- one of the: processor, graphic card, motherboard, peripherals
    unsigned int nUnits;
    float PricePerUnit;
    std::string Date; //blank if not applicable
    std::string Note; //limited to 1000 characters
public:
    //simple setters
    void setName(const std::string &name);
    void setProducer(const std::string &producer);
    void setModel(const std::string &model);
    void setCategory(const int &choice);
    void setNumberUnits(const unsigned int &units);
    void setPricePerUnit(const float &price);
    void setDate(const std::string &date);
    void setNote(const std::string &note);
    //simple getters
    std::string getName() const;
    std::string getProducer() const;
    std::string getModel() const;
    std::string getCategory() const;
    unsigned int getNUnits() const;
    float getPricePerUnit() const;
    std::string getDate() const;
    std::string getNote() const;
};


#endif //BAZA_DANYCH_PART_H
