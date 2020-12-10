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
	while((ch = cin.get()) != '@' && ch != '\n')
	{
		if (isalpha(ch))
		{
			if (isupper(ch))
				ch = tolower(ch);
			else
				ch = toupper(ch);
		}
		else if (isdigit(ch))
				continue;
		cout << char(ch) << endl;
	}
	return 0;
}


// Task 2 - Напишите программу, читающую массив double до 10 значений пожертвований.
//			Программа должна прекращать ввод при получении нечисловой величины. Она
//			должна выдавать среднее значение полученных чисел, а также количество
//			значений в массиве, превышающих среднее.

#include <iostream>
#include <array>
#include <cstdlib>
#include <cctype>

constexpr short ArSize = 10;
double fillArray(void);
int showaverage(const double donate[ArSize], const double averageValue);

int main()
{
	int count = 0;
	int moreAverageNumber = 0;
	double sum = 0.0;
	double averageValue = 0.0;
	double donate[ArSize];

	for (int index = 0; index < ArSize; ++index)
	{
		donate[index] = fillArray();
		++count;
		sum += donate[index];
	}
	averageValue = sum / count;
	moreAverageNumber = showaverage(donate, averageValue);
	std::cout << "Average value: " << averageValue << std::endl;
	std::cout << "Amount of number which mote then average value: " << moreAverageNumber << std::endl;

	return 0;
}

double fillArray(void)
{
	double temp;

	std::cout << "Enter value for add in array: ";
	if (std::cin >> temp)
		return temp;
	else
	{
		std::cout << "Some shit" << std::endl;
		exit(EXIT_FAILURE);
	}

}

int showaverage(const double donate[ArSize], const double averageValue)
{
	int count = 0;

	for (int index = 0; index < ArSize; ++index)
	{
		if (donate[index] > averageValue)
			++count; 
	}
	return count;
}

// Task 3 - Когда вы вступите в Благотворительный Орден Программистов (БОП), к вам
//			могут обращаться на заседаниях БОП по вашему реальному имени, по должности
//			либо секретному имени БОП. Напишите программу, которая может выводить
//			списки членов по реальным именам, должностям, секретным именам либо
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
