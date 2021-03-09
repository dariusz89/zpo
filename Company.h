#pragma once
class Company
{
public:
    int idCompany;
    std::string name;
    std::string nip;
    std::string regon;
    std::string krs;
    bool deletedFromREGON;
    bool softDel;
    int addressId;
    explicit Company();
    virtual ~Company();
};
Company::Company()
{
    idCompany = 0;
    name = "";
    nip = "";
    regon = "";
    krs = "";
    deletedFromREGON = false;
    softDel = false;
    addressId = 0;
    //std::cout << "Klasa Company została zaincjalizowana." << std::endl;
};
Company::~Company()
{
    //std::cout << "Instancja klasy Company została usunięta." << std::endl;
};
