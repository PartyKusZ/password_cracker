#define NUM 200
#define VARIATOIN_LEN 0
#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "md5.hpp"
#include "data.hpp"
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
    void is_cracked(const std::string &hash_passwd, const std::string &to_check,std::string user, bool &is_cracked);
    void simple_check(data_t  &data, const int &start, const int &stop);
    void numeric_prefix(data_t  &data,const std::vector<std::string> &numbers ,const int &start, const int &stop);
    void numeric_postfix(data_t  &data,const std::vector<std::string> &numbers ,const int &start, const int &stop);
    void special_prefix(data_t &data,const std::vector<std::string> &specials,const int &start, const int &stop);
    void special_postfix(data_t &data,const std::vector<std::string> &specials,const int &start, const int &stop);
    void uppercase(data_t  &data, const int &start, const int &stop);

    void show_cracker_passwords(const data_t &data);

} // namespace name
