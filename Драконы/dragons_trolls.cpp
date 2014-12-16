#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>

using namespace std;

class Unit
{
protected:
    int health;
public:
    int attackForce;

    Unit(int start_health, int _attackForce)
        :health(start_health), attackForce(_attackForce)
    {}
    void getDamage(int damage)
    {
        health -= damage;
    }
    int getHealth() const
    {
        return health;
    }
    bool isAlive() const
    {
        return (health > 0);
    }
};

class Monster: public Unit
{
protected:
    int my_answer;
    string my_name;
public:
    static const int c_killScores = 100;

    Monster(string name, int start_health, int _attackForce)
        :Unit(start_health, _attackForce), my_name(name)
    {}
    virtual string getQuest() = 0; //pure virtual

    bool checkAnswer(int answer) const
    {
        return answer == my_answer;
    }
    string name() const
    {
        return my_name;
    }
};

class GreenDragon: public Monster
{
    static const int c_greenDragonHealth = 50;
    static const int c_greenDragonAttack = 10;
public:
    GreenDragon() :Monster("Green Dragon",
                          c_greenDragonHealth,
                          c_greenDragonAttack)
    {}
    string getQuest()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        stringstream question;
        question << left << " + " << right << ": ";
        my_answer = left + right;
        return question.str();
    }
};

class RedDragon: public Monster
{
    static const int c_redDragonHealth = 80;
    static const int c_redDragonAttack = 15;
public:
    RedDragon() :Monster("Red Dragon",
                          c_redDragonHealth,
                          c_redDragonAttack)
    {}
    string getQuest()
    {
        int left = 1 + rand()%50;
        int right = 1 + rand()%50;

        stringstream question;
        question << left << " - " << right << ": ";
        my_answer = left - right;
        return question.str();
    }
};

class BlackDragon: public Monster
{
    static const int c_blackDragonHealth = 100;
    static const int c_blackDragonAttack = 20;
public:
    BlackDragon() :Monster("Black Dragon",
                          c_blackDragonHealth,
                          c_blackDragonAttack)
    {}
    string getQuest()
    {
        int left = 1 + rand()%10;
        int right = 1 + rand()%10;

        stringstream question;
        question << left << " * " << right << ": ";
        my_answer = left * right;
        return question.str();
    }
};

class Troll: public Monster
{
	static const int c_TrollHealth = 50;
    static const int c_TrollAttack = 10;
public:
    Troll() :Monster("Troll",
		            c_TrollHealth,
					c_TrollAttack)
    {}
    std::string getQuest()
    {
        int num = 1 + rand()%100;

        stringstream question;
        question << num << " - simple?\n1=\"yes\"  0=\"no\"\n" ;
        my_answer = simple(num);
        return question.str();
    }
protected:
	bool simple(int a){
		int i, j, k;
		if (a == 0 || a == 1)
			return 0;
		if (a == 2 || a == 3 || a == 5)
			return 1;
		if (a%2 == 0 || a%3 == 0 || a%5 == 0)
			return 0;
		k = sqrt((double)a);
		i = 7;
		j = 11;
		while (j <= k && a%i && a%j){
			i += 6;
			j += 6;
		}
		if (j <= k || i <= k && a%i == 0)
		   return 0;
		return 1;
		}
};

class Hero: public Unit
{
    int scores;
public:
    static const int default_health = 100;
    static const int default_attackForce = 20;

    Hero(int health = default_health, int aForce = default_attackForce)
        :Unit(health, aForce), scores(0)
    {}
    void attack (Monster &Monster)
    {
        string q = Monster.getQuest();
        cout << q;
        int answer;
        cin >> answer;
        if (Monster.checkAnswer(answer))
        {
            Monster.getDamage(attackForce);
            cout << "Hit you, Monster!" << endl;
        }
        else
        {
            getDamage(Monster.attackForce);
            cout << "Hero suffers..." << endl;
        }
    }
    void addScores(int _scores)
    {
        scores += _scores;
    }
    int getScores()
    {
        return scores;
    }
};

void showHealth(const Hero &hero, const Monster &Monster)
{
    cout << "Hero health: " << hero.getHealth()
        << ", Monster health: " << Monster.getHealth() << endl;
}

void playGame(list<Monster*> &MonsterList)
{
    Hero hero;
    bool gameOver = false;
    for (list<Monster*>::iterator Monster = MonsterList.begin();
            Monster != MonsterList.end(); Monster++)
    {

        cout << "You have met a new " << (*Monster)->name()
                << ". Fight!" << endl;

        while ((*Monster)->isAlive() && hero.isAlive())
        {
            hero.attack(**Monster);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // monster was killed!
        {
            hero.addScores(Monster::c_killScores);
            cout << "Ough! You have killed a Monster!" << endl;
        }
    }
    if (gameOver)
    {
        cout << "Game over! Your score is: " << hero.getScores() << endl;
    }
    else
    {
        cout << "You win! Your score is: " << hero.getScores() << endl;
    }
}

list<Monster*> generateMonsterList()
{
    list<Monster*> MonsterList;
    MonsterList.push_back(new GreenDragon());
    MonsterList.push_back(new RedDragon());
    MonsterList.push_back(new BlackDragon());
	MonsterList.push_back(new Troll());
    return MonsterList;
}

int main()
{
    list<Monster*> MonsterList = generateMonsterList();
    playGame(MonsterList);
    return 0;
}