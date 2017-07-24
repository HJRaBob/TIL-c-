#include <iostream>
#include <cstring>
using namespace std;

class Mt
{
	private:
		char mount[10];
		int alt;

	public:
		Mt(const char* _m = "없 음", int _a = 0);
		~Mt(void);

		const char* GetMount(void) const;
		int GetAlt(void) const;
		
		void Disp(void) const; //use 'const'
		void Disp(void); //not use 'const'
};

Mt::Mt(const char* _m, int _a)
{
	strcpy(this->mount, _m);
	this->alt = _a;
}

Mt::~Mt(void){}

const char* Mt::GetMount(void) const
{
	return this->mount;
}


int Mt::GetAlt(void) const
{
	return this->alt;
}

void Mt::Disp(void) const
{
	cout << "this have 'const'" << endl;
	//this->alt = 12345; //it make error (const can't change value)
	cout << this->GetMount() << "==>" << this->GetAlt() << endl;
}

void Mt::Disp(void)
{
	cout << "this don't have 'const'"<< endl;
	this->alt = 12345;
	cout << this->GetMount() << "==>" << this->GetAlt() << endl;
}

int main(void)
{
	Mt m1("mount1",9999);
	Mt m2("mount2",8888);

	m1.Disp();
	m2.Disp();
	//why const function is not called???
}

