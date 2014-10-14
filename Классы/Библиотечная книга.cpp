#include <iostream>
#include <string>

using namespace std;

struct book_of_MIPTlib
{
	private:
		int age;
	public:
		string  sub;	//subject
		string  athr;	//author

	//Конструктор класса
	book_of_MIPTlib( string  _sub, string  _athr, int _age):sub(_sub), athr(_athr),age(_age)
	{
			cout  << " В библиотеке новая книга по  " <<  sub  << ", автор  " << athr << endl;
	}

	void print()  const
	{
		cout << "subject: " << sub;
		cout << ", author: " << athr;
		cout << ", age: " << age << endl;
	}

	void aging()
	{
		age++;
		if (age >= 10) cout << "This book is obsolete!  It need to be changed.";
		else cout << "This book is used during " << age << " years.";
	}

	void set_age(int new_age)
	{
		age = new_age;
	}

	int get_age() const
	{
		return age;
	}

};

int main()
{
	book_of_MIPTlib x("Электричество и магнетизм", "Н.А.Кириченко", 3);
	x.print();
	x.aging();
	x.print();

	return 0;
}