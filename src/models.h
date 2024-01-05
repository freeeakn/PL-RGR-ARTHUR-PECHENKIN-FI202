#ifndef MODELS_H
#define MODELS_H

#include <iostream>
#include <string>

#define MAX_CART_SIZE 12

class Product {
private:
  std::string name;
  unsigned int price, size;

public:
  Product() : name(""), price(0), size(0) {}

  Product(const Product &other) {
    this->name = other.name;
    this->price = other.price;
    this->size = other.size;
  }

  Product(std::string name, unsigned int price, unsigned int size)
      : name(name), price(price), size(size) {}

  ~Product() {}

  std::string getName() const { return name; }

  unsigned int getPrice() const { return price; }

  unsigned int getSize() const { return size; }

  void setName(std::string name) { this->name = name; }

  void setPrice(unsigned int price) { this->price = price; }

  void setSize(unsigned int size) { this->size = size; }

  void operator=(const Product &other) {
    this->name = other.name;
    this->price = other.price;
    this->size = other.size;
  }
};

class Client {
private:
  std::string firstName, lastName, phone;

public:
  Client() : firstName(""), lastName(""), phone("") {}

  Client(std::string firstName, std::string lastName, std::string phone)
      : firstName(firstName), lastName(lastName), phone(phone) {}

  ~Client() {}

  std::string getFirstName() const { return this->firstName; }

  std::string getLastName() const { return this->lastName; }

  std::string getPhone() const { return this->phone; }

  void setFirstName(std::string firstName) { this->firstName = firstName; }

  void setLastName(std::string lastName) { this->lastName = lastName; }

  void setPhone(std::string phone) { this->phone = phone; }
};

class Order {
private:
  Client client;
  Product *cart;
  unsigned int quantity;

public:
  Order() : cart(nullptr), quantity(0) {}

  ~Order() {
    if (this->cart != nullptr)
      delete[] cart;
  }

  void getInfo() {
    std::cout
        << "================================================================\n"
        << "Client: " << client.getFirstName() << " " << client.getLastName()
        << std::endl
        << "Cart: \n";
    for (unsigned int i = 0; i < quantity; i++) {
      std::cout << "[" << i + 1 << "]"
                << " Name: " << cart[i].getName()
                << " Price: " << cart[i].getPrice()
                << " Size: " << cart[i].getSize() << std::endl;
    }
    std::cout
        << "================================================================\n";
  }

  Client getClient() const { return client; }

  void setClient(const Client &newClient) { client = newClient; }

  Product *getCart() const { return cart; }

  unsigned int getCartSize() const { return quantity; }

  void addToCart(Product product) {
    this->quantity++;

    if (this->quantity == MAX_CART_SIZE)
      throw std::overflow_error("Cart is full");

    if (this->quantity == 1) {
      this->cart = new Product[this->quantity];
      this->cart[0] = product;
    }

    if (this->quantity > 1) {
      Product *newCart = new Product[this->quantity];

      for (unsigned int i = 0; i < this->quantity - 1; i++) {
        newCart[i] = this->cart[i];
      }

      newCart[this->quantity - 1] = product;

      this->cart = newCart;
    }
  }

  void removeFromCart(unsigned const int index) {

    if (index >= this->quantity) {
      throw std::out_of_range("Index out of range");
    }

    delete &cart[index];
    this->quantity--;

    for (unsigned int i = index; i < this->quantity; i++) {
      cart[i] = cart[i + 1];
    }

    // cart[this->quantity + 1] = nullptr;
  }

  Order &operator=(const Order &other) {
    if (this == &other)
      return *this;
    this->client = other.client;

    if (this->cart != nullptr)
      delete[] this->cart;
    this->quantity = other.quantity;

    if (this->quantity > 0) {
      this->cart = new Product[this->quantity];
      for (unsigned int i = 0; i < this->quantity; i++)
        this->cart[i] = other.cart[i];
    } else {
      this->cart = nullptr;
    }

    return *this;
  }
};

#endif // MODELS_H
