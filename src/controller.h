#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <fstream>
#include <string.h>
#include "models.h"

class Controller {
public:
   Controller(Product *model) {
      _model = model;
   }
   void start() {
      _model->setName("");

      std::string temp;
      std::cin >> temp;
      _model->setName(temp);
   }
private:
   Product *_model;
};

class ProductController {
private:
    std::ofstream out;
public:
    // ProductController() {
    //     out.open("Products.txt");
    // }

    // ~ProductController() {
    //     out.close();
    // }

    // void addProduct(std::string name, unsigned int price, unsigned int size) {
    //     Product item = Product(name, price, size);
    //     out << "&name=" << item.getName() << "&price=" << item.getPrice() << "&size=" << item.getSize() << std::endl;
    // }

    // void removeProduct(std::string name) {
    //     std::ifstream file_in;
    //     file_in.open("Products.txt");
    //     std::string line;
    //     std::string line_file_text;
    //     if(!file_in) std::cerr << "Ошибка, невозможно открыть файл :" << std::endl;
    //     out << "&delete=" << name << std::endl;
    // }

    // void editProduct() {
    //     std::string name;
    //     unsigned int price;
    //     unsigned int size;

    //     std::cin >> name;
    //     std::cin >> price;
    //     std::cin >> size;
    //     out << "&edit=" << name << "&price=" << price << "&size=" << size << std::endl;
    // }

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
