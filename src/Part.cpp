#include <iostream>
#include "Part.h"

void Part::setName(const std::string &name) {
    if (name.length() <= 256) {
        Name = name;
    } else {
        std::cerr << "Too much characters!";
    }
}

void Part::setProducer(const std::string &producer) {
    if (producer.length() <= 256) {
        Producer = producer;
    } else {
        std::cerr << "Too much characters!";
    }
}

void Part::setModel(const std::string &model) {
    if (model.length() <= 50) {
        Model = model;
    } else {
        std::cerr << "Too much characters!";
    }
}

void Part::setCategory(const int &choice) {
    switch (choice) {
        case 1:
            Category = "Processor";
            break;
        case 2:
            Category = "Graphic Card";
            break;
        case 3:
            Category = "Motherboard";
            break;
        case 4:
            Category = "Peripherals";
            break;
    }
}

void Part::setNumberUnits(const unsigned int &units) {
    nUnits = units;
}

void Part::setPricePerUnit(const float &price) {
    PricePerUnit = price;
}

void Part::setDate(const std::string &date) {
    Date = date;
}

void Part::setNote(const std::string &note) {
    if (note.length() <= 1000) {
        Note = note;
    } else {
        std::cerr << "Too much characters!";
    }
}

std::string Part::getName() const {
    return Name;
}

std::string Part::getProducer() const {
    return Producer;
}

std::string Part::getModel() const {
    return Model;
}

std::string Part::getCategory() const {
    return Category;
}

unsigned int Part::getNUnits() const {
    return nUnits;
}

float Part::getPricePerUnit() const {
    return PricePerUnit;
}

std::string Part::getDate() const {
    return Date;
}

std::string Part::getNote() const {
    return Note;
}
