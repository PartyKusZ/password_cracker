#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class data_t{
    private:
        std::vector<std::string> dictionary; // variable for the dictionary used to crack passwords 
        std::vector<std::string> hashed_passwords; // variable for the hashed passwords to crack
        std::vector<std::string> emails; // variable for the users emails 
        std::vector<std::string> split(std::string str, std::string delimiter); // function to split a string
    public:
        data_t(const std::string &_dictionary_file_name, const std::string &_hashed_passwords_file_name);
};