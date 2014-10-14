#include "Inventory.h"

void Inventory::Init(SDL_Renderer* r) {
	invBox_.LoadTexture(r, SPRITE_LOCATION);
	invBox_.alpha(150);
	invBox_.x(0);
	invBox_.y(326);
	invBox_.scaleX(2);
}

void Inventory::HandleEvents(SDL_Event* event) {
	if (!textVect_.empty()) {
		vector<Texture>::iterator txtIter = textVect_.begin();

		if (txtIter->visible()) {
			invBox_.visible(false);
			for (; txtIter != textVect_.end(); txtIter++) {
				txtIter->visible(false);
			}
		} else {
			invBox_.visible(true);
			for (; txtIter != textVect_.end(); txtIter++) {
				txtIter->visible(true);
			}
		}
	}
}

void Inventory::Update(WindowManager* w) {
	vector<Texture>::iterator txtIter = textVect_.begin();
	textXPos = 0;
	textYPos = 326;

	for (; txtIter != textVect_.end(); txtIter++) {
		//textXPos += 20;
		textYPos += 25;

		txtIter->x(textXPos);
		txtIter->y(textYPos);
	}
}

void Inventory::Render(WindowManager* w) {
	TTF_Font* font = TTF_OpenFont("_resources\\arial.ttf", 18);
	SDL_Color textColor = { 0, 0, 0 };
	vector<Texture>::iterator txtIter = textVect_.begin();

	invBox_.Draw(w->getRenderer());
	for (; txtIter != textVect_.end(); txtIter++) {
		txtIter->CreateTextureFromText(w->getRenderer(), "Potion", font, textColor);
		txtIter->Draw(w->getRenderer());
	}
}

void Inventory::addItem(Item& newItem) {
	current_weight_ += newItem.weight();

	bool uniqueItem = true;

	vector<Item *>::iterator invIter = inventory_space_.begin();

	if (newItem.isStackable() == true && !inventory_space_.empty()) {
		for (; invIter != inventory_space_.end(); invIter++) {
			if (newItem.name() == (*invIter)->name() && !(*invIter)->isFull()) {
				(*invIter)->stackSize((*invIter)->stackSize() + 1);
				uniqueItem = false;
				break;
			}
		}
	}

	if (uniqueItem == true || newItem.isStackable() == false) {
		inventory_space_.push_back(&newItem);
	}
}

void Inventory::clearInventory() {
	inventory_space_.erase(inventory_space_.begin(), inventory_space_.end());
}

void Inventory::removeItem(string itemName) {
	int j = 0;
	bool fullRemove = true;
	vector<Item *> tmpInv(inventory_space_.size() - 1);
	vector<Item *>::iterator invIter;

	for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++) {
		if (itemName == (*invIter)->name()) {
			current_weight_ -= (*invIter)->weight();

			if ((*invIter)->isStackable() == true && (*invIter)->stackSize() > 1) {
				fullRemove = false;
				(*invIter)->stackSize((*invIter)->stackSize() - 1);
			} else {
				delete *invIter;
				*invIter = nullptr;
			}

			break;
		}
	}

	if (fullRemove == true) {
		for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++) {
			if (*invIter != nullptr) {
				tmpInv.at(j) = *invIter;
				j++;
			}
		}

		inventory_space_.clear();

		inventory_space_ = vector<Item *>(tmpInv);
	}
}

void Inventory::printInventory() {
	vector<Item *>::iterator invIter = inventory_space_.begin();

		for (; invIter != inventory_space_.end(); invIter++) {
			if ((*invIter)->isStackable() == false) {
				(*invIter)->printInfo();
			} else {
				(*invIter)->printInfo();
			}

			textVect_.push_back(Texture());
		}
}

bool Inventory::isFull() const {
	if (current_weight_ >= capacity_) {
		return true;
	} else {
		return false;
	}
}