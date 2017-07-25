#include<iostream>
#include<cstring>
#include<cstdlib> //use 'rand'
using namespace std;

class Train
{
	private:
		string dest;
		char time[20];
		int fee;

	public:
		Train(string,const char*,int);
		~Train();

		//retrun each private element
		string get_dest(void) const;
		const char* get_time(void) const;
		int get_fee(void) const;

		//change each private element
		void set_dest(string);
		void set_time(const char*);
		void set_fee(int);

		//print value
		void disp(void) const;
};

Train::Train(string dest="null",const char* time="null", int fee = 0)
{
	this->dest = dest;
	strcpy(this->time,time);
	this->fee = fee;
}

Train::~Train(){}

string Train::get_dest(void) const
{
	return this->dest;
}

const char* Train::get_time(void) const
{
	return this->time;
}

int Train::get_fee(void) const
{
	return this->fee;
}

void Train::set_dest(string dest)
{
	this->dest = dest;
}

void Train::set_time(const char* time)
{
	strcpy(this->time,time);
}

void Train::set_fee(int fee)
{
	this->fee = fee;
}

void Train::disp(void) const
{
	cout << get_dest() << ", " << get_time() << ", " << get_fee() <<endl;
}

int main(void)
{
	Train t[5];//make Train array
	string dest[5] = {"dest A","dest B", "dest C","dest D","dest E"};

	//fill Train array
	for(int i=0;i<5;i++){
		t[i] = Train(dest[i],"12:00",rand()%10000+10000);
	}

	t[1].set_time("1:30"); t[2].set_time("2:00");
	t[3].set_time("4:40"); t[4].set_time("6:00");

	for(int i=0;i<5;i++)
		t[i].disp();

	return 0;
}
