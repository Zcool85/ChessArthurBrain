#ifndef _MISC_HPP_
#define _MISC_HPP_

#include <iostream>
#include <string>
#include <mutex>

void send_line(const std::string& s) {
    static std::mutex io_mutex;
    {
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << s << std::endl;
    }
}

#endif // _MISC_HPP_
