#include "passwords_crackers.hpp"

namespace password_cracker{ 
    void strings_to_attacht_t::init_numbers(){
        for(int i = 0; i < NUM; ++i){
            this->numbers.push_back(std::to_string(i));
        }
    }
    void strings_to_attacht_t::init_special(){
        
    }
}