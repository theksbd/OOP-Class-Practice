#include <iostream>
#include <string.h>

using namespace std;

class People
{
protected:
	string Name;
	string Job;
	bool Gender; // Male: True, Female: False
	int Age;

public:
	People() : Name(""), Job(""), Gender(false), Age(0){};
	People(string Name, string Job, bool Gender, int Age)
	{
		this->Name = Name;
		this->Job = Job;
		this->Gender = Gender;
		this->Age = Age;
	}
	void setName(string Name)
	{
		this->Name = Name;
	}
	string getName()
	{
		return this->Name;
	}
	void setJob(string Job)
	{
		this->Job = Job;
	}
	string getJob()
	{
		return this->Job;
	}
	void setGender(bool Gender)
	{
		this->Gender = Gender;
	}
	bool getGender()
	{
		return this->Gender;
	}
	void setAge(int Age)
	{
		this->Age = Age;
	}
	int getAge()
	{
		return this->Age;
	}

	void Introduce()
	{
		cout << "Hello. My name is " << Name << ". I work as a " << Job << ". ";
		Gender ? cout << "I'm male " : cout << "I'm female ";
		cout << "and I'm " << Age << " now!" << endl;
	}
	virtual void Work()
	{
		cout << Name << " is checking email..." << endl;
	}
	virtual void AskForPromotion() = 0;
};

class Engineer : public People
{
protected:
	int AgeAtWork;

public:
	Engineer(string Name, string Job, bool Gender, int Age, int AgeAtWork) : People(Name, Job, Gender, Age)
	{
		this->AgeAtWork = AgeAtWork;
	}
	void Work()
	{
		cout << Name << " is fixing bugs using C++!" << endl;
	}
	void AskForPromotion()
	{
		AgeAtWork >= 10 ? cout << Name << " can get promoted!" << endl : cout << Name << " can not get promoted now, try harder!" << endl;
	}
};

class Teacher : public People
{
protected:
	int AgeAtWork;

public:
	Teacher(string Name, string Job, bool Gender, int Age, int AgeAtWork) : People(Name, Job, Gender, Age)
	{
		this->AgeAtWork = AgeAtWork;
	}
	void Work()
	{
		cout << Name << " is preparing the lesson!" << endl;
	}
	void AskForPromotion()
	{
		AgeAtWork >= 10 ? cout << Name << " can get promoted!" << endl : cout << Name << " can not get promoted now, try harder!" << endl;
	}
};

int main()
{
	Engineer e1("Do Thien Hoang", "Software Engineer", 1, 20, 8);
	Teacher t1("Pham Dong Trieu", "Chemistry Teacher", 1, 25, 12);
	People *p1 = &e1;
	People *p2 = &t1;
	p1->Work();
	p2->Work();
	// system("pause > 0");
	return 0;
}

// Engineer p1("Do Thien Hoang", "Software Engineer", 1, 20, 10);
// Engineer p2("Pham Toan Van Vo", "Vehicle Engineer", 1, 22, 8);
// Teacher p3("Pham Dong Trieu", "Chemistry Teacher", 1, 25, 12);
// p1.Introduce();
// p2.Introduce();
// p3.Introduce();
// p1.Work();
// p3.Work();
// p1.AskForPromotion();
// p2.AskForPromotion();
// p3.AskForPromotion();