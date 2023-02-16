#include "user.h"
#include "product.h"
#include <vector>

using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

void User::addToCart(Product* product) {
	cart_.push_back(product);
}

void User::printCart() {
	for (unsigned int i = 0; i < cart_.size(); i++) {
		std::cout << "i " << cart_[i] -> displayString() << std::endl;
	}
}

void User::buyCart() {
	for (unsigned int i = 0; i < cart_.size(); i++) {
		if (balance_ >= cart_[i]->getPrice() && cart_[i]->getQty() > 0)
		{
			balance_ -= cart_[i]->getPrice();
			cart_[i]->subtractQty(1);
		}
	}
}
