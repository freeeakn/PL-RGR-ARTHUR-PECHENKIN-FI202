#ifndef MODELS_H
#define MODELS_H

#include <iostream>
#include <string>
#include "observer.h"

#define MAX_CART_SIZE 12

class Product : public Observable {
private:
    std::string name;
    unsigned int price;
    unsigned int size;

public:
    Product():
        name(""), price(0), size(0) {}

    Product(const Product& other) {
        this->name = other.name;
        this->price = other.price;
        this->size = other.size;
    }

    Product(std::string name, unsigned int price, unsigned int size) :
        name(name), price(price), size(size) {}

    ~Product() {}

    std::string getName() const {
        return name;
    }

    unsigned int getPrice() const {
        return price;
    }

    unsigned int getSize() const {
        return size;
    }

    void setName(std::string name) {
        this->name = name;
        notifyUpdate();
    }

    void setPrice(unsigned int price) {
        this->price = price;
        notifyUpdate();
    }

    void setSize(unsigned int size) {
        this->size = size;
        notifyUpdate();
    }

    // void operator= (const Product& other) {
        
    // }
};

class Client : public Observable {
private:
    std::string firstName;
    std::string lastName;
    std::string phone;

public:

    Client():
        firstName(""), lastName(""), phone("") {}

    Client(std::string firstName, std::string lastName, std::string phone):
        firstName(firstName), lastName(lastName), phone(phone) {}

    ~Client() {}

    std::string getFirstName() {
        return this->firstName;
    }

    std::string getLastName() {
        return this->lastName;
    }

    std::string getPhone() {
        return this->phone;
    }
};

class Order : public Observable {
private:
    Client client;
    Product *cart;
    unsigned int quantity;

public:
    Order():
        cart(nullptr), quantity(0) {}

    ~Order() {
        if (this->cart != nullptr) delete[] cart;
    }

    Client getClient() const {
        return client;
    }

    void setClient(const Client& newClient) {
        client = newClient;
        notifyUpdate();
    }

    Product *getCart() const {
        return cart;
    }

    unsigned int getCartSize() const {
        return quantity;
    }

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
        
        notifyUpdate();
    }

    void removeFromCart(unsigned const int index) {

        if (index >= this->quantity) {
            throw std::out_of_range("Index out of range");
        }

        // delete product from cart
        delete &cart[index];
        this->quantity--;

        for (unsigned int i = index; i < this->quantity; i++) {
            cart[i] = cart[i + 1];
        }

        notifyUpdate();

        // cart[this->quantity + 1] = nullptr;
    }
};

#endif //MODELS_H
