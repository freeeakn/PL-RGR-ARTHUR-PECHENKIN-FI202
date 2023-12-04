#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    unsigned int price;
    unsigned int size;

public:
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
    }

    void setPrice(unsigned int price) {
        this->price = price;
    }

    void setSize(unsigned int size) {
        this->size = size;
    }
};

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string phone;

public:
    Client(std::string firstName, std::string lastName, std::string phone):
        firstName(firstName), lastName(lastName), phone(phone) {}

    ~Client();

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

class Order {
private:
    Client client;
    Product *cart;

public:
    Order();
    ~Order();
};