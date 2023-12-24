#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "models.h"
#include <fstream>
#include <string.h>

class Controller {
private:
  std::string filename;

public:
  Controller(std::string filename) : filename(filename) {}

  void saveData(const Order &order) {
    std::ofstream file(filename);

    if (file.is_open()) {
      // Сохраняем данные клиента
      file << order.getClient().getFirstName() << std::endl;
      file << order.getClient().getLastName() << std::endl;
      file << order.getClient().getPhone() << std::endl;

      // Сохраняем данные продуктов в корзине
      for (unsigned int i = 0; i < order.getCartSize(); i++) {
        file << order.getCart()[i].getName() << std::endl;
        file << order.getCart()[i].getPrice() << std::endl;
        file << order.getCart()[i].getSize() << std::endl;
      }

      file.close();
    }
  }

  //  Order loadData() {
  //    Order order;

  //    std::ifstream file(filename);

  //    if (file.is_open()) {
  //       // Загружаем данные клиента
  //       std::string firstName, lastName, phone;
  //       std::getline(file, firstName);
  //       std::getline(file, lastName);
  //       std::getline(file, phone);

  //       Client client(firstName, lastName, phone);
  //       order.setClient(client);

  //       // Загружаем данные продуктов в корзине
  //       std::string name;
  //       unsigned int price, size;

  //       while (std::getline(file, name)) {
  //             file >> price;
  //             file >> size;
  //             file.ignore(); // Игнорируем символ новой строки

  //             Product product(name, price, size);
  //             order.addToCart(product);
  //       }

  //       file.close();
  //    }

  //    return order;
  // }

  std::vector<Order> loadData() {
    std::vector<Order> orders;

    std::ifstream file(filename);

    if (file.is_open()) {
      while (!file.eof()) {
        Order order;

        // Загружаем данные клиента
        std::string firstName, lastName, phone;
        std::getline(file, firstName);
        std::getline(file, lastName);
        std::getline(file, phone);

        Client client(firstName, lastName, phone);
        order.setClient(client);

        // Загружаем данные продуктов в корзине
        std::string name;
        unsigned int price, size;

        while (std::getline(file, name)) {
          file >> price;
          file >> size;
          file.ignore(); // Игнорируем символ новой строки

          Product product(name, price, size);
          order.addToCart(product);
        }

        orders.push_back(order);
      }

      file.close();
    }

    return orders;
  }
};

// class Controller {
// public:
//    Controller(Product *model) {
//       _model = model;
//    }
//    void start() {
//       _model->setName("");

//       std::string temp;
//       std::cin >> temp;
//       _model->setName(temp);
//    }
// private:
//    Product *_model;
// };

// class ProductController {
// private:
//     std::ofstream out;
// public:
// ProductController() {
//     out.open("Products.txt");
// }

// ~ProductController() {
//     out.close();
// }

// void addProduct(std::string name, unsigned int price, unsigned int size) {
//     Product item = Product(name, price, size);
//     out << "&name=" << item.getName() << "&price=" << item.getPrice() <<
//     "&size=" << item.getSize() << std::endl;
// }

// void removeProduct(std::string name) {
//     std::ifstream file_in;
//     file_in.open("Products.txt");
//     std::string line;
//     std::string line_file_text;
//     if(!file_in) std::cerr << "Ошибка, невозможно открыть файл :" <<
//     std::endl; out << "&delete=" << name << std::endl;
// }

// void editProduct() {
//     std::string name;
//     unsigned int price;
//     unsigned int size;

//     std::cin >> name;
//     std::cin >> price;
//     std::cin >> size;
//     out << "&edit=" << name << "&price=" << price << "&size=" << size <<
//     std::endl;
// }

// void removeProduct() {

// }
// };

// class ClientController {
// public:

// };

// class OrderController {
// public:

// };

#endif // CONTROLLER_H
