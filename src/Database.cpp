#include "Database.h"

void Database::openOrCreateFile(const std::string &filePath) {

    this->filePath = filePath;

    std::filesystem::path path(this->filePath);
    std::string directory = path.parent_path().string();
    std::string filename = path.filename().string();

    if (!std::filesystem::exists(directory)) {
        std::filesystem::create_directories(directory);
    }
    std::ofstream file(filePath, std::ios::out);
    file.close();

    std::ifstream inputFile(this->filePath);
    if (inputFile.is_open()) {
        std::string line;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string name, producer, model, date, note;
            int category;
            unsigned int nUnits;
            float PricePerUnit;

            if (std::getline(iss, name, ',') &&
                std::getline(iss, producer, ',') &&
                std::getline(iss, model, ',') &&
                iss >> category &&
                iss.ignore() &&
                iss >> nUnits &&
                iss.ignore() &&
                iss >> PricePerUnit &&
                iss.ignore() &&
                std::getline(iss, date, ',') &&
                std::getline(iss, note)) {
                partStore.createPart(name, producer, model, category, nUnits, PricePerUnit, date, note);
            } else {
                std::cerr << "Error: Unable to use line in the file." << std::endl;
            }
        }

        std::cout << "Data loaded from " << filename << " successfully." << std::endl;
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
    }
}

void Database::changeFileName(const std::string &newFileName, std::string filePath) {
    std::filesystem::path oldPath(filePath);
    std::string directory = oldPath.parent_path().string();
    std::string newFilePath = directory + "/" + newFileName;
    std::error_code ec;
    std::filesystem::rename(filePath, newFilePath, ec);

    if (!ec) {
        std::cout << "File name changed from '" << oldPath.filename().string() << "' to '" << newFileName << "'."
                  << std::endl;
    } else {
        std::cerr << "Error: Unable to change file name. " << ec.message() << std::endl;
    }
}

void Database::saveToFile() const {
    std::ofstream outputFile(filePath, std::ios::trunc);

    if (outputFile.is_open()) {
        const std::vector<Part> &parts = partStore.getParts();
        for (const Part &part: parts) {
            outputFile << part.getName() << "," << part.getProducer() << ","
                       << part.getModel() << "," << part.getCategory() << ","
                       << part.getNUnits() << "," << part.getPricePerUnit() << ","
                       << part.getDate() << "," << part.getNote() << std::endl;
        }

        std::cout << "Data saved to " << filePath << " successfully." << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}

void Database::deleteFile(std::string filePath) {
    std::error_code ec;
    std::filesystem::remove(filePath, ec);

    if (!ec) {
        std::cout << "File '" << filePath << "' deleted successfully." << std::endl;
        filePath.clear();
    } else {
        std::cerr << "Error: Unable to delete file. " << ec.message() << std::endl;
    }
}

int Database::getUserChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

void Database::DataMenu(PartStore &partStore) {
    int choice;
    do {
        partStore.display();
        std::cout << std::endl;
        std::cout << "1. Add Part\n";
        std::cout << "2. Remove Part\n";
        std::cout << "3. Find Part by Name\n";
        std::cout << "4. Find Part by Category\n";
        std::cout << "5. Sort Vector\n";
        std::cout << "6. Display\n";
        std::cout << "7. Save to File\n";
        std::cout << "8. Exit this database\n";

        choice = getUserChoice();

        switch (choice) {
            case 1: {
                std::string name, producer, model, date, note;
                int category;
                unsigned int nUnits;
                float PricePerUnit;

                std::cout << "Enter the name: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);

                std::cout << "Enter the producer: ";
                std::getline(std::cin, producer);

                std::cout << "Enter the model: ";
                std::getline(std::cin, model);

                int n;
                std::cout << "Enter the category:\n";
                std::cout << "1. Processor\n";
                std::cout << "2. Graphic Card\n";
                std::cout << "3. Motherboard\n";
                std::cout << "4. Peripherals\n";;
                std::cin >> category;


                std::cout << "Enter the number of units: ";
                std::cin >> nUnits;

                std::cout << "Enter the price per unit: ";
                std::cin >> PricePerUnit;

                std::cout << "Enter the date: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, date);

                std::cout << "Enter the note: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, note);

                partStore.createPart(name, producer, model, category, nUnits, PricePerUnit, date, note);

                std::cout << "Part created successfully." << std::endl;
                break;
            }
            case 2: {
                int n;
                std::cout << "Give index number to delete: ";
                std::cin >> n;
                partStore.removePartByIndex(n);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Enter the name to find: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);

                std::vector<Part> found = partStore.findPartByName(name);

                std::cout << "Found parts with name '" << name << "':" << std::endl;
                for (const Part &part: found) {
                    std::cout << "Name: " << part.getName() << std::endl;
                    std::cout << "Producer: " << part.getProducer() << std::endl;
                    std::cout << "Model: " << part.getModel() << std::endl;
                    std::cout << "Category: " << part.getCategory() << std::endl;
                    std::cout << "Number of Units: " << part.getNUnits() << std::endl;
                    std::cout << "Price per Unit: " << part.getPricePerUnit() << std::endl;
                    std::cout << "Date: " << part.getDate() << std::endl;
                    std::cout << "Note: " << part.getNote() << std::endl;
                }
                break;
            }
            case 4: {
                int n;
                std::cout << "Choose category to find:\n";
                std::cout << "1. Processor\n";
                std::cout << "2. Graphic Card\n";
                std::cout << "3. Motherboard\n";
                std::cout << "4. Peripherals\n";
                std::cin >> n;

                if (n >= 1 && n <= 4) {
                    std::string type;
                    if (n == 1)
                        type = "Processor";
                    else if (n == 2)
                        type = "Graphic Card";
                    else if (n == 3)
                        type = "Motherboard";
                    else if (n == 4)
                        type = "Peripherals";
                    std::vector<Part> found = partStore.findPartByCategory(type);

                    std::cout << "Found parts in category " << type << ":" << std::endl;
                    for (const Part &part: found) {
                        std::cout << "Name: " << part.getName() << std::endl;
                        std::cout << "Producer: " << part.getProducer() << std::endl;
                        std::cout << "Model: " << part.getModel() << std::endl;
                        std::cout << "Category: " << part.getCategory() << std::endl;
                        std::cout << "Number of Units: " << part.getNUnits() << std::endl;
                        std::cout << "Price per Unit: " << part.getPricePerUnit() << std::endl;
                        std::cout << "Date: " << part.getDate() << std::endl;
                        std::cout << "Note: " << part.getNote() << std::endl;
                    }
                } else {
                    std::cout << "Invalid category choice." << std::endl;
                }
                break;
            }
            case 5:

                break;
            case 6:
                partStore.display();
                break;
            case 7:
                saveToFile();
                break;
            case 8:
                std::cout << "Exiting this database." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 8);
}

void Database::runProgram() {
    int choice;
    std::string filePath;
    do {
        std::cout << "MENU:\n";
        std::cout << "1. Open file\n";
        std::cout << "2. Change File Name\n";
        std::cout << "3. Delete File\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter the file path: ";
                std::getline(std::cin, filePath);
                openOrCreateFile(filePath);
                DataMenu(partStore);
                break;
            }
            case 2: {
                std::cout << "Enter the file path: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, filePath);
                std::string newFileName;
                std::cout << "Enter the new file name: ";
                std::getline(std::cin, newFileName);
                changeFileName(newFileName, filePath);
                break;
            }
            case 3: {
                std::cout << "Enter the file path: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, filePath);
                deleteFile(filePath);
                break;
            }
            case 4: {
                std::cout << "Exiting the program." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 4);
}
