//#pragma once
class Controller :
    private Model,
    private View,
    private FileHandler
{
private:
    std::string dbpath;
    bool databaseMenuState;
    bool tableMenuState;
    bool RunningState;
protected:
    using FileHandler::FileHandler;
    using Model::Model;
    using View::View;
    std::string databasePath{ dbpath };
public:
    int userChooseFromDatabaseMenu;
    int userChooseFromTableMenu;
    Controller(std::string databasePath);
    ~Controller();
    void databaseMenu();
    void tableMenu(int userChooseFromDatabaseMenu);
    bool getDatabaseMenuState();
    void setDatabaseMenuState(bool state);
    bool getTableMenuState();
    void setTableMenuState(bool state);
    bool getRunningState();
    void setRunningState(bool state);
private:
    // CLIENTS
    void displayClientsTable();
    void truncateClientsTable();
    void insertRowInToClientsTable();
    void selectRowFromClientsTable(const int& index);
    void selectFullRowFromClientsTable(const int& index);
    void updateRowInToClientsTable(const int& index);
    void deleteRowFromClientsTable(const int& index);
    void softDeleteRowFromClientsTable(const int& index);
    void undoSoftDeleteRowFromClientsTable(const int& index);
    void sortClientsTable(const int& columnNo, const bool& order);
    // COMPANIES
    void displayCompaniesTable();
    void truncateCompaniesTable();
    void insertRowInToCompaniesTable();
    void selectRowFromCompaniesTable(const int& index);
    void selectFullRowFromCompaniesTable(const int& index);
    void updateRowInToCompaniesTable(const int& index);
    void deleteRowFromCompaniesTable(const int& index);
    void softDeleteRowFromCompaniesTable(const int& index);
    void undoSoftDeleteRowFromCompaniesTable(const int& index);
    void sortCompaniesTable(const int& columnNo, const bool& order);
    // ADDRESSES
    void displayAddressesTable();
    void truncateAddressesTable();
    void insertRowInToAddressesTable();
    void selectRowFromAddressesTable(const int& index);
    void updateRowInToAddressesTable(const int& index);
    void deleteRowFromAddressesTable(const int& index);
    void softDeleteRowFromAddressesTable(const int& index);
    void undoSoftDeleteRowFromAddressesTable(const int& index);
    void sortAddressesTable(const int& columnNo, const bool& order);
    // CLIENTS, COMPANIES, ADDRESSES
    void displayDatabase();
    void dropDatabase();
    template <typename columnType>
    void findAllRowsInClientsTable(int columnNo, columnType value);
    template <typename columnType>
    void findAllRowsInCompaniesTable(int columnNo, columnType value);
    template <typename columnType>
    void findAllRowsInAddressesTable(int columnNo, columnType value);
};
Controller::Controller(std::string databasePath) : FileHandler(databasePath)
{
    RunningState = true;
    databaseMenuState = true;
    tableMenuState = false;
    userChooseFromTableMenu = 7;
    userChooseFromDatabaseMenu = -1;
    //std::cout << "Klasa Controller została zaincjalizowana." << std::endl;
    FileHandler::loadDB(Model::clients, Model::companies, Model::addresses);
}
Controller::~Controller()
{
    FileHandler::saveDB(Model::clients, Model::companies, Model::addresses);
    //std::cout << "Instancja klasy Controller została usunięta." << std::endl;
};
void Controller::displayClientsTable()
{
    View::selectFromTable(Model::clients);
};
void Controller::displayCompaniesTable()
{
    View::selectFromTable(Model::companies);
};
bool Controller::getDatabaseMenuState()
{
    return databaseMenuState;
};
void Controller::setDatabaseMenuState(bool state)
{
    databaseMenuState = state;
};
bool Controller::getTableMenuState()
{
    return tableMenuState;
};
void Controller::setTableMenuState(bool state)
{
    tableMenuState = state;
};
bool Controller::getRunningState()
{
    return RunningState;
};
void Controller::setRunningState(bool state)
{
    RunningState = state;
};
void Controller::displayAddressesTable()
{
    View::selectFromTable(Model::addresses);
};
void Controller::displayDatabase()
{
    displayClientsTable();
    displayCompaniesTable();
    displayAddressesTable();
};
void Controller::truncateClientsTable()
{
    Model::truncateTable(Model::clients);
};
void Controller::truncateCompaniesTable()
{
    Model::truncateTable(Model::companies);
};
void Controller::truncateAddressesTable()
{
    Model::truncateTable(Model::addresses);
};
void Controller::dropDatabase()
{
    truncateClientsTable();
    truncateCompaniesTable();
    truncateAddressesTable();
};
void Controller::insertRowInToClientsTable()
{
    Client client;
    client.idClient = (Model::clients.empty()) ? 1 : Model::clients.back().idClient + 1;
    View::insertRow(client, client.idClient);
    Model::insertRow(Model::clients, client);
};
void Controller::insertRowInToCompaniesTable()
{
    Company company;
    company.idCompany = (Model::companies.empty()) ? 1 : Model::companies.back().idCompany + 1;
    View::insertRow(company, company.idCompany);
    Model::insertRow(Model::companies, company);
};
void Controller::insertRowInToAddressesTable()
{
    Address address;
    address.idAddress = (Model::addresses.empty()) ? 1 : Model::addresses.back().idAddress + 1;
    View::insertRow(address, address.idAddress);
    Model::insertRow(Model::addresses, address);
};
void Controller::selectRowFromClientsTable(const int& index)
{
    std::vector<Client>::iterator row = Model::findRowInTableByIndex(Model::clients, index);
    if (row == Model::clients.end())
    {
        View::displayError(1);
    }
    else
    {
        View::selectRowFromTable(*row);
    }
};
void Controller::selectFullRowFromClientsTable(const int& index)
{
    std::vector<Client>::iterator row = Model::findRowInTableByIndex(Model::clients, index);
    if (row == Model::clients.end())
    {
        View::displayError(1);
    }
    else
    {
        View::selectRowFromTable(*row);
        int clientAddressId = row->addressId;
        selectRowFromAddressesTable(clientAddressId);
        int companyId = row->companyId;
        selectFullRowFromCompaniesTable(companyId);
    }
};
void Controller::selectRowFromCompaniesTable(const int& index)
{
    std::vector<Company>::iterator row = Model::findRowInTableByIndex(Model::companies, index);
    if (row == Model::companies.end())
    {
        View::displayError(2);
    }
    else
    {
        View::selectRowFromTable(*row);
    }
};
void Controller::selectFullRowFromCompaniesTable(const int& index)
{
    std::vector<Company>::iterator row = Model::findRowInTableByIndex(Model::companies, index);
    if (row == Model::companies.end())
    {
        View::displayError(2);
    }
    else
    {
        View::selectRowFromTable(*row);
        int clientAddressId = row->addressId;
        selectRowFromAddressesTable(clientAddressId);
    }
};
void Controller::selectRowFromAddressesTable(const int& index)
{
    std::vector<Address>::iterator row = Model::findRowInTableByIndex(Model::addresses, index);
    if (row == Model::addresses.end())
    {
        View::displayError(3);
    }
    else
    {
        View::selectRowFromTable(*row);
    }
};
void Controller::updateRowInToClientsTable(const int& index)
{
    int position = -1;
    std::vector<Client>::iterator row = Model::findRowInTableByIndex(Model::clients, index);
    if (row == Model::clients.end())
    {
        View::displayError(4);
    }
    else
    {
        position = std::distance(Model::clients.begin(), row);
        View::updateRow(*row);
        Model::updateRow(Model::clients.at(position), *row);
    }
};
void Controller::updateRowInToCompaniesTable(const int& index)
{
    int position = -1;
    std::vector<Company>::iterator row = Model::findRowInTableByIndex(Model::companies, index);
    if (row == Model::companies.end())
    {
        View::displayError(5);
    }
    else
    {
        position = std::distance(Model::companies.begin(), row);
        View::updateRow(*row);
        Model::updateRow(Model::companies.at(position), *row);
    }
};
void Controller::updateRowInToAddressesTable(const int& index)
{
    int position = -1;
    std::vector<Address>::iterator row = Model::findRowInTableByIndex(Model::addresses, index);
    if (row == Model::addresses.end())
    {
        View::displayError(6);
    }
    else
    {
        position = std::distance(Model::addresses.begin(), row);
        View::updateRow(*row);
        Model::updateRow(Model::addresses.at(position), *row);
    }
};
void Controller::deleteRowFromClientsTable(const int& index)
{
    std::vector<Client>::iterator row = Model::findRowInTableByIndex(Model::clients, index);
    if (row == Model::clients.end())
    {
        View::displayError(7);
    }
    else
    {
        Model::deleteRow(Model::clients, row);
    }
};
void Controller::deleteRowFromCompaniesTable(const int& index)
{
    std::vector<Company>::iterator row = Model::findRowInTableByIndex(Model::companies, index);
    if (row == Model::companies.end())
    {
        View::displayError(8);
    }
    else
    {
        Model::deleteRow(Model::companies, row);
    }
};
void Controller::deleteRowFromAddressesTable(const int& index)
{
    std::vector<Address>::iterator row = Model::findRowInTableByIndex(Model::addresses, index);
    if (row == Model::addresses.end())
    {
        View::displayError(9);
    }
    else
    {
        Model::deleteRow(Model::addresses, row);
    }
};
void Controller::softDeleteRowFromClientsTable(const int& index)
{
    std::vector<Client>::iterator row = Model::findRowInTableByIndex(Model::clients, index);
    if (row == Model::clients.end())
    {
        View::displayError(10);
    }
    else
    {
        Model::softDeleteRow(*row);
    }
};
void Controller::softDeleteRowFromCompaniesTable(const int& index)
{
    std::vector<Company>::iterator row = Model::findRowInTableByIndex(Model::companies, index);
    if (row == Model::companies.end())
    {
        View::displayError(11);
    }
    else
    {
        Model::softDeleteRow(*row);
    }
};
void Controller::softDeleteRowFromAddressesTable(const int& index)
{
    std::vector<Address>::iterator row = Model::findRowInTableByIndex(Model::addresses, index);
    if (row == Model::addresses.end())
    {
        View::displayError(12);
    }
    else
    {
        Model::softDeleteRow(*row);
    }
};
void Controller::undoSoftDeleteRowFromClientsTable(const int& index)
{
    std::vector<Client>::iterator row = Model::findRowInTableByIndex(Model::clients, index);
    if (row == Model::clients.end())
    {
        View::displayError(13);
    }
    else
    {
        Model::undoSoftDeleteRow(*row);
    }
};
void Controller::undoSoftDeleteRowFromCompaniesTable(const int& index)
{
    std::vector<Company>::iterator row = Model::findRowInTableByIndex(Model::companies, index);
    if (row == Model::companies.end())
    {
        View::displayError(14);
    }
    else
    {
        Model::undoSoftDeleteRow(*row);
    }
};
void Controller::undoSoftDeleteRowFromAddressesTable(const int& index)
{
    std::vector<Address>::iterator row = Model::findRowInTableByIndex(Model::addresses, index);
    if (row == Model::addresses.end())
    {
        View::displayError(15);
    }
    else
    {
        Model::undoSoftDeleteRow(*row);
    }
};
void Controller::sortClientsTable(const int& column, const bool& order)
{
    Model::sortTableBy(Model::clients, column, order);
    displayClientsTable();
    Model::sortTableBy(Model::clients, 0, 1);
};
void Controller::sortCompaniesTable(const int& column, const bool& order)
{
    Model::sortTableBy(Model::companies, column, order);
    displayCompaniesTable();
    Model::sortTableBy(Model::companies, 0, 1);
};
void Controller::sortAddressesTable(const int& column, const bool& order)
{
    Model::sortTableBy(Model::addresses, column, order);
    displayAddressesTable();
    Model::sortTableBy(Model::addresses, 0, 1);
};
template <typename columnType>
void Controller::findAllRowsInClientsTable(int columnNo, columnType value)
{
    typename std::vector<Client> tmp;
    tmp = Model::findAllRowsInTableByValue(Model::clients, columnNo, value);
    View::selectFromTable(tmp);
};
template <typename columnType>
void Controller::findAllRowsInCompaniesTable(int columnNo, columnType value)
{
    typename std::vector<Company> tmp;
    tmp = Model::findAllRowsInTableByValue(Model::companies, columnNo, value);
    View::selectFromTable(tmp);
};
template <typename columnType>
void Controller::findAllRowsInAddressesTable(int columnNo, columnType value)
{
    typename std::vector<Address> tmp;
    tmp = Model::findAllRowsInTableByValue(Model::addresses, columnNo, value);
    View::selectFromTable(tmp);
};
void Controller::databaseMenu()
{
    View::databaseMenu();
    userChooseFromDatabaseMenu = View::specifyMenuOption();
    if (userChooseFromDatabaseMenu == 0)
    {
        RunningState = false;
    }
    databaseMenuState = false;
    tableMenuState = true;
};
void Controller::tableMenu(int userChooseFromDatabaseMenu)
{
    if (userChooseFromDatabaseMenu == 1)
    {
        View::clientsTableMenu();
        userChooseFromTableMenu = View::specifyMenuOption();
        switch (userChooseFromTableMenu)
        {
        case 1:
            insertRowInToClientsTable();
            break;
        case 2:
            selectRowFromClientsTable(View::specifyIndex());
            break;
        case 3:
            selectFullRowFromClientsTable(View::specifyIndex());
            break;
        case 4:
            updateRowInToClientsTable(View::specifyIndex());
            break;
        case 5:
            deleteRowFromClientsTable(View::specifyIndex());
            break;
        case 6:
            softDeleteRowFromClientsTable(View::specifyIndex());
            break;
        case 7:
            undoSoftDeleteRowFromClientsTable(View::specifyIndex());
            break;
        case 8:
            displayClientsTable();
            break;
        case 9:
            truncateClientsTable();
            break;
        case 10:
            sortClientsTable(View::specifyColumnNo(), View::specifyOrder());
            break;
        case 11:
            findAllRowsInClientsTable(View::specifyColumnNo(), View::specifyFindValue<bool>());
            break;
        case 12:
            findAllRowsInClientsTable(View::specifyColumnNo(), View::specifyFindValue<int>());
            break;
        case 13:
            findAllRowsInClientsTable(View::specifyColumnNo(), View::specifyFindValue<std::string>());
            break;
        case 0:
            tableMenuState = false;
            databaseMenuState = true;
            break;
        default:
            tableMenu(userChooseFromDatabaseMenu);
            break;
        }
    }
    else if (userChooseFromDatabaseMenu == 2)
    {
        View::companiesTableMenu();
        userChooseFromTableMenu = View::specifyMenuOption();
        switch (userChooseFromTableMenu)
        {
        case 1:
            insertRowInToCompaniesTable();
            break;
        case 2:
            selectRowFromCompaniesTable(View::specifyIndex());
            break;
        case 3:
            selectFullRowFromCompaniesTable(View::specifyIndex());
            break;
        case 4:
            updateRowInToCompaniesTable(View::specifyIndex());
            break;
        case 5:
            deleteRowFromCompaniesTable(View::specifyIndex());
            break;
        case 6:
            softDeleteRowFromCompaniesTable(View::specifyIndex());
            break;
        case 7:
            undoSoftDeleteRowFromCompaniesTable(View::specifyIndex());
            break;
        case 8:
            displayCompaniesTable();
            break;
        case 9:
            truncateCompaniesTable();
            break;
        case 10:
            sortCompaniesTable(View::specifyColumnNo(), View::specifyOrder());
            break;
        case 11:
            findAllRowsInCompaniesTable(View::specifyColumnNo(), View::specifyFindValue<bool>());
            break;
        case 12:
            findAllRowsInCompaniesTable(View::specifyColumnNo(), View::specifyFindValue<int>());
            break;
        case 13:
            findAllRowsInCompaniesTable(View::specifyColumnNo(), View::specifyFindValue<std::string>());
            break;
        case 0:
            tableMenuState = false;
            databaseMenuState = true;
            break;
        default:
            tableMenu(userChooseFromDatabaseMenu);
            break;
        }
    }
    else if (userChooseFromDatabaseMenu == 3)
    {
        View::addressesTableMenu();
        userChooseFromTableMenu = View::specifyMenuOption();
        switch (userChooseFromTableMenu)
        {
        case 1:
            insertRowInToAddressesTable();
            break;
        case 2:
            selectRowFromAddressesTable(View::specifyIndex());
            break;
        case 3:
            updateRowInToAddressesTable(View::specifyIndex());
            break;
        case 4:
            deleteRowFromAddressesTable(View::specifyIndex());
            break;
        case 5:
            softDeleteRowFromAddressesTable(View::specifyIndex());
            break;
        case 6:
            undoSoftDeleteRowFromAddressesTable(View::specifyIndex());
            break;
        case 7:
            displayAddressesTable();
            break;
        case 8:
            truncateAddressesTable();
            break;
        case 9:
            sortAddressesTable(View::specifyColumnNo(), View::specifyOrder());
            break;
        case 10:
            findAllRowsInAddressesTable(View::specifyColumnNo(), View::specifyFindValue<bool>());
            break;
        case 11:
            findAllRowsInAddressesTable(View::specifyColumnNo(), View::specifyFindValue<int>());
            break;
        case 12:
            findAllRowsInAddressesTable(View::specifyColumnNo(), View::specifyFindValue<std::string>());
            break;
        case 0:
            tableMenuState = false;
            databaseMenuState = true;
            break;
        default:
            tableMenu(userChooseFromDatabaseMenu);
            break;
        }
    }
    else if (userChooseFromDatabaseMenu == 4)
    {
        displayDatabase();
        tableMenuState = false;
        databaseMenuState = true;
    }
    else if (userChooseFromDatabaseMenu == 5)
    {
        dropDatabase();
        tableMenuState = false;
        databaseMenuState = true;
    }
    else
    {
        View::displayError(0);
        RunningState = false;
    }
};
