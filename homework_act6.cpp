// homework_act6 -- Cycles, branches and logicals operations 

// Task 1 - Напишите программу, которая читает клавиатурный ввод до символа @
//			и повторяет его, за исключением десятичных цифр, преобразуя
//			каждую букву верхнего регистра в букву нижнего регистра и наоборот

#include <iostream>
#include <cctype>

int main()
{
	using namespace std;
	char ch;

	cout << "Enter something: ";
	while((ch = cin.get()) != '@' && ch != EOF)
	{
		if (isalpha(ch))
		{
			ch = (isupper(ch)) ? tolower(ch) : toupper(ch);
		}
		else if (isdigit(ch))
				continue;
		cout << char(ch);
	}
	return 0;
}


// Task 2 - Напишите программу, читающую массив double до 10 значений пожертвований.
//			Программа должна прекращать ввод при получении нечисловой величины. Она
//			должна выдавать среднее значение полученных чисел, а также количество
//			значений в массиве, превышающих среднее.

#include <iostream>
#include <cctype>

constexpr size_t ArrSize = 10;
int moreThenAvg(const double donate[ArSize], const double averageValue);

int main()
{
	int count = 0;
	int moreAverageNumber = 0;
	double sum = 0.0;
	double averageValue = 0.0;
	double donate[ArrSize];
	int index = 0;
	std::cout << "Fill the array (10 elements):" << std::endl;
	while (std::cin >> donate[index] && index < ArSize)
	{
		++count;
		sum += donate[index];
		++index;
	}
	averageValue = sum / count;
	moreAverageNumber = moreThenAvg(donate, averageValue);
	std::cout << "Average value: " << averageValue << std::endl;
	std::cout << "Amount of number which more then average value: "
			  << moreAverageNumber << std::endl;

	return 0;
}

int moreThenAvg(const double donate[ArrSize], const double averageValue)
{
	int count = 0;

	for (int index = 0; index < ArrSize; ++index)
	{
		if (donate[index] > averageValue)
			++count; 
	}
	return count;
}

// Task 3 - Когда вы вступите в Благотворительный Орден Программистов (БОП), к вам
//			могут обращаться на заседаниях БОП по вашему реальному имени, по должности
//			либо секретному имени БОП. Напишите программу, которая может выводить
//			списки членов по реальным именам, должностям либо секретным именам
//			по предпочтению самого члена. В основу положите структуру:
//			struct bop
//			{
//				char fullname[strsize];
//				char title[strsize];
//				char bopname[strsize];
//				int preference;			0 = fullname, 1 = title, 2 = bopname
//			}
//			В этой программе создайте небольшой массив таких структур и инициализируйте
//			его соответствующими значениями. Пусть программа запустит цикл, который даст
//			возможность пользователю выбирать разные альтернативы:
//			a. display by name 		b. display by title
//			c. display by bopname	d. display by preference
//			q. quit
//			Обратите внимание, что "display by preference" (отображать по предпочтениям)
//			не означает, что нужно отобразить член preference; это значит, что необходимо
//			отобразить член структуры, который соответствует значению preference.
//			Например, если preference = 1, то выбор d должен вызвать отображение
//			должности данного программиста.

#include <iostream>
#include <string>

struct bop
{
	std::string fullname;
	std::string title;
	std::string bopname;
	int preference;
};
constexpr size_t ArrSize = 4;
void showmenu();
void showListMembers(bop * const members, const char choice);
void showByPreference(bop * const members);
void fillData(bop * members);

int main()
{
	using namespace std;
	char choice;
	bop * members = new bop [ArrSize];
	fillData(members);
	showmenu();
	cin >> choice;
	while (choice != 'q')
	{
		switch (choice)
		{
			case 'a': showListMembers(members, choice);
					break;
			case 'b': showListMembers(members, choice);
					break;
			case 'c': showListMembers(members, choice);
					break;
			case 'd': showByPreference(members);
					break;
			default: cout << "Have no choice." << endl;
		}
		showmenu();
		cin >> choice;
	}
	delete [] members;
	cout << "Executed";
	//delete [] members;

	return 0;
}

void showmenu()
{
	std::cout << "Enter 'a', 'b', 'c', 'd' (q for quit):\n"
				"a) display by name 		b) display by title\n"
				"c) display by bopname 		d) display by preference\n"
				"q) quit" << std::endl;		
}

void fillData(bop * members)
{
	members[0].fullname = "Sveta";
	members[0].title = "Engineer";
	members[0].bopname = "HolyMolly";
	members[0].preference = 2;

	members[1].fullname = "Seva";
	members[1].title = "Senior C++ Developer";
	members[1].bopname = "LoveAndHate C++";
	members[1].preference = 0;

	members[2].fullname = "Timofey";
	members[2].title = "Specialist";
	members[2].bopname = "MyLife MyRules";
	members[2].preference = 1;

	members[3].fullname = "Alexey";
	members[3].title = "The best team leader around the world";
	members[3].bopname = "Just Lex";
	members[4].preference = 0;
}

void showListMembers(bop * const members, const char choice)
{
	for (int index = 0; index < ArrSize; ++index)
	{
		if (choice == 'a')
			std::cout << members[index].fullname << std::endl;
		else if (choice == 'b')
			std::cout << members[index].title << std::endl;
		else if (choice == 'c')
			std::cout << members[index].bopname << std::endl;
		else
			std::cout << "Wrong symbol." << std::endl;
	}
}

void showByPreference(bop * const members)
{
	for(int index = 0; index < ArrSize; ++index)
	{
		if (members[index].preference == 0)
			std::cout << members[index].fullname << std::endl;
		else if (members[index].preference == 1)
			std::cout << members[index].title << std::endl;
		else if (members[index].preference == 2)
			std::cout << members[index].bopname << std::endl;
	}
}