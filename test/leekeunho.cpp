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
		cout << "Animal ����" << endl;
	}
	virtual ~Animal() {
		cout << "Animal �Ҹ�" << endl;
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
		cout << "Dog ����" << endl;
	}
	virtual ~Dog() {
		cout << "Dog �Ҹ�" << endl;
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
		cout << getName() << "�� " << bark << endl;
	}


};

class Cat : public Animal {
private:
	string bark;
public:
	/***********************/
	Cat(string name = "", int age = 0, string bark = "") : Animal(name, age) {
		this->bark = bark;
		cout << "Cat ����" << endl;
	}
	virtual ~Cat() {
		cout << "Cat �Ҹ�" << endl;
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
		cout << getName() << "�� " << bark << endl;
	}

};



void running(Animal* pAnimal) {
	cout << pAnimal->name << "�� �޸���" << endl;
}

void crying(Animal* pAnimal) {
	pAnimal->crying();
}



int main() {
	cout << "--�߻� Ŭ������ �Ļ� Ŭ���� ����--\n";
	Dog* dog = new Dog("������", 4, "�۸�");
	Cat* cat = new Cat("�����", 2, "�߿�");

	cout << "\n--�Ű������� ������ ����--\n";
	crying(dog);
	crying(cat);
	running(dog);
	running(cat);

	cout << "\n--�⺻ ��������� ���� ����--\n";
	Dog copyDog(*dog);
	cout << copyDog.getName() << endl;
	cout << copyDog.getAge() << endl;
	cout << copyDog.getBark() << endl;

	cout << "\n--�Ҹ��� ����--\n";
	delete dog;
	delete cat;
	return 0;
}