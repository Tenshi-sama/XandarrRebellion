#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
	string name_;
	string description_;
	unsigned int worth_;
	unsigned short weight_;
	unsigned short stack_size_;
	unsigned short max_stack_size_;

public:
	Item() {}
	Item::~Item() {}

	inline bool isFull() const { return (max_stack_size_ - stack_size_ == 0); }
	inline bool isStackable() const { return (max_stack_size_ > 1); }
	inline const string& name() const { return name_; }
	inline unsigned int worth() const { return worth_; }
	inline unsigned short weight() const { return weight_; }
	inline unsigned short stackSize() const { return stack_size_; }
	inline const string& description() const { return description_; }
	inline unsigned short maxStackSize() const { return max_stack_size_; }

	inline void name(const string& newValue) { name_ = newValue; }
	inline void description(const string& newValue) { description_ = newValue; }
	inline void worth(const unsigned int newValue) { worth_ = newValue; }
	inline void weight(const unsigned short newValue) { weight_ = newValue; }
	inline void stackSize(const unsigned short newValue) { stack_size_ = newValue; }
	inline void maxStackSize(const unsigned short newValue) { max_stack_size_ = newValue; }

	virtual void printInfo() = 0;
};

#endif