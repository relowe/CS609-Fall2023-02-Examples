#ifndef MENU_H  
#define MENU_H


class Menu
{

public:
Menu();
int welcome_user(std::string companyName);
void swtich_user_cases(int user_input);
private:
std::string _companyName;
};

#endif