#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

class Order {
private:
    int id;
    std::string name;
    std::string address;
    std::string phone;
    std::string status;
    Product* clothes;
public:
    Order(int id, std::string name, std::string address, std::string phone, std::string status, Product* clothes) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phone = phone;
        this->status = status;
        this->clothes = clothes;
    }
    int getId() { return id; }
    std::string getName() { return name; }
    std::string getAddress() { return address; }
    std::string getPhone() { return phone; }
    std::string getStatus() { return status; }
    Product* getClothes() { return clothes; }
};
#endif //MODEL_H
