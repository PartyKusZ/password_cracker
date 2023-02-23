#include "data.hpp"

std::vector<std::string>  data_t::split(std::string str, std::string delimiter){
    std::vector<std::string> result;
    int pos;
    while((pos = str.find_first_of(delimiter)) != std::string::npos){
        std :: string substr = str.substr(0, pos);
        str.erase(0,pos + 1);
        result.push_back(substr);
    }
    result.push_back(str);
    return result;
}
data_t::data_t(const std::string &_dictionary_file_name, const std::string &_hashed_passwords_file_name){

    std::string tmp_line;

    std::fstream dictionary_file;
    std::fstream hashed_passwords_file;

    dictionary_file.open(_dictionary_file_name.c_str(), std::ios::in);

    if(dictionary_file.is_open()){
        while(std::getline(dictionary_file, tmp_line)){
        this->dictionary.push_back(tmp_line);
        }
    }else{
        std::cerr << "Cannot open dictionary file" << std::endl;
        exit(-1);
    }
    dictionary_file.close();

    hashed_passwords_file.open(_hashed_passwords_file_name.c_str());

    if(hashed_passwords_file.is_open()){
        while(std::getline(hashed_passwords_file, tmp_line)){
            auto splited_line = this->split(tmp_line," ");
            this->hashed_passwords.push_back({splited_line[1]});
            this->emails.push_back({splited_line[2]});
        }
    }else{
        std::cerr << "Cannot open hashed passwords file" << std :: endl;
    }
    hashed_passwords_file.close();
}