#include <iostream>
#include <cstdlib> // Для работы с функцией system()

using namespace std;

class Drob
{
protected:

	int x;
	int y;

public:
	Drob(){
		this->x = 0;
		this->y = 1;
	}
	Drob(int a,int b)
	{
		if (b==0)
		{
			cout << ("Denominator mustn't equal zero ") << endl;
			system("pause"); // Команда задержки экрана
		}
		 
		if (a*b >= 0){
			x = abs(a);
			y = abs(b);
		}
		else{
			x = -abs(a);
			y = abs(b);
		}
	}



	void print(){ 
		int a = this->x;
		this->x /= Drob(this->x, this->y).evklid();
		this->y /= Drob(a, this->y).evklid();
		cout << this->x << "/" << this->y;
	}

	int evklid(){
		if (abs(this->x) == this->y) return abs(this->x);
		int a = abs(this->x);
		int b = abs(this->y);
		while ((a*b) != 0){
			if (a>b) a -= (a / b)*b;
			else b -= (b / a)*a;
		}
		return a + b;
 	}

	Drob operator+(Drob b)
	{
		Drob c;
		c.x = (this->x*b.y + this->y*b.x) / Drob(this->x*b.y + this->y*b.x, this->y*b.y).evklid();
		c.y = (this->y*b.y) / Drob(this->x*b.y + this->y*b.x, this->y*b.y).evklid();
		return c;
	}

	Drob operator-(Drob b)
	{
		Drob c;
		c.x = (this->x*b.y - this->y*b.x) / Drob(this->x*b.y + this->y*b.x, this->y*b.y).evklid();
		c.y = (this->y*b.y) / Drob(this->x*b.y + this->y*b.x, this->y*b.y).evklid();
		return c;
	}

	Drob operator*(Drob b)
	{
		Drob c;
		c.x = (this->x*b.x) / Drob(this->x *b.x, this->y*b.y).evklid();
		c.y = (this->y*b.y) / Drob(this->x *b.x, this->y*b.y).evklid();
		return c;
	}

	Drob operator/(Drob b)
	{
		Drob c;
		c.x = (this->x *b.y) / Drob(this->x *b.y, this->y*b.x).evklid();
		if (this->y*b.x < 0) {
			c.y = (-this->y*b.x) / Drob(this->x *b.y, this->y*b.x).evklid();
			c.x *= -1;
		}
		else {
			c.y = (this->y*b.x) / Drob(this->x *b.y, this->y*b.x).evklid();
		}
		return c;
	}

};

