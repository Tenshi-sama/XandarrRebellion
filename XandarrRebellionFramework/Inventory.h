#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Inventory
{
private:
	unsigned short current_weight_;
	unsigned short capacity_;
	vector<Item *> inventory_space_;

public:
	Inventory();
	~Inventory() {};

	void addItem(Item& newItem);
	void removeItem(string);
	bool isFull() const;

	inline unsigned short getCurrentWeight() const { return current_weight_; }
	inline unsigned short getCapacity() const { return capacity_; }

	inline void Inventory::setCapacity(const unsigned short newValue) { capacity_ = newValue; }
	inline void Inventory::setCurrentWeight(const unsigned short newValue) { current_weight_ = newValue; }

	void printInventory();
	void clearInventory();
};

#endif