#include<iostream>
#include<iomanip> //to use setw()
#include<cstring>
#define YEAR 2017
using namespace std;

int gcount = 0;

class Man
{
	private:
		char name[20];
		int year; //birth year
		int age;
		static int s_count; //number of instance using static
		int count; //number of instance(not work)

	public:
		Man(const char* , int);
		~Man();

		const char* getname(void) const;
		int getyear(void) const;
		int getage(void) const;

		int getcount(void) const;
		int gets_count(void) const;

		void setname(const char*);
		void setyear(int);

		void disp(void) const;
};

int Man::s_count = 0; //initialize static variable

Man::Man(const char* name= "null", int year =0)
{
	strcpy(this->name,name);
	this->year = year;
	this->age = YEAR - year;
	//if instance is made, count up
	this->count++;
	s_count++;
	gcount++;
}

Man::~Man()
{
	//if instance is removed, count down
	this->count--;
	s_count--;
	gcount--;
}

const char* Man::getname(void) const
{
	return this->name;
}

int Man::getyear(void) const
{
	return this->year;
}

int Man::getage(void) const
{
	return this->age;
}

int Man::getcount(void) const
{
	return count;
}

int Man::gets_count(void) const
{
	return s_count;
}

void Man::setname(const char* name)
{
	strcpy(this->name,name);
}

void Man::setyear(int year)
{
	this->year = year;
	this->age = YEAR - year;
}

void Man::disp(void) const
{
	cout <<setw(10) << getname() << setw(8) << getyear() << setw(6) <<getage() <<endl;
	cout << "count : " << this->count << setw(10) << "s_count : " << this->s_count << endl;
	cout << "count(global)" << gcount <<endl;
}

int main(void)
{
	Man m1("man1",1989);
	Man m2("man2",1993);
	Man m3;

	gcount = 2222; //accessible from outside

	m1.disp();
	m2.disp();
	m3.disp();

	/* why error?
	cout << "count(main) : " <<Man::getcount() <<endl;
	cout << "s_count(main) : " <<Man::gets_count() <<endl;
	*/

	/* can't accese (private)
	cout << "count(main) : " <<Man::count <<endl;
	cout << "s_count(main) : " << Man::s_count << endl;
	*/
	return 0;
}
