#define NUM 200
#define VARIATOIN_LEN 0
#include <vector>
#include <string>
namespace password_cracker{ 

    class strings_to_attacht_t{
        private:
            std::vector<std::string> numbers;
            std::vector<std::string> special;
            void init_numbers();
            void init_special();
        public:
            strings_to_attacht_t();
    };
    
} // namespace name
