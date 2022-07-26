#pragma once

#include <iostream>
#include <vector>

class MobilePhone
{
    class Contact
    {
        std::string nameContact;
        std::string phoneNumber;
    public:
        void setAddContact(std::string& name, std::string& number)
        {
            nameContact = name;
            phoneNumber = number;
        }
        std::string getNameContact()
        {
            return nameContact;
        }
        std::string getPhoneNumber()
        {
            return phoneNumber;
        }
    };

    std::vector<Contact> contactList;

public:

    int findContact()
    {
        std::string answer;
        std::cout << "Enter the contact's name or phone number in the format +7<10 digit>: ";
        std::cin >> answer;

        if (contactList.empty())
        {
            return -1;
        }
        else
        {
            for (int i = 0; i < contactList.size(); ++i)
            {
                if (answer == contactList[i].getNameContact() || answer == contactList[i].getPhoneNumber())
                {
                    return i;
                }
            }
        }
        return -2;
    }

    void addContact()
    {
        auto* tmpContact = new Contact;

        std::string nameContact;
        std::string numberContact;
        std::cout << "Enter a name: ";
        std::cin >> nameContact;
        std::cout << "Enter the phone number in the format +7<10 digit>: ";
        std::cin >> numberContact;

        tmpContact->setAddContact(nameContact, numberContact);
        contactList.push_back(*tmpContact);

        delete tmpContact;
    }
    void callContact()
    {
        int find = findContact();
        if (find == -1)
        {
            std::cout << "The address book is empty." << std::endl;
        }
        else if (find == -2)
        {
            std::cout << "Record not found." << std::endl;
        }
        else
        {
            std::cout << "***************" << std::endl;
            std::cout << "Call " << contactList[find].getNameContact() << " to the number: " << contactList[find].getPhoneNumber() << std::endl;
            std::cout << "***************" << std::endl;
        }
    }
    void sendSms()
    {
        int find = findContact();
        if (find == -1)
        {
            std::cout << "The address book is empty." << std::endl;
        }
        else if (find == -2)
        {
            std::cout << "Record not found." << std::endl;
        }
        else
        {
            std::string text;
            std::cout << "Enter the message text" << std::endl << "<- ";
            std::cin >> text;
            std::cout << "***************" << std::endl;
            std::cout << "Send SMS" << std::endl;
            std::cout << "***************" << std::endl;
            std::cout << "to: " << contactList[find].getNameContact() << std::endl;
            std::cout << "number: " << contactList[find].getPhoneNumber() << std::endl;
            std::cout << "***************" << std::endl;
            std::cout << "Text: " << text << std::endl;
            std::cout << "***************" << std::endl;
        }
    }
};
