#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
	string name;
	int age;
public:
	/***********************/
	Animal(string name = "", int age = 0) {
		this->name = name;
		this->age = age;
		cout << "Animal 생성" << endl;
	}
	virtual ~Animal() {
		cout << "Animal 소멸" << endl;
	}

	Animal(const Animal& a) {
		this->name = a.name;
		this->age = a.age;
	}
	/***********************/
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}

	int getAge() {
		return age;
	}
	void setAge(int age) {
		this->age = age;
	}

	/***********************/
	friend void running(Animal* pAnimal);
	virtual void crying() = 0;


};

class Dog : public Animal {
private:
	string bark;
public:
	/***********************/
	Dog(string name = "", int age=0, string bark = "") : Animal(name, age),bark(bark) {
//		this->bark = bark;
		cout << "Dog 생성" << endl;
	}
	virtual ~Dog() {
		cout << "Dog 소멸" << endl;
	}

	Dog(const Dog& d) : Animal(d) {
		this->bark = d.bark;
	}
	/***********************/
	string getBark() {
		return bark;
	}
	string setBark(string bark) {
		this->bark = bark;
	}

	/***********************/
	virtual void crying() {
		cout << getName() << "는 " << bark << endl;
	}


};

class Cat : public Animal {
private:
	string bark;
public:
	/***********************/
	Cat(string name = "", int age = 0, string bark = "") : Animal(name, age) {
		this->bark = bark;
		cout << "Cat 생성" << endl;
	}
	virtual ~Cat() {
		cout << "Cat 소멸" << endl;
	}

	Cat(const Cat& c) : Animal(c) {
		this->bark = c.bark;
	}
	/***********************/
	string getBark() {
		return bark;
	}
	string setBark(string bark) {
		this->bark = bark;
	}
	/***********************/

	virtual void crying() {
		cout << getName() << "는 " << bark << endl;
	}

};



void running(Animal* pAnimal) {
	cout << pAnimal->name << "가 달린다" << endl;
}

void crying(Animal* pAnimal) {
	pAnimal->crying();
}



int main() {
	cout << "--추상 클래스와 파생 클래스 구현--\n";
	Dog* dog = new Dog("강아지", 4, "멍멍");
	Cat* cat = new Cat("고양이", 2, "야옹");

	cout << "\n--매개변수의 다형성 구현--\n";
	crying(dog);
	crying(cat);
	running(dog);
	running(cat);

	cout << "\n--기본 복사생성자 직접 구현--\n";
	Dog copyDog(*dog);
	cout << copyDog.getName() << endl;
	cout << copyDog.getAge() << endl;
	cout << copyDog.getBark() << endl;

	cout << "\n--소멸자 실행--\n";
	delete dog;
	delete cat;
	return 0;
}