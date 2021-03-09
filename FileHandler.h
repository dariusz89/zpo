#pragma once
class FileHandler
{
private:
    std::string databasePath;
protected:
    virtual ~FileHandler();
    explicit FileHandler(std::string DBpath);
    void saveDB(const std::vector<Client>& clientsTable, const std::vector<Company>& companiesTable, const std::vector<Address>& addressesTable);
    void loadDB(std::vector<Client>& clientsTable, std::vector<Company>& companiesTable, std::vector<Address>& addressesTable);
private:
    template <typename tableName>
    void saveTable(std::ofstream& out, const std::vector<tableName>& table);
    template <typename tableName>
    void serializeTable(std::ofstream& out, const std::vector<tableName>& table, const size_t& index);
    void serializeBool(std::ofstream& out, bool value);
    void serializeInt(std::ofstream& out, int value);
    void serializeString(std::ofstream& out, std::string value);
    template <typename tableName>
    void loadTable(std::ifstream& in, std::vector<tableName>& table);
    template <typename tableName>
    void deserializeTable(std::ifstream& in, std::vector<tableName>& table, const size_t& index);
    void deserializeBool(std::ifstream& in, bool& value);
    void deserializeInt(std::ifstream& in, int& value);
    void deserializeString(std::ifstream& in, std::string& value);
};
FileHandler::FileHandler(std::string DBpath)
{
    //std::cout << "Klasa FileHandler została zaincjalizowana." << std::endl;
    databasePath = DBpath;
}
FileHandler::~FileHandler()
{
    //std::cout << "Instancja klasy FileHandler została usunięta." << std::endl;
}
void FileHandler::saveDB(const std::vector<Client>& clientsTable, const std::vector<Company>& companiesTable, const std::vector<Address>& addressesTable)
{
    std::ofstream out(databasePath, std::ios::out | std::ios::binary);
    saveTable(out, clientsTable);
    saveTable(out, companiesTable);
    saveTable(out, addressesTable);
    out.close();
};
template <typename tableName>
void FileHandler::saveTable(std::ofstream& out, const std::vector<tableName>& table)
{
    typename std::vector<tableName>::size_type size = table.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        serializeTable(out, table, i);
    }
};
template <typename tableName>
void FileHandler::serializeTable(std::ofstream& out, const std::vector<tableName>& table, const size_t& index)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        serializeInt(out, table.at(index).idClient);
        serializeString(out, table.at(index).firstName);
        serializeString(out, table.at(index).lastName);
        serializeString(out, table.at(index).email);
        serializeBool(out, table.at(index).gender);
        serializeBool(out, table.at(index).softDel);
        serializeInt(out, table.at(index).companyId);
        serializeInt(out, table.at(index).addressId);
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        serializeInt(out, table.at(index).idCompany);
        serializeString(out, table.at(index).name);
        serializeString(out, table.at(index).nip);
        serializeString(out, table.at(index).regon);
        serializeString(out, table.at(index).krs);
        serializeBool(out, table.at(index).deletedFromREGON);
        serializeBool(out, table.at(index).softDel);
        serializeInt(out, table.at(index).addressId);
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        serializeInt(out, table.at(index).idAddress);
        serializeString(out, table.at(index).country);
        serializeString(out, table.at(index).state);
        serializeString(out, table.at(index).county);
        serializeString(out, table.at(index).community);
        serializeString(out, table.at(index).town);
        serializeString(out, table.at(index).street);
        serializeString(out, table.at(index).propertyNo);
        serializeString(out, table.at(index).apartmentNo);
        serializeString(out, table.at(index).postCode);
        serializeString(out, table.at(index).postalTown);
        serializeBool(out, table.at(index).softDel);
    }
};
void FileHandler::serializeBool(std::ofstream& out, bool value)
{
    out.write(reinterpret_cast<const char*>((bool*)&value), sizeof(value));
};
void FileHandler::serializeInt(std::ofstream& out, int value)
{
    out.write(reinterpret_cast<const char*>((int*)&value), sizeof(value));
};
void FileHandler::serializeString(std::ofstream& out, std::string value)
{
    std::string::size_type stringSize = value.length();
    out.write(reinterpret_cast<const char*>(&stringSize), sizeof(stringSize));
    out.write(reinterpret_cast<const char*>(value.data()), stringSize);
};
void FileHandler::loadDB(std::vector<Client>& clientsTable, std::vector<Company>& companiesTable, std::vector<Address>& addressesTable)
{
    std::ifstream in(databasePath, std::ios::in | std::ios::binary);
    loadTable(in, clientsTable);
    loadTable(in, companiesTable);
    loadTable(in, addressesTable);
    in.close();
};
template <typename tableName>
void FileHandler::loadTable(std::ifstream& in, std::vector<tableName>& table)
{
    typename std::vector<tableName>::size_type tableSize = 0;
    in.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    table.resize(tableSize);
    for (size_t i = 0; i < tableSize; i++)
    {
        deserializeTable(in, table, i);
    }
};
template <typename tableName>
void FileHandler::deserializeTable(std::ifstream& in, std::vector<tableName>& table, const size_t& index)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        deserializeInt(in, table.at(index).idClient);
        deserializeString(in, table.at(index).firstName);
        deserializeString(in, table.at(index).lastName);
        deserializeString(in, table.at(index).email);
        deserializeBool(in, table.at(index).gender);
        deserializeBool(in, table.at(index).softDel);
        deserializeInt(in, table.at(index).companyId);
        deserializeInt(in, table.at(index).addressId);
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        deserializeInt(in, table.at(index).idCompany);
        deserializeString(in, table.at(index).name);
        deserializeString(in, table.at(index).nip);
        deserializeString(in, table.at(index).regon);
        deserializeString(in, table.at(index).krs);
        deserializeBool(in, table.at(index).deletedFromREGON);
        deserializeBool(in, table.at(index).softDel);
        deserializeInt(in, table.at(index).addressId);

    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        deserializeInt(in, table.at(index).idAddress);
        deserializeString(in, table.at(index).country);
        deserializeString(in, table.at(index).state);
        deserializeString(in, table.at(index).county);
        deserializeString(in, table.at(index).community);
        deserializeString(in, table.at(index).town);
        deserializeString(in, table.at(index).street);
        deserializeString(in, table.at(index).propertyNo);
        deserializeString(in, table.at(index).apartmentNo);
        deserializeString(in, table.at(index).postCode);
        deserializeString(in, table.at(index).postalTown);
        deserializeBool(in, table.at(index).softDel);
    }
};
void FileHandler::deserializeBool(std::ifstream& in, bool& value)
{
    in.read(reinterpret_cast<char*>((bool*)&value), sizeof(value));
};
void FileHandler::deserializeInt(std::ifstream& in, int& value)
{
    in.read(reinterpret_cast<char*>((int*)&value), sizeof(value));
};
void FileHandler::deserializeString(std::ifstream& in, std::string& value)
{
    std::string::size_type stringSize = 0;
    in.read(reinterpret_cast<char*>(&stringSize), sizeof(stringSize));
    value.resize(stringSize);
    in.read(reinterpret_cast<char*>((void*)value.data()), stringSize);
};
