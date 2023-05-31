#include <iostream>
#include <string>

class Printable
{
public:
	void virtual GetName() = 0;
	virtual std::string GetClassName() = 0;
	Printable();
	~Printable();
};

Printable::Printable() {};
Printable::~Printable() {};

class Entity : public Printable {
public:
	std::string n_name = "Entity";
	void GetName() override { std::cout<<"GetName function => Entity"; } // take home message: virtual metodo() = 0 -> interfaccia 
	std::string GetClassName() {return "GetClassName: Entity Class Name";}
};


class Player : public Entity
{
public:
	std::string n_name = "Default Player Name";
	Player();
	~Player();
	void GetName() override {std::cout << n_name << std::endl;}
	std::string GetClassName() override {return "Player's GetClassName: Player Class Name";}
};

Player::Player(){}
Player::~Player(){}

void PrintName(Entity* e) {
	std::cout << e->GetClassName() << std::endl;
}

int main() {
	Entity* e1 = new Entity();
	std::cout << e1->GetClassName() << std::endl;

	Player* p1 = new Player();
	p1->GetName();

	PrintName(p1);
	PrintName(e1);
	return 0;
}