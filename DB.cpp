#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "Client.h"
#include "Company.h"
#include "Address.h"
#include "FileHandler.h"
#include "Model.h"
#include "View.h"
#include "Controller.h"
#include "UserInterface.h"

int main(int argc, char** argv)
{
    std::string databasePath = "";
    if (argc == 2)
        databasePath = argv[1];
    else if (argc < 2)
        databasePath = std::filesystem::current_path().append("db.stefan").u8string();
    else if (argc > 2)
    {
        std::cout << "Nie prawidłowa liczba argumentów! Przerwano działanie programu." << std::endl;
        return 1;
    }
    std::cout << "Lokalizacja bazy danych: " << databasePath << std::endl;

    Controller DB(databasePath);
    UserInterface UI;
    while (DB.getRunningState())
    {
        UI.showDatabaseMenu(&DB);
        UI.showTableMenu(&DB);
    }

    return 0;
}
