#include <iostream>

namespace node_container {

template <typename T>
struct node {

    T data;
    node* next = nullptr;
    node* previus = nullptr;

    node (T Data, node<T>* nnode) : data(Data), next(nnode) {std::cout << "constructor called, direct initilizer";}

    node (T Data, node<T> nnode, node<T> n2node) : data(Data), next(nnode), previus(n2node) {

        std::cout << "constructor called, direct initilizer, include_previus link = true\n";
    }

    node (T Data) : data(Data) {std::cout << "constructor called, direct, include_link = false\n";}

    node () {std::cout << "default constructor called\n";}

//    const T& cost_ref_ret () const {return data;}
//    T& ref_ret () {return data;}

}; // end of S node


namespace single {


template <typename T>
class slist {

    node<T>* head = nullptr;

public:

    slist () : head(nullptr) {}

    slist (const slist<T>& cpy_from) {

        if (cpy_from.next != nullptr) this->next = cpy_from.next;

//        try {this->next = cpy_from.data; throw std::runtime_error};

        this->next = cpy_from.data;
    }

    T ret_value_first () {return head->data;}

    T ret_value_last () {

        node<T>* temp = this->head;
        while (temp->next != nullptr) {

            temp = temp->next;
        }
        return temp->data;
    }

    T ret_value_next () {


    }

    node<T>* first_cpy_ret () {if (head != nullptr) return head;}               // assignable

    node<T>* last_cpy_ret () {                                                  // assignable

        node<T>* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

    void add (T data) {

        if (head != nullptr) {

            node<T>* temp = this->head;
            while (temp->next != nullptr) {

                temp = temp->next;                       // temp node to equal the current nodes state, stop loop, when nullptr gets assigned
            }

            auto *append = new node<T>(data);      // create a new node
            temp->next = append;                   // assign the new node to the last nodes next address
        }

        if (head == nullptr) {this->head = new node<T> (data);}
    }

}; // end of C slist

}

} // end of N link

/*
 * assignment constructor
 * inbuilt iteration methods of sorts, so we can utilize container without the use of an iterator object
 * cleanup
 * other types
 * exception handling
 *
 *
 *
 * make it comply with c container interface
 * make use of standard iterator class to make custom iterator
 *
 */

/* improvement 1
 *
 * reorginized, to naming it a node based container, with a single link version included so far
 *
 * node struct becomes seperated from single link, with it being useful with double link verison, added a previus link and constructors
 *
 *
 *
 */