#pragma once
class UserInterface
{
public:
	UserInterface();
	~UserInterface();
	void showDatabaseMenu(Controller* instance);
	void showTableMenu(Controller* instance);
};
UserInterface::UserInterface()
{
	//std::cout << "Klasa UserInterface została zaincjalizowana." << std::endl;
};
UserInterface::~UserInterface()
{
	//std::cout << "Instancja klasy UserInterface została usunięta." << std::endl;
};
void UserInterface::showDatabaseMenu(Controller* instance)
{
	if (instance->getDatabaseMenuState() == true and instance->getRunningState())
	{
		instance->databaseMenu();
		showTableMenu(instance);
	}
};
void UserInterface::showTableMenu(Controller* instance)
{
	if (instance->getTableMenuState() == true and instance->getRunningState())
	{
		instance->tableMenu(instance->userChooseFromDatabaseMenu);
	}
};
