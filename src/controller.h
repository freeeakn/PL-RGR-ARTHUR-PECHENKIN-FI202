#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "models.h"
#include <fstream>
#include <iostream>
#include <string>

class Controller {
private:
  unsigned int length;
  Order *Orders;

public:
  Controller() {
    length = 0;
    Orders = new Order[length];
  }
  unsigned int getLength() { return length; }
  void getInfo() {
    for (unsigned int i = 0; i < length; i++)
      Orders[i].getInfo();
  }
  void newOrder() {
    Order currentOrder;
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::cout << "Write client information" << std::endl;
    std::cout << "Write FirstName:" << std::endl;
    std::cin >> firstName;
    std::cout << "Write LastName:" << std::endl;
    std::cin >> lastName;
    std::cout << "Write Phone:" << std::endl;
    std::cin >> phone;
    currentOrder.setClient(Client(firstName, lastName, phone));
    std::cout << "Order created." << std::endl;
    std::string cmd = "Y";
    std::cout << "Would you immediately add products to this order? "
                 "[\033[92mY\033[0m/\033[91mN\033[0m]\n";
    do {
      std::cin >> cmd;
      if (cmd == "Y") {
        std::string newProductName;
        unsigned int newProductPrice, newProductSize;
        std::cout << "Well, now enter the name of product: \n";
        std::cin >> newProductName;
        std::cout << "Enter the price of product: \n";
        std::cin >> newProductPrice;
        std::cout << "Enter the size of product: \n";
        std::cin >> newProductSize;
        currentOrder.addToCart(
            Product(newProductName, newProductPrice, newProductSize));
        std::cout << "Add more products to this order? "
                     "[\033[92mY\033[0m/\033[91mN\033[0m]\n";
      }
      if (cmd != "Y" && cmd != "N")
        std::cout << "\033[91mError: Unknown command\033[0m";
    } while (cmd != "N");

    Order *newOrders = new Order[length + 1];
    for (unsigned int i = 0; i < length; i++)
      newOrders[i] = Orders[i];
    newOrders[length] = currentOrder;
    length++;
    delete[] Orders;
    Orders = newOrders;
  }

  void deleteOrder(unsigned int index) {
    Order *newOrders = new Order[length - 1];
    for (unsigned int i = 0, j = 0; i < length; i++, j++) {
      if (i == (index - 1))
        i++;
      if (i < length)
        newOrders[j] = Orders[i];
    }
    length--;
    delete[] Orders;
    Orders = newOrders;
  }

  void pushOrder(Order *newOrder) {
    Order *newOrders = new Order[length + 1];
    for (unsigned int i = 0; i < length; i++)
      newOrders[i] = Orders[i];
    newOrders[length] = *newOrder;
    length++;
    delete[] Orders;
    Orders = newOrders;
  }

  void saveFile() {
    std::ofstream out;
    out.open("data.txt");
    if (out.is_open()) {
      std::string info;
      for (unsigned int i = 0; i < length; i++) {
        info = Orders[i].getClient().getFirstName() + ";" +
               Orders[i].getClient().getLastName() + ";" +
               Orders[i].getClient().getPhone() + ";";
        for (unsigned int j = 0; j < Orders[i].getCartSize(); j++) {
          info += Orders[i].getCart()[j].getName() + ";" +
                  std::to_string(Orders[i].getCart()[j].getPrice()) + ";" +
                  std::to_string(Orders[i].getCart()[j].getSize()) + ";";
        }
        out << info << std::endl;
      }
      out.close();
    }
  }

  void loadFile() {
    std::ifstream in("data.txt");
    if (in.is_open()) {
      std::string buffer;
      while (getline(in, buffer)) {
        std::string firstName = buffer.substr(0, buffer.find(";"));
        buffer = buffer.substr(buffer.find(";") + 1,
                               buffer.length() - buffer.find(";") - 1);

        std::string lastName = buffer.substr(0, buffer.find(";"));
        buffer = buffer.substr(buffer.find(";") + 1,
                               buffer.length() - buffer.find(";") - 1);

        std::string phone = buffer.substr(0, buffer.find(";"));
        buffer = buffer.substr(buffer.find(";") + 1,
                               buffer.length() - buffer.find(";") - 1);

        Order newOrder;
        newOrder.setClient(Client(firstName, lastName, phone));

        std::string temp;
        while (!buffer.empty()) {
          std::string name = buffer.substr(0, buffer.find(";"));
          buffer = buffer.substr(buffer.find(";") + 1,
                                 buffer.length() - buffer.find(";") - 1);
          unsigned int price =
              (unsigned int)std::stoi(buffer.substr(0, buffer.find(";")));
          buffer = buffer.substr(buffer.find(";") + 1,
                                 buffer.length() - buffer.find(";") - 1);
          unsigned int size =
              (unsigned int)std::stoi(buffer.substr(0, buffer.find(";")));
          buffer = buffer.substr(buffer.find(";") + 1,
                                 buffer.length() - buffer.find(";") - 1);
          newOrder.addToCart(Product(name, price, size));
        }

        pushOrder(&newOrder);
      }
    }
    in.close();
  }

  void changeOrder(unsigned const int index) {
    Orders[index - 1].getInfo();
    std::cout
        << "Is this the right order?[\033[92mY\033[0m/\033[91mN\033[0m]\n";
    std::string choice = "";
    while (choice != "Y" && choice != "N")
      std::cin >> choice;
    if (choice == "Y") {
      std::string newClientFirstName, newClientLastName, newClientPhone;
      std::cout << "Enter new first name: ";
      std::cin >> newClientFirstName;
      std::cout << "Enter new last name: ";
      std::cin >> newClientLastName;
      std::cout << "Enter new phone: ";
      std::cin >> newClientPhone;
      Orders[index - 1].setClient(
          Client(newClientFirstName, newClientLastName, newClientPhone));
    }
  }
  void removeFromCart(unsigned const int index) {
    Orders[index - 1].getInfo();
    std::cout
        << "Is this the right order? [\033[92mY\033[0m/\033[91mN\033[0m]\n";
    std::string choice = "";
    while (choice != "Y" && choice != "N")
      std::cin >> choice;
    if (choice == "Y") {
      try {
        unsigned int itemIndex = 0;
        system("clear");
        Orders[index - 1].getInfo();
        std::cout << "Enter number of item to delete: \n";
        std::cin >> itemIndex;
        if (itemIndex > Orders[index - 1].getCartSize()) {
          throw std::out_of_range("Invalid item index.");
        }
        Orders[index - 1].removeFromCart(itemIndex - 1);
        std::cout << "Product removed from the order." << std::endl;
      } catch (const std::out_of_range &e) {
        system("clear");
        std::cout << e.what() << std::endl;
      }
    }
  }

  void addToOrder(unsigned const int index) {
    Orders[index - 1].getInfo();
    std::cout
        << "Is this the right order? [\033[92mY\033[0m/\033[91mN\033[0m]\n";
    std::string choice = "";
    while (choice != "Y" && choice != "N")
      std::cin >> choice;
    if (choice == "Y") {
      std::string name;
      unsigned int price, size;
      std::cout << "Enter name of product: ";
      std::cin >> name;
      std::cout << "Enter price of product: ";
      std::cin >> price;
      std::cout << "Enter size of product(int): ";
      std::cin >> size;
      Orders[index - 1].addToCart(Product(name, price, size));
      std::cout << "Complete!";
    }
  }
};

#endif //CONTROLLER_H