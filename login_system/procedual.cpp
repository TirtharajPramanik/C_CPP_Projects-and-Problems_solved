#include <iostream>
#include <fstream>
#include <string>

void signup();

void login();

int main()
{
    int tries = 3;
    char signedin;
    std::cout << "[*] Do you have a account? (y/n):    " << std::endl;
    while (tries)
    {
        std::string input;
        std::getline(std::cin, input);
        if (input.length() > 1)
        {
            signedin = 0;
        }
        else
        {
            signedin = input[0];
        }
        switch (signedin)
        {
        case 'y':
            std::cout << "[+] Allright! You gotta login!" << std::endl;
            login();
            return 0;
        case 'n':
            std::cout << "[+] Allright! You gotta signup!" << std::endl;
            signup();
            return 0;
        default:
            tries--;
            if (tries)
            {
                std::cout << "[-] Type `y` if yes; else type `n` :    " << std::endl;
            }
            break;
        }
    }
    std::cout << "[-] Oops! Too may ties! Exiting programme!" << std::endl;
    return 0;
}

void signup()
{
    std::string username;
    std::string password;
    int tries = 3;
    std::cout << "[*] Enter your name:  " << std::endl;
    while (tries)
    {
        std::cin >> username;
        if (username.length() >= 4)
        {
            if (username.find(':') < username.length())
            {
                std::cout << "[-] Oops! Usernames cannot contain `:`!" << std::endl;
                tries--;
                break;
            }
            int tries = 3;
            std::cout << "[*] Enter new password:  " << std::endl;
            while (tries)
            {
                std::cin >> password;
                if (password.length() >= 4)
                {
                    if (password.find(':') < username.length())
                    {
                        std::cout << "[-] Oops! Passwords cannot contain `:`!" << std::endl;
                        tries--;
                        break;
                    }
                    std::ofstream users("users.txt", std::ios::app);
                    users << username << ':' << password << std::endl;
                    users.close();
                    std::cout << "[+] Congrats! You have created your new account!" << std::endl;
                    return;
                }
                else
                {
                    tries--;
                    if (tries)
                    {
                        std::cout << "[-] Oops! Password field too short!" << std::endl;
                    }
                }
            }
            std::cout << "[-] Oops! Password field cannot be empty!" << std::endl;
            tries = 0;
            break;
        }
        else
        {
            tries--;
            if (tries)
            {
                std::cout << "[-] Oops! Name field too short!" << std::endl;
            }
        }
    }
    std::cout << "[-] Oops! Name field cannot be empty!" << std::endl;
    std::cout << "[-] Oops! Signing up failed!" << std::endl;
}

void login()
{
    int tries = 3;
    std::string loginname;
    std::cout << "[*] Enter your name:  " << std::endl;
    while (tries)
    {
        std::cin >> loginname;
        if (loginname.length() >= 4)
        {
            break;
        }
        tries--;
        if (tries)
        {
            std::cout << "[-] Name is too short!" << std::endl;
        }
    }
    std::string user;
    std::ifstream users("users.txt");
    if (!users.is_open())
    {
        std::cout << "[-] No users Exist! Please signup!" << std::endl;
        users.close();
        return;
    }
    while (users.good())
    {
        std::getline(users, user);
        if (!user.length())
        {
            break;
        }
        std::string username = user.substr(0, user.find(':'));
        std::string password = user.substr(user.find(':') + 1);
        if (username == loginname)
        {
            tries = 3;
            std::cout << "[*] Enter your password!" << std::endl;
            std::string loginpassword;
            while (tries)
            {
                std::cin >> loginpassword;
                if (loginpassword.length() < 4)
                {
                    tries--;
                    if (tries)
                    {
                        std::cout << "[-] Oops! Password too short!" << std::endl;
                        std::cout << "[-] Retry!" << std::endl;
                    }
                }
                else
                {
                    tries = 0;
                    break;
                }
            }
            if (loginpassword != password)
            {
                std::cout << "[-] Oops! Pasword is incorrect!" << std::endl;
            }
            else
            {
                std::cout << "[+] Congrats! You are logedin!" << std::endl;
            }
            users.close();
            return;
        }
    }
    std::cout << "[-] Oops! You do not have an active account!" << std::endl;
    users.close();
}