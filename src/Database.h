#ifndef BAZA_DANYCH_DATABASE_H
#define BAZA_DANYCH_DATABASE_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include "Part.h"
#include "PartStore.h"


class Database {
    std::string filePath;
    PartStore partStore;
public:
    Database() = default;

    // if the specified file path does not exist, the function creates the
    // directories and initializes an empty file. it then reads the contents of the file
    // and fills the part store with the stored data.
    void openOrCreateFile(const std::string &filePath);

    // renames the existing file with the new file name provided.
    void changeFileName(const std::string &newFileName, std::string filePath);

    // saves the data from the part store to the current file.
    void saveToFile() const;

    // deletes the specified file.
    void deleteFile(std::string filePath);

    // retrieves the users choice from the console.
    int getUserChoice();

    // displays options to add, remove, find, and manipulate part data.
    // it continues to execute the chosen operation until the user chooses to exit.
    void DataMenu(PartStore &partStore);

    // runs the main program loop.
    // displays a menu for opening, renaming, deleting files, or exiting the program.
    // it continues to execute user-chosen operations until the user chooses to exit the program.
    void runProgram();
};


#endif BAZA_DANYCH_DATABASE_H
