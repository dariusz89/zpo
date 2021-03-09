#pragma once
class Client
{
public:
    int idClient;
    std::string firstName;
    std::string lastName;
    std::string email;
    bool gender;
    bool softDel;
    int companyId;
    int addressId;
    explicit Client();
    virtual ~Client();
};
Client::Client()
{
    idClient = 0;
    firstName = "";
    lastName = "";
    email = "";
    gender = false;
    softDel = false;
    companyId = 0;
    addressId = 0;
    //std::cout << "Klasa Client została zaincjalizowana." << std::endl;
};
Client::~Client()
{
    //std::cout << "Instancja klasy Client została usunięta." << std::endl;
};
