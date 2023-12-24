#ifndef VIEWS_H
#define VIEWS_H

#include "controller.h"
#include "models.h"
#include <iostream>

class View : public Observer {
private:
  Product *_model;

public:
  View() {}
  View(Product *model) {
    _model = model;
    _model->addObserver(this);
  }

  virtual void update() {
    system("clear");
    std::cout << "Name of product:" << _model->getName() << std::endl;
    printf("Price of product: %.2u\n", _model->getPrice());
    printf("Size: %.2u\n", _model->getSize());
    printf("Input name: ");
  }

  void printMenu() {
    std::cout << "=== Menu ===" << std::endl;
    std::cout << "1. Create Order" << std::endl;
    std::cout << "2. Add Product to Order" << std::endl;
    std::cout << "3. Remove Product from Order" << std::endl;
    std::cout << "4. Set Client for Order" << std::endl;
    std::cout << "5. Print All Products" << std::endl;
    std::cout << "6. Print All Orders" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "============" << std::endl;
    std::cout << "Enter your choice: ";
  }

  void execute() {
    Controller controller("data.txt");

    Order order;
    std::vector<Product> products;

    int choice = 0;
    while (choice != 7) {
      printMenu();
      std::cin >> choice;
      std::cin.ignore(); // Игнорируем символ новой строки

      switch (choice) {
      case 1: {
        // Создание заказа
        order = Order();
        std::cout << "Order created." << std::endl;
        break;
      }
      case 2: {
        // Добавление продукта в заказ
        std::string name;
        unsigned int price, size;

        std::cout << "Enter product name: ";
        std::getline(std::cin, name);

        std::cout << "Enter product price: ";
        std::cin >> price;

        std::cout << "Enter product size: ";
        std::cin >> size;

        Product product(name, price, size);
        order.addToCart(product);

        std::cout << "Product added to the order." << std::endl;
        break;
      }
      case 3: {
        // Удаление продукта из заказа
        unsigned int index;

        std::cout << "Enter the index of the product to remove: ";
        std::cin >> index;

        try {
          order.removeFromCart(index - 1);
          std::cout << "Product removed from the order." << std::endl;
        } catch (const std::out_of_range &e) {
          std::cout << "Invalid index. Please try again." << std::endl;
        }

        break;
      }
      case 4: {
        // Установка клиента для заказа
        std::string firstName, lastName, phone;

        std::cout << "Enter client's first name: ";
        std::getline(std::cin, firstName);

        std::cout << "Enter client's last name: ";
        std::getline(std::cin, lastName);

        std::cout << "Enter client's phone number: ";
        std::getline(std::cin, phone);

        Client client(firstName, lastName, phone);
        order.setClient(client);

        std::cout << "Client set for the order." << std::endl;
        break;
      }
      case 5: {
        // Вывод всех продуктов
        std::cout << "All Products:" << std::endl;
        for (const auto &product : products) {
          std::cout << "Name: " << product.getName()
                    << ", Price: " << product.getPrice()
                    << ", Size: " << product.getSize() << std::endl;
        }
        break;
      }
      case 6: {
        // Вывод всех заказов
        std::cout << "All Orders:" << std::endl;
        // Загружаем данные всех заказов
        std::vector<Order> orders = controller.loadData();

        for (const auto &order : orders) {
          std::cout << "Client: " << order.getClient().getFirstName() << " "
                    << order.getClient().getLastName() << std::endl;

          std::cout << "Cart:" << std::endl;
          for (unsigned int i = 0; i < order.getCartSize(); i++) {
            std::cout << "Product " << i + 1 << ": "
                      << order.getCart()[i].getName()
                      << ", Price: " << order.getCart()[i].getPrice()
                      << ", Size: " << order.getCart()[i].getSize()
                      << std::endl;
          }

          std::cout << std::endl;
        }
        break;
      }
      case 7: {
        // Выход из программы
        std::cout << "Exiting..." << std::endl;
        break;
      }
      default: {
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
      }
      }

      std::cout << std::endl;
    }

    // Сохраняем данные заказа перед выходом
    controller.saveData(order);

    // Освобождаем память от продуктов в корзине заказа
    delete[] order.getCart();
  }
};

#endif // VIEWS_H