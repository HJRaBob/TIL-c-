#include<iostream>
#include<cstring>
using namespace std;

class Mt
{
	private:
		char mount[10];
		int alt;

	public:
		Mt(const char*,int);
		~Mt();

		const char* getmount(void) const;
		int getalt(void) const;

		void setmount(const char*);
		void setalt(int);

		void disp(void) const;
};

Mt::Mt(const char* _m,int _a)
{
	strcpy(this->mount,_m);
	this->alt = _a;
}

Mt::~Mt(){}

const char* Mt::getmount(void) const
{
	return mount;
}

int Mt::getalt(void) const
{
	return alt;
}

void Mt::setmount(const char* _m)
{
	strcpy(mount,_m);
}

void Mt::setalt(int _a)
{
	alt = _a;
}

void Mt::disp(void) const
{
	cout << getmount() << "==>" << getalt() << endl;
}

int main(void)
{
	//make class array
	Mt m[5] = {Mt("mount1",1111),Mt("mount2",2222),Mt("mount3",3333),Mt("mount4",4444),Mt("mount5",5555)};

	int i, n;
	n = sizeof(m)/sizeof(Mt);

	for(i = 0;i<n;i++)
		m[i].disp(); //access to each member

	return 0;
}








