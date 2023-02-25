#include "passwords_crackers.hpp"

const std::string special_characters = "~`!@#$%^&*()_+-={}\\|; :'\",<.>/?"; // 

namespace password_cracker{ 

    void strings_to_attacht_t::init_numbers(){
        for(int i = 0; i < NUM; ++i){
            this->numbers.push_back(std::to_string(i));
            this->numbers.back().shrink_to_fit();
        }
        this->numbers.shrink_to_fit();
    }

    void strings_to_attacht_t::init_special(){

        for (int length = 1; length <= VARIATOIN_LEN; length++) {
            std::string variation(length, special_characters[0]);
            this->special.push_back(variation);
            //this->special.back().shrink_to_fit();
            
           // std::cout << this->special.back() << std::endl; 
            while(true){
                int i = length - 1;
                while(i >= 0 && variation[i] == special_characters[special_characters.length() - 1]){
                    i--;
                }

                if(i < 0){
                    break;
                }

                int index = special_characters.find(variation[i]);
                variation[i] = special_characters[index + 1];

                for(int j = i + 1; j < length; j++){
                    variation[j] = special_characters[0];
                }

                this->special.push_back(variation);
                this->special.back().shrink_to_fit();
                //std::cout << this->special.back() << std::endl; 
                

            }
        }
        this->special.shrink_to_fit();
      
    }

    strings_to_attacht_t::strings_to_attacht_t(){
        this->init_numbers();
        this->init_special();
        
    }


    bool is_cracked(const std::string &hash_passwd, const std::string &to_check){
        std::string hash_to_check = md5(to_check);
        if(hash_passwd == hash_to_check)
            return true;
        else
            return false;
    }

    void simple_check(data_t  &data,const int &start, const int &stop){
        for(int i = start; i < stop; ++i){
            for(int j = 0; j < data.dictionary.size() && !data.hashed_passwords[i].is_cracked; ++j){
                data.hashed_passwords[i].is_cracked = is_cracked(data.hashed_passwords[i].passwd,data.dictionary[j]);
            }
        }
    }

    void numeric_prefix(data_t  &data,const std::vector<std::string> &numbers ,const int &start, const int &stop){
        std::string tmp;
        for(int i = start; i < stop; ++i){
            for(int j = 0; j < data.dictionary.size() && !data.hashed_passwords[i].is_cracked; ++j){
                for(int k = 0; k < numbers.size() && !data.hashed_passwords[i].is_cracked; ++k){
                    tmp = numbers[k] + data.dictionary[j];
                    std::cout << tmp << std::endl;
                    data.hashed_passwords[i].is_cracked = is_cracked(data.hashed_passwords[i].passwd, tmp);

                }
            }
        }
    }
    void numeric_postfix(data_t  &data,const std::vector<std::string> &numbers ,const int &start, const int &stop){
        std::string tmp;
        for(int i = start; i < stop; ++i){
            for(int j = 0; j < data.dictionary.size() && !data.hashed_passwords[i].is_cracked; ++j){
                for(int k = 0; k < numbers.size() && !data.hashed_passwords[i].is_cracked; ++k){
                    tmp = data.dictionary[j] + numbers[k];
                    std::cout << tmp << std::endl;

                    data.hashed_passwords[i].is_cracked = is_cracked(data.hashed_passwords[i].passwd,tmp);

                }
            }
        }
    }

    void special_prefix(data_t &data,const std::vector<std::string> &specials,const int &start, const int &stop){
        std::string tmp;
        for(int i = start; i < stop; ++i){
            for(int j = 0; j < data.dictionary.size() && !data.hashed_passwords[i].is_cracked; ++j){
                for(int k = 0; k < specials.size() && !data.hashed_passwords[i].is_cracked; ++k){
                    tmp = specials[k] + data.dictionary[j];
                    std::cout << tmp << std::endl;

                    data.hashed_passwords[i].is_cracked = is_cracked(data.hashed_passwords[i].passwd,tmp);
                }
            }
        }
    }
    void special_postfix(data_t &data,const std::vector<std::string> &specials,const int &start, const int &stop){
        std::string tmp;
        for(int i = start; i < stop; ++i){
            for(int j = 0; j < data.dictionary.size() && !data.hashed_passwords[i].is_cracked; ++j){
                for(int k = 0; k < specials.size() && !data.hashed_passwords[i].is_cracked; ++k){
                    tmp = data.dictionary[j] + specials[k];
                    std::cout << tmp << std::endl;

                    data.hashed_passwords[i].is_cracked = is_cracked(data.hashed_passwords[i].passwd,tmp);
                }
            }
        }
    }
    
    void uppercase(data_t  &data, const int &start, const int &stop){
        std::string tmp;
        for(int i = start; i < stop; ++i){
            for(int j = 0; j < data.dictionary.size() && !data.hashed_passwords[i].is_cracked; ++j){
                tmp = data.dictionary[j];
                for(int k = 1; k < (1 << data.dictionary[j].length()); ++k){
                    for(int l = 0; l < data.dictionary[j].length(); ++l){
                        if(k & (1 << l))
                            tmp[l] = std::toupper(tmp[l]);
                        else
                            tmp[l] = std::tolower(tmp[l]);
 
                    }
                std::cout << tmp << std::endl;

                data.hashed_passwords[i].is_cracked = is_cracked(data.hashed_passwords[i].passwd,tmp);
                }
            }
        }

    }
}