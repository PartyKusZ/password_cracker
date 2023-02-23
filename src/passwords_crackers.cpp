#include "passwords_crackers.hpp"

const std::string special_characters = " ~`!@#$%^&*()_+-={}\\|; :'\",<.>/?"; //

namespace password_cracker{ 

    void strings_to_attacht_t::init_numbers(){
        for(int i = 0; i < NUM; ++i){
            this->numbers.push_back(std::to_string(i));
            this->numbers.back().shrink_to_fit();
        }
    }

    void strings_to_attacht_t::init_special(){

        for (int length = 1; length <= VARIATOIN_LEN; length++) {
            std::string variation(length, special_characters[0]);
            this->special.push_back(variation);
            this->special.back().shrink_to_fit();

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
            }
        }
    }

    strings_to_attacht_t::strings_to_attacht_t(){
        this->init_numbers();
        this->init_special();
        
    }
}