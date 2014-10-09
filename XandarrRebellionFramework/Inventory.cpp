#include "Inventory.h"

Inventory::Inventory() : capacity_(100), current_weight_(0) {}

void Inventory::addItem(Item& newItem)
{
	current_weight_ += newItem.weight();

	bool uniqueItem = true;

	vector<Item *>::iterator invIter = inventory_space_.begin();

	if (newItem.isStackable() == true && !inventory_space_.empty())
	{
		for (; invIter != inventory_space_.end(); invIter++)
		{
			if (newItem.name() == (*invIter)->name() && !(*invIter)->isFull())
			{
				(*invIter)->stackSize((*invIter)->stackSize() + 1);
				uniqueItem = false;
				break;
			}
		}
	}

	if (uniqueItem == true || newItem.isStackable() == false)
	{
		inventory_space_.push_back(&newItem);
	}
}

void Inventory::clearInventory()
{
	inventory_space_.erase(inventory_space_.begin(), inventory_space_.end());
}

void Inventory::removeItem(string itemName)
{
	int j = 0;
	bool fullRemove = true;
	vector<Item *> tmpInv(inventory_space_.size() - 1);
	vector<Item *>::iterator invIter;

	for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++)
	{
		if (itemName == (*invIter)->name())
		{
			current_weight_ -= (*invIter)->weight();

			if ((*invIter)->isStackable() == true && (*invIter)->stackSize() > 1)
			{
				fullRemove = false;
				(*invIter)->stackSize((*invIter)->stackSize() - 1);
			}
			else
			{
				delete *invIter;
				*invIter = nullptr;
			}

			break;
		}
	}

	if (fullRemove == true)
	{
		for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++)
		{
			if (*invIter != nullptr)
			{
				tmpInv.at(j) = *invIter;
				j++;
			}
		}

		inventory_space_.clear();

		inventory_space_ = vector<Item *>(tmpInv);
	}
}

void Inventory::printInventory()
{
	vector<Item *>::iterator invIter = inventory_space_.begin();

	for (; invIter != inventory_space_.end(); invIter++)
	{
		if ((*invIter)->isStackable() == false)
		{
			(*invIter)->printInfo();
		}
		else
		{
			(*invIter)->printInfo();
		}
	}
}

bool Inventory::isFull() const
{
	if (current_weight_ >= capacity_)
	{
		return true;
	}
	else
	{
		return false;
	}
}