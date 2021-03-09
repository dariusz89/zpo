#pragma once
class Address
{
public:
    int idAddress;
    std::string country;
    std::string state;
    std::string county;
    std::string community;
    std::string town;
    std::string street;
    std::string propertyNo;
    std::string apartmentNo;
    std::string postCode;
    std::string postalTown;
    bool softDel;
    explicit Address();
    virtual ~Address();
};
Address::Address()
{
    idAddress = 0;
    country = "";
    state = "";
    county = "";
    community = "";
    town = "";
    street = "";
    propertyNo = "";
    apartmentNo = "";
    postCode = "";
    postalTown = "";
    softDel = false;
    //std::cout << "Klasa Address została zaincjalizowana." << std::endl;
};
Address::~Address()
{
    //std::cout << "Instancja klasy Address została usunięta." << std::endl;
};
