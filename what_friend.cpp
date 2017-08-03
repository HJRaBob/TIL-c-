#include<iostream>
using namespace std;

class B; //there is class B

class A
{
	friend class B; //B can access A's private member

	private:
		int data;

	public:
		A(int);
		~A();
		
		void disp() const;	
//		void frd_disp(B) const; anable
};

class B
{
	private:
		int data;

	public:
		B(int);
		~B();
		
		void disp() const;
		void frd_disp(A) const; //to access A
};

A::A(int data)
{
	this->data = data;
}

A::~A(){}

void A::disp() const
{
	cout << "A's data: " << this->data << endl;
}

/*
void A::frd_disp(B b) const
{
	cout << "B:: A's data: "<<b.data<<endl;
}
anable
*/

B::B(int data)
{
	this->data = data;
}

B::~B(){}

void B::disp() const
{
	cout << "B's data: " << this->data << endl;
}

void B::frd_disp(A a) const
{
	cout << "B:: A's data: "<<a.data<<endl;
}


int main()
{
	A a(10);
	B b(20);

	a.disp();
	b.disp();
//	a.frd_disp(b); anable
	b.frd_disp(a);
	return 0;
}
