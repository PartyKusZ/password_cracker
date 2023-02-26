#include "data.hpp"
#include "passwords_crackers.hpp"
#include <thread>

int main(){
    data_t data("d1","h1");
    password_cracker::strings_to_attacht_t strings;
    int start = 0;
    int stop = data.hashed_passwords.size();
    std::thread t3(password_cracker::show_cracker_passwords,std::cref(data));   
    std::thread t1(password_cracker::simple_check,std::ref(data),std::cref(start),std::cref(stop));
    std::thread t2(password_cracker::uppercase,std::ref(data),std::cref(start),std::cref(stop));
    t1.join();
    t2.join();
    t3.join();
}
