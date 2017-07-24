#include<iostream>
#include<cstring>
using namespace std;

class Mt
{
	private:
		char mount[10];
		mutable int alt; //mutable

	public:
		Mt(const char*,int);
		~Mt();

		const char* getmount(void) const;
		int getalt(void) const;

		void setmount(const char*);
		void setalt(int);

		void disp() const;
};

Mt::Mt(const char* _m = "null", int _a = 0)
{
	strcpy(this->mount,_m);
	this->alt = _a;
}

Mt::~Mt(){}

const char* Mt::getmount(void) const
{
	return this->mount;
}

int Mt::getalt(void) const
{
	return this->alt;
}

void Mt::setmount(const char* _m)
{
	strcpy(this->mount,_m);
}

void Mt::setalt(int _a)
{
	this->alt = _a;
}

void Mt::disp(void) const
{
	this->alt = 5000; //mutable can change in const
	//strcpy(this->mount,"mount"); //error
	cout<< this->getmount() << "==>" << this->getalt() << endl;
}

int main(void)
{
	Mt m1("mount1",9999);
	Mt m2("mount2",8888);
	Mt m3;

	m1.disp();
	m2.disp();
	m3.disp();

	return 0;
}
