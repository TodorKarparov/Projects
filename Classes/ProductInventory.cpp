/**
Product Inventory Project:
Create an application which manages an inventory of products. 
Create a product class which has a price, id, and quantity on hand.
Then create an inventory class which keeps track of various products and can sum up the inventory value.
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Product {
	std::string ID;
	double price;
	size_t quantity;

public:

	Product(std::string& _ID, double _price, size_t _quantity) {
		ID = _ID;
		price = _price;
		quantity = _quantity;
	}

	std::string getID() const {
		return ID;
	}

	double getPrice() const {
		return price;
	}

	size_t availableQuantity() const {
		return quantity;
	}

	void setPrice(double newPrice) {
		price = newPrice;
	}

	void setQuantity(size_t newQuantity) {
		quantity = newQuantity;
	}

};

class Inventory {
	std::unordered_map<std::string, Product*> inventory;

public:

	Product* getProduct(std::string& productID) const {
		if (inventory.contains(productID)) {
			return inventory.at(productID);
		}

		return nullptr;
	}

	void addProduct(Product* product) {
		if (inventory.contains(product -> getID())) {
			inventory.at(product -> getID()) -> 
			setQuantity(inventory.at(product -> 
			getID()) -> availableQuantity() + product -> availableQuantity());
		}

		inventory[product -> getID()] = product;
	}


};

