#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <fstream>
#include <string.h>
#include "models.h"

class ProductController {
private:
    std::ofstream out;
public:
    ProductController() {
        out.open("Products.txt");
    }

    ~ProductController() {
        out.close();
    }

    void addProduct() {
        std::string name;
        unsigned int price;
        unsigned int size;

        std::cin >> name;
        std::cin >> price;
        std::cin >> size;
        Product item = Product(name, price, size);
        out << "&name=" << item.getName() << "&price=" << item.getPrice() << "&size=" << item.getSize() << std::endl;
    }

    // void removeProduct() {

    // }
};

// class ClientController {
// public:

// };

// class OrderController {
// public:

// };

#endif //CONTROLLER_H
