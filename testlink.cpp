#include "link.hpp"


int main () {

    node_container::single::slist<int> list1;

    list1.add(4);

    list1.add(3);

    list1.add(2);

    std::cout << list1.ret_value_first();

    std::cout << list1.ret_value_last();


    // exceptions need to be added
    node_container::single::slist<int> list2;

    std::cout << list2.ret_value_last();                    // sigsegv

    std::cout << list2.ret_value_first();                   // sigsegv

    std::cout << list2.first_cpy_ret();                     // sigsegv

    std::cout << list2.last_cpy_ret();                      // sigsegv





}