#ifndef VIEW_H
#define VIEW_H

#include "models.h"
#include "controller.h"
#include <iostream>

class View {
private:
  Controller shop;

public:
  View() { shop.loadFile(); }
  ~View() { shop.saveFile(); }

  void printMenu() {
    system("clear");
    std::cout << "=== Menu ===\n";
    std::cout << "1. Print All Orders\n";
    std::cout << "2. Create Order\n";
    std::cout << "3. Edit Order\n";
    std::cout << "4. Remove Product from Order\n";
    std::cout << "5. Delete order\n";
    std::cout << "6. Add product to some Order\n";
    std::cout << "7. Exit\n";
    std::cout << "============\n";
    std::cout << "Enter your choice: ";
  }

  void execute() {
    unsigned int choice = 0, indexForChange = 0, indexForRemoveProduct = 0,
                 indexForDel = 0, indexForAdd = 0;
    while (choice != 7) {
      printMenu();
      std::cin >> choice;
      std::cin.ignore();
      switch (choice) {
      case 1:
        system("clear");
        shop.getInfo();
        break;
      case 2:
        system("clear");
        shop.newOrder();
        break;
      case 3:
        system("clear");
        std::cout << "Select order number to edit\n";
        while (indexForChange < 1 || indexForChange > shop.getLength()) {
          shop.getInfo();
          std::cin >> indexForChange;
        }
        shop.changeOrder(indexForChange);
        std::cout << "Order information has changed\n";
        break;
      case 4:
        system("clear");
        shop.getInfo();
        std::cout << "Enter the number of the order to remove: ";
        while (indexForRemoveProduct < 1 ||
               indexForRemoveProduct > shop.getLength()) {
          std::cin >> indexForRemoveProduct;
        }
        shop.removeFromCart(indexForRemoveProduct);
        std::cout << "Product has been removed!\n";
        break;
      case 5:
        system("clear");
        shop.getInfo();
        std::cout << "Select order number to delete\n";
        while (indexForDel < 1 || indexForDel > shop.getLength()) {
          std::cin >> indexForDel;
        }
        shop.deleteOrder(indexForDel);
        std::cout << "Order has been removed\n";
        break;
      case 6:
        system("clear");
        shop.getInfo();
        std::cout << "Select order number to add product\n";
        while (indexForAdd < 1 || indexForAdd > shop.getLength()) {
          std::cin >> indexForAdd;
        }
        shop.addToOrder(indexForAdd);
        break;
      case 7:
        std::cout << "Exiting...\n";
        break;
      default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
      }
      std::cout << std::endl;
    }
  }
};

#endif // VIEW_H