#include <iostream>
#include <fstream>

using namespace std;

string filename = "Save";

enum Choise
{
	ONE = 1, TWO, THREE, FOUR, FIVE, EXIT = 0,
};

#define PAUSE system("pause");
#define CLEAR system("cls");

class Weapon
{
private:
	int shot_range;
	float caliber;
	int count_of_patrons;
	int max_count_of_patrons;
public:
	void Initialize(int range, float calibre, int maxSize, int _count_of_patrons)
	{
		shot_range = range;
		caliber = calibre;
		max_count_of_patrons = maxSize;
		count_of_patrons = _count_of_patrons;
	}

	bool Shot()
	{
		if (count_of_patrons == 0)
		{
			return false;
		}
		else
		{
			count_of_patrons--;
			return true;
		}
	}

	void Recharge()
	{
		count_of_patrons = max_count_of_patrons;
	}

	void Save() const
	{

		ofstream fout;
		fout.open(filename);
		bool isOpen_fout = fout.is_open();
		if (isOpen_fout == false)
		{
			cout << " File not open" << endl;
			return;
		}
		else
		{
			fout << shot_range << endl;
			fout << caliber << endl;
			fout << count_of_patrons << endl;
			fout << max_count_of_patrons << endl;
		}
		fout.close();
	}

	void Load()
	{
		ifstream fin;
		fin.open(filename);
		bool isOpen_fin = fin.is_open();
		if (isOpen_fin == false)
		{
			cout << " File not open" << endl;
			return;
		}
		else
		{
			while (!fin.eof())
			{
				fin >> shot_range;
				fin >> caliber;
				fin >> count_of_patrons;
				fin >> max_count_of_patrons;
			}
		}
		fin.close();
	}
};

void main()
{
	Weapon gun;

	int choise = 0;
	do
	{
		cout << ONE << " - initialize" << endl;
		cout << TWO << " - shoot" << endl;
		cout << THREE << " - recharge" << endl;
		cout << FOUR << " - save" << endl;
		cout << FIVE << " - load" << endl;
		cout << EXIT << " - exit" << endl;
		cout << ">";
		cin >> choise;
		switch (choise)
		{
		case ONE:
		{
			int _range, _maxSize, _countP_atrons;
			float _calibre;
			cout << "Enter range of gun --> ";
			cin >> _range;
			if (_range <= 0)
			{
				cout << "error" << endl;
				break;
			}
			cout << "Enter calibre of gun --> ";
			cin >> _calibre;
			if (_calibre <= 0)
			{
				cout << "error" << endl;
				break;
			}
			cout << "Enter max size of magazin --> ";
			cin >> _maxSize;
			if (_maxSize <= 0)
			{
				cout << "error" << endl;
				break;
			}
			cout << "Enter count of patrons --> ";
			cin >> _countP_atrons;
			if (_countP_atrons <= 0 && _countP_atrons > _maxSize)
			{
				cout << "error" << endl;
				break;
			}
			gun.Initialize(_range, _calibre, _maxSize, _countP_atrons);
			CLEAR
		}
		break;
		case TWO:
		{
			int check = gun.Shot();
			if (check == false)
			{
				cout << "There are no patrons in magazin" << endl;
				PAUSE
			}
			else
			{
				cout << "The shot was fired" << endl;
				PAUSE
			}
			CLEAR
		}
		break;
		case THREE:
		{
			gun.Recharge();
		}
		break;
		case FOUR:
		{
			gun.Save();
		}
		break;
		case FIVE:
		{
			gun.Load();
		}
		break;
		default:
			cout << "error" << endl;
			break;
		}
		CLEAR;
	} while (choise != EXIT);

	PAUSE
}