#pragma once
#include <string>

class Contact{
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string number;
        std::string secret;

    public:
        void        setFirstName(const std::string &s) { name = s ;}
        void        setLastName(const std::string &s) { surname = s ;}
        void        setNickname(const std::string &s) { nickname = s ;}
        void        setNumber(const std::string &s) { number = s ;}
        void        setDarkestSecret(const std::string &s) { secret = s ;}

        std::string getFirstName() const { return name ;}
        std::string getLastName() const { return surname ;}
        std::string getNickname() const { return nickname ;}
        std::string getNumber() const { return number ;}
        std::string getDarkestSecret() const { return secret ;}
};
