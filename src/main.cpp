#include <iostream>
#include "phone.h"

int main()
{
    auto* mobilePhone = new MobilePhone;
    std::string answer;

    while (true)
    {
        std::cout << R"(Enter the "add" command to add a new contact, "call" to make a call, "sms" to send a short message, "exit" to exit the program)" << std::endl;
        std::cin >> answer;

        if (answer == "add")
        {
            mobilePhone->addContact();
        }
        else if (answer == "call")
        {
            mobilePhone->callContact();
        }
        else if (answer =="sms")
        {
            mobilePhone->sendSms();
        }
        else if (answer == "exit") break;
    }

    delete mobilePhone;
    return 0;
}
