#pragma once
class Model :
    protected Client,
    protected Company,
    protected Address
{
protected:
    std::vector<Client> clients;
    std::vector<Company> companies;
    std::vector<Address> addresses;
    using Client::Client;
    using Company::Company;
    using Address::Address;
protected:
    explicit Model();
    virtual ~Model();
    template <typename tableName>
    void truncateTable(std::vector<tableName>& table);
    template <typename tableName>
    void updateRow(tableName& row, tableName& newValue);
    template <typename tableName>
    void insertRow(std::vector<tableName>& table, const tableName& newRow);
    template <typename tableName, typename tableIterator>
    void deleteRow(std::vector<tableName>& table, tableIterator position);
    template <typename tableName>
    void softDeleteRow(tableName& row);
    template <typename tableName>
    void undoSoftDeleteRow(tableName& row);
    template <typename tableName>
    void sortTableBy(std::vector<tableName>& table, int columnName = 0, bool order = true);
    template <typename tableName>
    typename std::vector<tableName>::iterator findRowInTableByIndex(std::vector<tableName>& table, const int& index);
    template <typename tableName, typename columnType>
    typename std::vector<tableName> findAllRowsInTableByValue(std::vector<tableName> table, int colNo, columnType value);

};
Model::Model()
{
    //std::cout << "Klasa Model została zaincjalizowana." << std::endl;
};
Model::~Model()
{
    //std::cout << "Instancja klasy Model została usunięta." << std::endl;
};
template <typename tableName>
void Model::truncateTable(std::vector<tableName>& table)
{
    table.clear();
};
template <typename tableName>
void Model::updateRow(tableName& row, tableName& newValue)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        row.firstName = newValue.firstName;
        row.lastName = newValue.lastName;
        row.email = newValue.email;
        row.gender = newValue.gender;
        row.companyId = newValue.companyId;
        row.addressId = newValue.addressId;
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        row.name = newValue.name;
        row.nip = newValue.nip;
        row.regon = newValue.regon;
        row.krs = newValue.krs;
        row.deletedFromREGON = newValue.deletedFromREGON;
        row.addressId = newValue.addressId;
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        row.state = newValue.state;
        row.county = newValue.county;
        row.community = newValue.community;
        row.town = newValue.town;
        row.street = newValue.street;
        row.propertyNo = newValue.propertyNo;
        row.apartmentNo = newValue.apartmentNo;
        row.postCode = newValue.postCode;
        row.postalTown = newValue.postalTown;
    }
};
template <typename tableName>
void Model::insertRow(std::vector<tableName>& table, const tableName& newRow)
{
    table.push_back(newRow);
};
template <typename tableName, typename tableIterator>
void Model::deleteRow(std::vector<tableName>& table, tableIterator position)
{
    table.erase(position);
};
template <typename tableName>
void Model::softDeleteRow(tableName& row)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        row.softDel = true;
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        row.softDel = true;
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        row.softDel = true;
    }
};
template <typename tableName>
void Model::undoSoftDeleteRow(tableName& row)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        row.softDel = false;
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        row.softDel = false;
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        row.softDel = false;
    }
};
template <typename tableName>
void Model::sortTableBy(std::vector<tableName>& table, int columnName, bool order)
{
    std::sort(table.begin(), table.end(), [columnName, order](tableName const& left, tableName const& right)
        {
            bool result;
            if constexpr (std::is_same<tableName, Client>::value)
            {
                switch (columnName)
                {
                case 1:
                    result = (order) ? left.firstName < right.firstName : left.firstName > right.firstName;
                    break;
                case 2:
                    result = (order) ? left.lastName < right.lastName : left.lastName > right.lastName;
                    break;
                case 3:
                    result = (order) ? left.email < right.email : left.email > right.email;
                    break;
                case 4:
                    result = (order) ? left.gender < right.gender : left.gender > right.gender;
                    break;
                case 5:
                    result = (order) ? left.softDel < right.softDel : left.softDel > right.softDel;
                    break;
                case 6:
                    result = (order) ? left.companyId < right.companyId : left.companyId > right.companyId;
                    break;
                case 7:
                    result = (order) ? left.addressId < right.addressId : left.addressId > right.addressId;
                    break;
                default:
                    result = (order) ? left.idClient < right.idClient : left.idClient > right.idClient;
                    break;
                }
                return result;
            }
            else if constexpr (std::is_same<tableName, Company>::value)
            {
                switch (columnName)
                {
                case 1:
                    result = (order) ? left.name < right.name : left.name > right.name;
                    break;
                case 2:
                    result = (order) ? left.nip < right.nip : left.nip > right.nip;
                    break;
                case 3:
                    result = (order) ? left.regon < right.regon : left.regon > right.regon;
                    break;
                case 4:
                    result = (order) ? left.krs < right.krs : left.krs > right.krs;
                    break;
                case 5:
                    result = (order) ? left.deletedFromREGON < right.deletedFromREGON : left.deletedFromREGON > right.deletedFromREGON;
                    break;
                case 6:
                    result = (order) ? left.softDel < right.softDel : left.softDel > right.softDel;
                    break;
                case 7:
                    result = (order) ? left.addressId < right.addressId : left.addressId > right.addressId;
                    break;
                default:
                    result = (order) ? left.idCompany < right.idCompany : left.idCompany > right.idCompany;
                    break;
                }
                return result;
            }
            else if constexpr (std::is_same<tableName, Address>::value)
            {
                switch (columnName)
                {
                case 1:
                    result = (order) ? left.country < right.country : left.country > right.country;
                    break;
                case 2:
                    result = (order) ? left.state < right.state : left.state > right.state;
                    break;
                case 3:
                    result = (order) ? left.county < right.county : left.county > right.county;
                    break;
                case 4:
                    result = (order) ? left.community < right.community : left.community > right.community;
                    break;
                case 5:
                    result = (order) ? left.town < right.town : left.town > right.town;
                    break;
                case 6:
                    result = (order) ? left.street < right.street : left.street > right.street;
                    break;
                case 7:
                    result = (order) ? left.propertyNo < right.propertyNo : left.propertyNo > right.propertyNo;
                    break;
                case 8:
                    result = (order) ? left.apartmentNo < right.apartmentNo : left.apartmentNo > right.apartmentNo;
                    break;
                case 9:
                    result = (order) ? left.postCode < right.postCode : left.postCode > right.postCode;
                    break;
                case 10:
                    result = (order) ? left.postalTown < right.postalTown : left.postalTown > right.postalTown;
                    break;
                case 11:
                    result = (order) ? left.softDel < right.softDel : left.softDel > right.softDel;
                    break;
                default:
                    result = (order) ? left.idAddress < right.idAddress : left.idAddress > right.idAddress;
                    break;
                }
                return result;
            }
        });
};
template <typename tableName>
typename std::vector<tableName>::iterator Model::findRowInTableByIndex(std::vector<tableName>& table, const int& index)
{
    typename std::vector<tableName>::iterator row;
    row = std::find_if(table.begin(), table.end(), [index](tableName const& result)
        {
            if constexpr (std::is_same<tableName, Client>::value)
            {
                return result.idClient == index;
            }
            else if constexpr (std::is_same<tableName, Company>::value)
            {
                return result.idCompany == index;
            }
            else if constexpr (std::is_same<tableName, Address>::value)
            {
                return result.idAddress == index;
            }
        });
    return row;
};
template <typename tableName, typename columnType>
typename std::vector<tableName> Model::findAllRowsInTableByValue(std::vector<tableName> table, int colNo, columnType value)
{
    typename std::vector<tableName> temp;
    for (auto i = table.begin(), limit = table.end(); i != limit; ++i)
    {
        if constexpr (std::is_same<tableName, Client>::value && std::is_same<columnType, std::string>::value)
        {
            switch (colNo)
            {
            case 1:
                if (i->firstName == value) temp.push_back(*i);
                break;
            case 2:
                if (i->lastName == value) temp.push_back(*i);
                break;
            case 3:
                if (i->email == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Client>::value && std::is_same<columnType, bool>::value)
        {
            switch (colNo)
            {
            case 4:
                if (i->gender == value) temp.push_back(*i);
                break;
            case 5:
                if (i->softDel == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Client>::value && std::is_same<columnType, int>::value)
        {
            switch (colNo)
            {
            case 6:
                if (i->companyId == value) temp.push_back(*i);
                break;
            case 7:
                if (i->addressId == value) temp.push_back(*i);
                break;
            case 0:
                if (i->idClient == value) temp.push_back(*i);
                break;
            default:
                if (i->idClient == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Company>::value && std::is_same<columnType, std::string>::value)
        {
            switch (colNo)
            {
            case 1:
                if (i->name == value) temp.push_back(*i);
                break;
            case 2:
                if (i->nip == value) temp.push_back(*i);
                break;
            case 3:
                if (i->regon == value) temp.push_back(*i);
                break;
            case 4:
                if (i->krs == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Company>::value && std::is_same<columnType, bool>::value)
        {
            switch (colNo)
            {
            case 5:
                if (i->deletedFromREGON == value) temp.push_back(*i);
                break;
            case 6:
                if (i->softDel == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Company>::value && std::is_same<columnType, int>::value)
        {
            switch (colNo)
            {
            case 7:
                if (i->addressId == value) temp.push_back(*i);
                break;
            case 0:
                if (i->idCompany == value) temp.push_back(*i);
                break;
            default:
                if (i->idCompany == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Address>::value && std::is_same<columnType, std::string>::value)
        {
            switch (colNo)
            {
            case 1:
                if (i->country == value) temp.push_back(*i);
                break;
            case 2:
                if (i->state == value) temp.push_back(*i);
                break;
            case 3:
                if (i->county == value) temp.push_back(*i);
                break;
            case 4:
                if (i->community == value) temp.push_back(*i);
                break;
            case 5:
                if (i->town == value) temp.push_back(*i);
                break;
            case 6:
                if (i->street == value) temp.push_back(*i);
                break;
            case 7:
                if (i->propertyNo == value) temp.push_back(*i);
                break;
            case 8:
                if (i->apartmentNo == value) temp.push_back(*i);
                break;
            case 9:
                if (i->postCode == value) temp.push_back(*i);
                break;
            case 10:
                if (i->postalTown == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Address>::value && std::is_same<columnType, bool>::value)
        {
            switch (colNo)
            {
            case 11:
                if (i->softDel == value) temp.push_back(*i);
                break;
            }
        }
        else if constexpr (std::is_same<tableName, Address>::value && std::is_same<columnType, int>::value)
        {
            switch (colNo)
            {
            case 0:
                if (i->idAddress == value) temp.push_back(*i);
                break;
            default:
                if (i->idAddress == value) temp.push_back(*i);
                break;
            }
        }
    }
    return temp;
};
