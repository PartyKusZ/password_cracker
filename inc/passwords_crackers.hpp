#define NUM 200
#define VARIATOIN_LEN 3
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
namespace password_cracker{ 

    class strings_to_attacht_t{
        private:
            
            void init_numbers();
            void init_special();
        public:
            strings_to_attacht_t();
            std::vector<std::string> numbers;
            std::vector<std::string> special;
    };
    
    
} // namespace name
