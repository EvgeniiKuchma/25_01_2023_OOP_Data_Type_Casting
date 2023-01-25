#include <iostream>
#include <vector>
class IVehicle
{
	public:
		virtual void printName() = 0;
		virtual int getSpeed() = 0;
		virtual void printEngine() = 0;
		virtual ~IVehicle() {}
}; 
class Car : public IVehicle
{
public:
	Car(int speed) : _speed(speed) {}
	void printName() override {
		std::cout << "Skoda" << std::endl;
	}
	int getSpeed() override {
		return _speed;
	}
	void printEngine() override {
		std::cout << "Disel" << std::endl;
	}
private:
	int _speed;
}; 
class Van : public IVehicle
{
public:
	Van(int speed) : _speed(speed) {}
	void printName() override {
		std::cout << "Wolkswagen" << std::endl;
	}
	int getSpeed() override {
		return _speed;
	}
	void printEngine() override {
		std::cout << "Disel" << std::endl;
	}
private:
	int _speed;
};
void printIVehicale(const std::vector<IVehicle*>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		v[i]->printName();
		std::cout << v[i]->getSpeed() << std::endl;
		v[i]->printEngine();
	}
}
class Parent {
	public: 
		virtual void sleep() {
			std::cout << "sleep()" << std::endl;
		}
};
void foo(Parent& derived_obj) {
	std::cout << "inside foo()" << std::endl;
	derived_obj.sleep();
}
class Child : public Parent {
	public:
		void sleep() override {
			std::cout << "child sleep()" << std::endl;
		}
		void gotoSchool() {
			std::cout << "gotoSchool()" << std::endl;
		}
};
	int main() {
		setlocale(LC_ALL, "Russian");

		IVehicle* b = new Car(50);
		IVehicle* d = new Van(80);
		
		std::vector<IVehicle*> vec;

		vec.push_back(b);
		vec.push_back(d);

		std::cout << "Traversing vehicles" << std::endl;
		
		printIVehicale(vec);
		
		delete b;
		delete d;

		Parent parent;
		Child child;

		//int a = 5;
		//double b = (double)a;// C-style приведение типа данных
		//double b = double(a);//второй вариант

		//upcast - Ќ≈я¬Ќќ≈ ѕ–≈ќЅ–ј«ќ¬јЌ»≈ 
		Parent* pParent = &child;// Child* превратили Parent* /дает возможность динамического полиморфизма приработе с кучей
		//downcast
		Child* pChild = (Child*)&parent;//Parent* превратили в Child* добавив в него все методы чайлда
	
		pParent->sleep();
		pChild->sleep();
		
		foo(*pParent);

		return 0;
	};