#pragma once
class View
{
protected:
    explicit View();
    virtual ~View();
protected:
    void renderIntro();
    void displayHelp();
    void displayError(const int& operation);
    int specifyMenuOption();
    int specifyColumnNo();
    int specifyIndex();
    bool specifyOrder();
    bool askForValueUpdate();
    template <typename rowName>
    rowName inputRowValues(rowName& row);
    template <typename dataType>
    dataType specifyFindValue();
    template <typename tableName>
    void selectFromTable(std::vector<tableName>& table);
    template <typename tableName>
    void selectRowFromTable(const tableName& row);
    template <typename rowName>
    void insertRow(rowName& row, const int& uniqueId);
    template <typename valueType>
    valueType updateValue(valueType& oldValue);
    template <typename rowName>
    auto updateRow(rowName& row) -> decltype(row);
    template <typename valueType>
    valueType validateUIInput(valueType& value);
    void databaseMenu();
    void clientsTableMenu();
    void companiesTableMenu();
    void addressesTableMenu();
};
View::View()
{
    //std::cout << "Klasa View została zaincjalizowany." << std::endl;
};
View::~View()
{
    //std::cout << "Instancja klasy View została usunięta." << std::endl;
};
void View::displayHelp()
{
    std::cout << "Pomoc - obsluga programu" << std::endl;
};
void View::displayError(const int& operation)
{
    switch (operation)
    {
    case 0:
        std::cout << "Wybrano nie istniejaca pozycje w menu." << std::endl;
        std::cout << "Program zostanie zamkniety." << std::endl;
        break;
    case 1:
        std::cout << "Nie odnaleziono wskazanego rekordu w tabeli KLIENCI." << std::endl;
        break;
    case 2:
        std::cout << "Nie odnaleziono wskazanego rekordu w tabeli FIRMY." << std::endl;
        break;
    case 3:
        std::cout << "Nie odnaleziono wskazanego rekordu w tabeli ADRESY." << std::endl;
        break;
    case 4:
        std::cout << "Nie mozna zaktualizowac wskazanego rekordu w tabeli KLIENCI." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 5:
        std::cout << "Nie mozna zaktualizowac wskazanego rekordu w tabeli FIRMY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 6:
        std::cout << "Nie mozna zaktualizowac wskazanego rekordu w tabeli ADRESY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 7:
        std::cout << "Nie mozna usunac wskazanego rekordu w tabeli KLIENCI." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 8:
        std::cout << "Nie mozna usunac wskazanego rekordu w tabeli FIRMY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 9:
        std::cout << "Nie mozna usunac wskazanego rekordu w tabeli ADRESY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 10:
        std::cout << "Nie mozna oznaczyc wskazanego rekordu jako usuniety w tabeli KLIENCI." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 11:
        std::cout << "Nie mozna oznaczyc wskazanego rekordu jako usuniety w tabeli FIRMY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 12:
        std::cout << "Nie mozna oznaczyc wskazanego rekordu jako usuniety w tabeli ADRESY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 13:
        std::cout << "Nie mozna cofnac oznaczenia wskazanego rekordu jako usuniety w tabeli KLIENCI." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 14:
        std::cout << "Nie mozna cofnac oznaczenia wskazanego rekordu jako usuniety w tabeli FIRMY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 15:
        std::cout << "Nie mozna cofnac oznaczenia wskazanego rekordu jako usuniety w tabeli ADRESY." << std::endl;
        std::cout << "Wskazany rekord nie istnieje!" << std::endl;
        break;
    case 16:
        std::cout << "Oczekiwano wartosci tekstowej." << std::endl;
        std::cout << "Wybierz ponownie: ";
        break;
    case 17:
        std::cout << "Oczekiwano wartosci logicznej." << std::endl;
        std::cout << "Wybierz ponownie: ";
        break;
    case 18:
        std::cout << "Oczekiwano wartosci liczbowej calkowitej." << std::endl;
        std::cout << "Wybierz ponownie: ";
        break;
    default:
        std::cout << "Wystąpił nieznany programistom błąd ;)" << std::endl;
        break;
    }
};
template <typename tableName>
void View::selectFromTable(std::vector<tableName>& table)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "ZAWARTOSC TABELI: KLIENCI" << std::endl;
        std::cout << std::string(120, '=') << std::endl;
        std::cout << std::setfill(' ');
        std::cout
            << "| " << std::setw(2) << "Id"
            << " | " << std::setw(17) << "Imie"
            << " | " << std::setw(17) << "Nazwisko"
            << " | " << std::setw(30) << "Adres e-mail"
            << " | " << std::setw(4) << "Plec"
            << " | " << std::setw(8) << "Id firmy"
            << " | " << std::setw(9) << "Id adresu"
            << " | " << std::setw(8) << "Usuniety"
            << " |" << std::endl;
        std::cout << std::string(120, '-') << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            std::cout
                << "| " << std::setw(2) << table.at(i).idClient
                << " | " << std::setw(17) << table.at(i).firstName
                << " | " << std::setw(17) << table.at(i).lastName
                << " | " << std::setw(30) << table.at(i).email
                << " | " << std::setw(4) << table.at(i).gender
                << " | " << std::setw(8) << table.at(i).addressId
                << " | " << std::setw(9) << table.at(i).companyId
                << " | " << std::setw(8) << table.at(i).softDel
                << " |" << std::endl;
        }
        std::cout << std::string(120, '-') << std::endl;
        std::cout << "| " << std::setw(114) << "Ilosc rekordow: " << std::setw(2) << table.size() << " |" << std::endl;
        std::cout << std::string(120, '=') << std::endl;
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "ZAWARTOSC TABELI: FIRMY" << std::endl;
        std::cout << std::string(120, '=') << std::endl;
        std::cout << std::setfill(' ');
        std::cout
            << "| " << std::setw(2) << "Id"
            << " | " << std::setw(25) << "Nazwa firmy"
            << " | " << std::setw(10) << "NIP"
            << " | " << std::setw(14) << "REGON"
            << " | " << std::setw(10) << "KRS"
            << " | " << std::setw(17) << "Skreslony z REGON"
            << " | " << std::setw(9) << "Id adresu"
            << " | " << std::setw(8) << "Usuniety"
            << " |" << std::endl;
        std::cout << std::string(120, '-') << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            std::cout
                << "| " << std::setw(2) << table.at(i).idCompany
                << " | " << std::setw(25) << table.at(i).name.substr(0, 25)
                << " | " << std::setw(10) << table.at(i).nip.substr(0, 10)
                << " | " << std::setw(14) << table.at(i).regon.substr(0, 14)
                << " | " << std::setw(10) << table.at(i).krs.substr(0, 10)
                << " | " << std::setw(17) << table.at(i).deletedFromREGON
                << " | " << std::setw(9) << table.at(i).addressId
                << " | " << std::setw(8) << table.at(i).softDel
                << " |" << std::endl;
        }
        std::cout << std::string(120, '-') << std::endl;
        std::cout << "| " << std::setw(114) << "Ilosc rekordow: " << std::setw(2) << table.size() << " |" << std::endl;
        std::cout << std::string(120, '=') << std::endl;
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "ZAWARTOSC TABELI: ADRESY" << std::endl;
        std::cout << std::string(120, '=') << std::endl;
        std::cout << std::setfill(' ');
        std::cout
            << "| " << std::setw(2) << "Id"
            << " | " << std::setw(6) << "Kraj"
            << " | " << std::setw(11) << "Wojewodztwo"
            << " | " << std::setw(8) << "Powiat"
            << " | " << std::setw(8) << "Gmina"
            << " | " << std::setw(8) << "Miasto"
            << " | " << std::setw(8) << "Ulica"
            << " | " << std::setw(6) << "Nr bud"
            << " | " << std::setw(6) << "Nr lok"
            << " | " << std::setw(6) << "Kod"
            << " | " << std::setw(6) << "Poczta"
            << " | " << std::setw(8) << "Usuniety"
            << " |" << std::endl;
        std::cout << std::string(120, '-') << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            std::cout
                << "| " << std::setw(2) << table.at(i).idAddress
                << " | " << std::setw(6) << table.at(i).country.substr(0, 6)
                << " | " << std::setw(11) << table.at(i).state.substr(0, 11)
                << " | " << std::setw(8) << table.at(i).county.substr(0, 8)
                << " | " << std::setw(8) << table.at(i).community.substr(0, 8)
                << " | " << std::setw(8) << table.at(i).town.substr(0, 8)
                << " | " << std::setw(8) << table.at(i).street.substr(0, 8)
                << " | " << std::setw(6) << table.at(i).propertyNo.substr(0, 6)
                << " | " << std::setw(6) << table.at(i).apartmentNo.substr(0, 6)
                << " | " << std::setw(6) << table.at(i).postCode.substr(0, 6)
                << " | " << std::setw(6) << table.at(i).postalTown.substr(0, 6)
                << " | " << std::setw(8) << table.at(i).softDel
                << " |" << std::endl;
        }
        std::cout << std::string(120, '-') << std::endl;
        std::cout << "| " << std::setw(114) << "Ilosc rekordow: " << std::setw(2) << table.size() << " |" << std::endl;
        std::cout << std::string(120, '=') << std::endl;
    }
};
template <typename tableName>
void View::selectRowFromTable(const tableName& row)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        if (row.softDel == 0)
        {
            std::cout << std::string(120, '=') << std::endl;
            std::cout << "TABELA: KLIENCI -> WYSWIETLAM WSKAZANY REKORD:" << std::endl;
            std::cout << std::string(120, '-') << std::endl;
            std::cout << "Id: " << row.idClient << std::endl;
            std::cout << "Imie: " << row.firstName << std::endl;
            std::cout << "Nazwisko: " << row.lastName << std::endl;
            std::cout << "Adres e-mail: " << row.email << std::endl;
            std::cout << "Plec: " << row.gender << std::endl;
            std::cout << "Id firmy: " << row.companyId << std::endl;
            std::cout << "Id adresu: " << row.addressId << std::endl;
            std::cout << std::string(120, '=') << std::endl;
        }
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        if (row.softDel == 0)
        {
            std::cout << std::string(120, '=') << std::endl;
            std::cout << "TABELA: FIRMY -> WYSWIETLAM WSKAZANY REKORD:" << std::endl;
            std::cout << std::string(120, '-') << std::endl;
            std::cout << "Id: " << row.idCompany << std::endl;
            std::cout << "Nazwa: " << row.name << std::endl;
            std::cout << "NIP: " << row.nip << std::endl;
            std::cout << "REGON: " << row.regon << std::endl;
            std::cout << "KRS: " << row.krs << std::endl;
            std::cout << "Info o skresleniu z REGON?: : " << row.deletedFromREGON << std::endl;
            std::cout << "Id adresu: " << row.addressId << std::endl;
            std::cout << std::string(120, '=') << std::endl;
        }
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        if (row.softDel == 0)
        {
            std::cout << std::string(120, '=') << std::endl;
            std::cout << "TABELA: ADRESY -> WYSWIETLAM WSKAZANY REKORD:" << std::endl;
            std::cout << std::string(120, '-') << std::endl;
            std::cout << "Id: " << row.idAddress << std::endl;
            std::cout << "Kraj: " << row.country << std::endl;
            std::cout << "Wojewodztwo: " << row.state << std::endl;
            std::cout << "Powiat: " << row.county << std::endl;
            std::cout << "Gmina: " << row.community << std::endl;
            std::cout << "Miasto: " << row.town << std::endl;
            std::cout << "Ulica: " << row.street << std::endl;
            std::cout << "Nr posiadlosci: " << row.propertyNo << std::endl;
            std::cout << "Nr mieszkania: " << row.apartmentNo << std::endl;
            std::cout << "Kod pocztowy: " << row.postCode << std::endl;
            std::cout << "Miasto pocztowe: " << row.postalTown << std::endl;
            std::cout << std::string(120, '=') << std::endl;
        }
    }
};
template <typename rowName>
void View::insertRow(rowName& row, const int& uniqueId)
{
    if constexpr (std::is_same<rowName, Client>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "WPROWADZ DANE KLIENTA O ID: " << uniqueId << std::endl;
        row.idClient = uniqueId;
        std::cout << std::string(120, '-') << std::endl;
        inputRowValues(row);
        std::cout << std::string(120, '-') << std::endl;
    }
    else if constexpr (std::is_same<rowName, Company>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "WPROAWDZ DANE FIRMY O ID:" << uniqueId << std::endl;
        row.idCompany = uniqueId;
        std::cout << std::string(120, '-') << std::endl;
        inputRowValues(row);
        std::cout << std::string(120, '=') << std::endl;
    }
    else if constexpr (std::is_same<rowName, Address>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "WPROWADZ DANE ADRESOWE O ID: " << uniqueId << std::endl;
        row.idAddress = uniqueId;
        std::cout << std::string(120, '-') << std::endl;
        inputRowValues(row);
        std::cout << std::string(120, '=') << std::endl;
    }
};
template <typename valueType>
valueType View::updateValue(valueType& oldValue)
{
    if constexpr (std::is_same<valueType, std::string>::value)
    {
        std::string newValue;
        if (askForValueUpdate())
        {
            std::cout << "Nowa wartosc: "; validateUIInput(newValue);
            return newValue;
        }
        else
        {
            return oldValue;
        }
    }
    else if constexpr (std::is_same<valueType, bool>::value)
    {
        bool newValue;
        if (askForValueUpdate())
        {
            std::cout << "Nowa wartosc: "; validateUIInput(newValue);
            return newValue;
        }
        else
        {
            return oldValue;
        }
    }
    else if constexpr (std::is_same<valueType, int>::value)
    {
        int newValue;
        if (askForValueUpdate())
        {
            std::cout << "Nowa wartosc: "; validateUIInput(newValue);
            return newValue;
        }
        else
        {
            return oldValue;
        }
    }
};
template <typename rowName>
rowName View::inputRowValues(rowName& row)
{
    if constexpr (std::is_same<rowName, Client>::value)
    {
        std::cout << "Imie: " << row.firstName << std::endl;
        row.firstName = updateValue(row.firstName);
        std::cout << "Nazwisko: " << row.lastName << std::endl;
        row.lastName = updateValue(row.lastName);
        std::cout << "Adres e-mail: " << row.email << std::endl;
        row.email = updateValue(row.email);
        std::cout << "Plec: " << row.gender << std::endl;
        row.gender = updateValue(row.gender);
        std::cout << "Id firmy: " << row.companyId << std::endl;
        row.companyId = updateValue(row.companyId);
        std::cout << "Id adresu: " << row.addressId << std::endl;
        row.addressId = updateValue(row.addressId);
        return row;
    }
    else if constexpr (std::is_same<rowName, Company>::value)
    {
        std::cout << "Nazwa: " << row.name << std::endl;
        row.name = updateValue(row.name);
        std::cout << "NIP: " << row.nip << std::endl;
        row.nip = updateValue(row.nip);
        std::cout << "REGON: " << row.regon << std::endl;
        row.regon = updateValue(row.regon);
        std::cout << "KRS: " << row.krs << std::endl;
        row.krs = updateValue(row.krs);
        std::cout << "Info o skresleniu z REGON?: " << row.deletedFromREGON << std::endl;
        row.deletedFromREGON = updateValue(row.deletedFromREGON);
        std::cout << "Id adresu: " << row.addressId << std::endl;
        row.addressId = updateValue(row.addressId);
        std::cout << std::string(120, '=') << std::endl;
        return row;
    }
    else if constexpr (std::is_same<rowName, Address>::value)
    {
        std::cout << "Kraj: " << row.country << std::endl;
        row.country = updateValue(row.country);
        std::cout << "Wojewodztwo: " << row.state << std::endl;
        row.state = updateValue(row.state);
        std::cout << "Powiat: " << row.county << std::endl;
        row.county = updateValue(row.county);
        std::cout << "Gmina: " << row.community << std::endl;
        row.community = updateValue(row.community);
        std::cout << "Miasto: " << row.town << std::endl;
        row.town = updateValue(row.town);
        std::cout << "Ulica: " << row.street << std::endl;
        row.street = updateValue(row.street);
        std::cout << "Numer posiadlosci: " << row.propertyNo << std::endl;
        row.propertyNo = updateValue(row.propertyNo);
        std::cout << "Numer mieszkania: " << row.apartmentNo << std::endl;
        row.apartmentNo = updateValue(row.apartmentNo);
        std::cout << "Kod pocztowy: " << row.postCode << std::endl;
        row.postCode = updateValue(row.postCode);
        std::cout << "Miasto pocztowe: " << row.postalTown << std::endl;
        row.postalTown = updateValue(row.postalTown);
        std::cout << std::string(120, '=') << std::endl;
        return row;
    }
};
template <typename rowName>
auto View::updateRow(rowName& row) -> decltype(row)
{
    if constexpr (std::is_same<rowName, Client>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "POPRAW DANE KLIENTA O ID: " << row.idClient << std::endl;
        std::cout << std::string(120, '-') << std::endl;
        inputRowValues(row);
    }
    else if constexpr (std::is_same<rowName, Company>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "POPRAW DANE FRIMY O ID: " << row.idCompany << std::endl;
        std::cout << std::string(120, '-') << std::endl;
        inputRowValues(row);
    }
    else if constexpr (std::is_same<rowName, Address>::value)
    {
        std::cout << std::string(120, '=') << std::endl;
        std::cout << "POPRAW DANE ADRESOWE O ID: " << row.idAddress << std::endl;
        std::cout << std::string(120, '-') << std::endl;
        inputRowValues(row);
    }
    return row;
};
void View::renderIntro()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << std::endl;
    }
    std::cout << std::string(40, ' ') << "========================================" << std::endl;
    std::cout << std::string(40, ' ') << "|| *                                * ||" << std::endl;
    std::cout << std::string(40, ' ') << "||                                    ||" << std::endl;
    std::cout << std::string(40, ' ') << "||                 ZPO                ||" << std::endl;
    std::cout << std::string(40, ' ') << "||             BAZA DANYCH            ||" << std::endl;
    std::cout << std::string(40, ' ') << "||              DB.STEFAN             ||" << std::endl;
    std::cout << std::string(40, ' ') << "||                                    ||" << std::endl;
    std::cout << std::string(40, ' ') << "|| *                                * ||" << std::endl;
    std::cout << std::string(40, ' ') << "========================================" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::endl;
    }
};
template <typename valueType>
valueType View::validateUIInput(valueType& value)
{
    if constexpr (std::is_same<valueType, std::string>::value)
    {
        std::getline(std::cin >> std::ws, value);
        if (std::cin.fail())
        {
            displayError(16);
        }
        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin >> std::ws, value);
        }
        return value;
    }
    else if constexpr (std::is_same<valueType, bool>::value)
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            displayError(17);
        }
        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cin >> value;
        }
        return value;
    }
    else if constexpr (std::is_same<valueType, int>::value)
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            displayError(18);
        }
        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cin >> value;
        }
        return value;
    }
};
int View::specifyColumnNo()
{
    int columnNo = 0;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << " Wartosc typu int oznaczajaca kolejne kolumny tabeli" << std::endl;
    std::cout << " Obslugiwane tabele:" << std::endl;
    std::cout << " Clients-> [0]:idClient; [1]:firstName; [2]:lastName; [3]:email; [4]:gender; [5]:softDel; [6]:companyId; [7]:addressId; " << std::endl;
    std::cout << " Companies-> [0]:idCompany; [1]:name; [2]:nip; [3]:regon; [4]:krs; [5]:deletedFromREGON; [6]:softDel; [7]:addressId; " << std::endl;
    std::cout << " Addresses-> [0]:idAddress; [1]:country; [2]:state; [3]:county; [4]:community; [5]:town; [6]:street; [7]:propertyNo; [8]:apartmentNo; [9]:postCode; [10]:postalTown; [11]:softDel; " << std::endl;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << " -> Wprowadz Numer kolumny: ";
    validateUIInput(columnNo);
    std::cout << std::string(120, '*') << std::endl;
    return columnNo;
};
int View::specifyIndex()
{
    int index = 0;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << " Wartosc typu int w kolumnie ID" << std::endl;
    std::cout << " Obslugiwane tabele:" << std::endl;
    std::cout << " std::vector<Client>" << std::endl;
    std::cout << " std::vector<Company>" << std::endl;
    std::cout << " std::vector<Addresses>" << std::endl;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << " -> Wprowadz Id rekordu: ";
    validateUIInput(index);
    std::cout << std::string(120, '*') << std::endl;
    return index;
};
bool View::specifyOrder()
{
    bool order = true;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << " Wartosc typu bool jako kierunek sortowania" << std::endl;
    std::cout << " [0] Sortowanie malejaco" << std::endl;
    std::cout << " [1] Sortowanie rosnaco" << std::endl;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << " -> Wprowadz kierunek sortowania: ";
    validateUIInput(order);
    std::cout << std::string(120, '*') << std::endl;
    return order;
};
int View::specifyMenuOption()
{
    int option = 0;
    std::cout << " -> Wybierz pozycje z menu: ";
    validateUIInput(option);
    std::cout << std::string(120, '*') << std::endl;
    return option;
};
bool View::askForValueUpdate()
{
    bool userChoice = false;
    std::cout << "Czy chcesz wprowadzic wartosc ?" << std::endl;
    std::cout << "[0]NIE [1]TAK" << std::endl;
    std::cout << "Wybierz: ";
    validateUIInput(userChoice);
    return userChoice;
};
template <typename dataType>
dataType View::specifyFindValue()
{
    dataType findValue;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << " Dostepne typy danych:" << std::endl;
    std::cout << " int" << std::endl;
    std::cout << " bool" << std::endl;
    std::cout << " std::string" << std::endl;
    std::cout << std::string(120, '*') << std::endl;
    std::cout << "specifyFindVaue():-> Wprowadz poszukiwana wartosc: ";
    validateUIInput(findValue);
    std::cout << std::string(120, '*') << std::endl;
    return findValue;
};
void View::databaseMenu()
{
    renderIntro();
    std::cout << std::string(120, '+') << std::endl;
    std::cout << "Wybierz tabele:" << std::endl;
    std::cout << " [1] Klienci" << std::endl;
    std::cout << " [2] Firmy" << std::endl;
    std::cout << " [3] Adresy" << std::endl;
    std::cout << std::string(120, '-') << std::endl;
    std::cout << "Przeprowadz operacje na bazie danych:" << std::endl;
    std::cout << " [4] Wyswietl zawartosc wszystkich tabel" << std::endl;
    std::cout << " [5] Usun zawartosc wszystkich tabel" << std::endl;
    std::cout << std::string(120, '-') << std::endl;
    std::cout << " [0] Zapisz i wyjdz" << std::endl;
    std::cout << std::string(120, '+') << std::endl;
};
void View::clientsTableMenu()
{
    std::cout << std::string(120, '+') << std::endl;
    std::cout << "Tabela Klienci -> Wybierz akcje:" << std::endl;
    std::cout << " [ 1] Wstaw nowy wiersz do tabeli Klienci" << std::endl;
    std::cout << " [ 2] Wyswietl wiersz z tabeli Klienci" << std::endl;
    std::cout << " [ 3] Wyswietl wiersz z tabeli Klienci wraz z wierszami z powiazanych tabel" << std::endl;
    std::cout << " [ 4] Zaktualizuj wiersz w tabeli Klienci" << std::endl;
    std::cout << " [ 5] Usun wiersz z tabeli Klienci" << std::endl;
    std::cout << " [ 6] Oznacz jako usuniety wiersz z tabeli Klienci" << std::endl;
    std::cout << " [ 7] Oznacz jako nieusuniety wiersz z tabeli Klienci" << std::endl;
    std::cout << " [ 8] Wyswietl zawartosc tabeli Klienci" << std::endl;
    std::cout << " [ 9] Wyczysc zawartosc tabeli Klienci" << std::endl;
    std::cout << " [10] Sortuj zawartosc tabeli Klienci" << std::endl;
    std::cout << " [11] Przeszukaj zawartosc tabeli Firmy po wartosci logicznej" << std::endl;
    std::cout << " [12] Przeszukaj zawartosc tabeli Firmy po wartosci numerycznej" << std::endl;
    std::cout << " [13] Przeszukaj zawartosc tabeli Firmy po wartosci tekstowej" << std::endl;
    std::cout << std::string(120, '-') << std::endl;
    std::cout << " [ 0] Wroc do wyboru tabeli" << std::endl;
    std::cout << std::string(120, '+') << std::endl;
};
void View::companiesTableMenu()
{
    std::cout << std::string(120, '+') << std::endl;
    std::cout << "Tabela Firmy -> Wybierz akcje:" << std::endl;
    std::cout << " [ 1] Wstaw nowy wiersz do tabeli Firmy" << std::endl;
    std::cout << " [ 2] Wyswietl wiersz z tabeli Firmy" << std::endl;
    std::cout << " [ 3] Wyswietl wiersz z tabeli Firmy wraz z wierszami z powiazanych tabel" << std::endl;
    std::cout << " [ 4] Zaktualizuj wiersz w tabeli Firmy" << std::endl;
    std::cout << " [ 5] Usun wiersz z tabeli Firmy" << std::endl;
    std::cout << " [ 6] Oznacz jako usuniety wiersz z tabeli Firmy" << std::endl;
    std::cout << " [ 7] Oznacz jako nieusuniety wiersz z tabeli Firmy" << std::endl;
    std::cout << " [ 8] Wyswietl zawartosc tabeli Firmy" << std::endl;
    std::cout << " [ 9] Wyczysc zawartosc tabeli Firmy" << std::endl;
    std::cout << " [10] Sortuj zawartosc tabeli Firmy" << std::endl;
    std::cout << " [11] Przeszukaj zawartosc tabeli Firmy po wartosci logicznej" << std::endl;
    std::cout << " [12] Przeszukaj zawartosc tabeli Firmy po wartosci numerycznej" << std::endl;
    std::cout << " [13] Przeszukaj zawartosc tabeli Firmy po wartosci tekstowej" << std::endl;
    std::cout << std::string(120, '-') << std::endl;
    std::cout << " [ 0] Wroc do wyboru tabeli" << std::endl;
    std::cout << std::string(120, '+') << std::endl;
};
void View::addressesTableMenu()
{
    std::cout << std::string(120, '+') << std::endl;
    std::cout << "Tabela Adresy -> Wybierz akcje:" << std::endl;
    std::cout << " [ 1] Wstaw nowy wiersz do tabeli Adresy" << std::endl;
    std::cout << " [ 2] Wyswietl wiersz z tabeli Adresy" << std::endl;
    std::cout << " [ 3] Zaktualizuj wiersz w tabeli Adresy" << std::endl;
    std::cout << " [ 4] Usun wiersz z tabeli Adresy" << std::endl;
    std::cout << " [ 5] Oznacz jako usuniety wiersz z tabeli Adresy" << std::endl;
    std::cout << " [ 6] Oznacz jako nieusuniety wiersz z tabeli Adresy" << std::endl;
    std::cout << " [ 7] Wyswietl zawartosc tabeli Adresy" << std::endl;
    std::cout << " [ 8] Wyczysc zawartosc tabeli Adresy" << std::endl;
    std::cout << " [ 9] Sortuj zawartosc tabeli Adresy" << std::endl;
    std::cout << " [10] Przeszukaj zawartosc tabeli Firmy po wartosci logicznej" << std::endl;
    std::cout << " [11] Przeszukaj zawartosc tabeli Firmy po wartosci numerycznej" << std::endl;
    std::cout << " [12] Przeszukaj zawartosc tabeli Firmy po wartosci tekstowej" << std::endl;
    std::cout << std::string(120, '-') << std::endl;
    std::cout << " [ 0] Wroc do wyboru tabeli" << std::endl;
    std::cout << std::string(120, '+') << std::endl;
};
