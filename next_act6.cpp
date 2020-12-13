//next_act6.cpp -- add for homework_act6.cpp

// Task 5 - Королевство Нейтрония, где денежной единицей служит тварп, использует
//			следующую шкалу налогооблажения:
//			первые 5000 тварпов - налог 0 %
//			следуюшие 10000 тварпов - налог 10 %
//			следующие 20000 тварпов - налог 15 %
//			свыше 35000 тварпов - налог 20 %

//			Например, если некто зарабатывает 38000 тварпов, то он должен
//			заплатить налогов 5000 * 0,00 % + 10000 * 0,10 % + 20000 * 0,15 % + 3000 * 0,20 %
//			или 4600 тварпов. Напишите программу, которая использует цикл для
//			запроса доходов и выдачи подлежащего к выплате налога. Цикл должен
//			завершаться, когда пользователь вводит отрицательное или
//			нечисловое значение.

#include <iostream>
#include <cctype>

struct tax
{
	double firstTax;
	double secondTax;
	double thirdTax;
	double fourthTax;
};

void taxCount(const long money, double * taxSum, tax * const Tax);

int main()
{
	using namespace std;
	tax Tax {0.0, 0.1, 0.15, 0.2};
	double taxSum = 0;
	long money;

	cout << "Enter amount of money for tax count: ";
	while (cin >> money && money >= 0)
	{
		taxCount(money, &taxSum, &Tax);
		cout << "Tax sum: " << taxSum << endl;
		cout << "Enter amount of money for tax count: ";
	}

	return 0;
}

void taxCount(const long money, double * taxSum, tax * const Tax)
{
	if (money <= 5000)
	{
		*taxSum = money * Tax->firstTax;
	}
	else if (money > 5000 && money <= 15000)
	{
		*taxSum = 5000 * Tax->firstTax + (money - 5000) * Tax->secondTax;
	}
	else if (money > 15000 && money <= 35000)
	{
		*taxSum = 5000 * Tax->firstTax + 10000 * Tax->secondTax + (money - 15000) * Tax->thirdTax;
	}
	else if (money > 35000)
	{
		*taxSum = 5000 * Tax->firstTax + 10000 * Tax->secondTax + 20000 * Tax->thirdTax + (money - 35000) * Tax->fourthTax;
	}		
}

// Task 6 - Постройте программу, которая отслеживает пожертвования в Общество Защиты
//			Влиятельных лиц. Она должна запрашивать у пользователя количество
//			меценатов, а затем приглашать вводить их имена и суммы пожертвований
//			от каждого. Информация должна сохраняться в динамически выделяемом
//			массиве структур. Каждая структура должна иметь два члена:
//			строку для имени и переменную double для суммы пожертования.
//			После чтения всех данных программа должна отображать суммы пожертвований
//			тех, кто не пожалел 10000$ и более. Этот список должен быть озаглавлен
//			меткой "Grand Patrons". После этого программа должна выдать список остальных
//			жертвователей. Он должен быть озаглавлен "Patrons". Если в одной из двух
//			категорий не окажется никого, программа должна напечатать "none".
//			Помимо отображения двух категорий, никакой другой сортировки делать не нужно

#include <iostream>
#include <string>

struct members
{
	std::string name;
	double money;
};

void fillDonateMembers(members * const Donater, const size_t N, const double overmoney, int * countGrand, int * countCommon);
void sortGrandPatronsAndPatrons(members * const Donater, members * const Patrons, members * const GrandPatrons, const size_t N, const double overmoney);
int main()
{
	using namespace std;
	const double overmoney = 10000;

	cout << "Enter amount of patrons: ";
	size_t N;
	int countGrand = 0;
	int countCommon = 0;
	cin >> N;
	members * Donater = new members [N];
	fillDonateMembers(Donater, N, overmoney, &countCommon, &countGrand);
	members * Patrons = new members [countCommon];
	members * GrandPatrons = new members [countGrand];
	sortGrandPatronsAndPatrons(Donater, Patrons, GrandPatrons, N, overmoney);
	cout << "Here5" << endl;

	cout << "Grand Patrons: " << endl;
	for (size_t index = 0; index < countGrand; ++index)
	{
		cout << GrandPatrons[index].name << endl;
		cout << GrandPatrons[index].money << endl;
	}
	cout << "Patrons: " << endl;
	for (size_t index = 0; index < countCommon; ++index)
	{
		cout << Patrons[index].name << endl;
		cout << Patrons[index].money << endl;
	}
	cout << "Executed.";
	delete [] Donater;
	delete [] Patrons;
	delete [] GrandPatrons;

	return 0;
}

void fillDonateMembers(members * const Donater, const size_t N, const double overmoney, int * countGrand, int * countCommon)
{
	for (size_t i = 0; i < N; ++i)
	{
		std::cout << "Enter donater name: ";
		std::cin >> Donater[i].name;
		std::cout << "Enter amount of donate: ";
		std::cin >> Donater[i].money;
		if (Donater[i].money >= overmoney)
			++*countGrand;
		else
			++*countCommon;
	}
	std::cout << "Here1" << std::endl;
}

void sortGrandPatronsAndPatrons(members * const Donater, members * const Patrons, members * const GrandPatrons, const size_t N, const double overmoney)
{
	size_t indexGrand = 0;
	size_t indexCommon = 0;
	for (size_t i = 0; i < N; ++i)
	{
		if (Donater[i].money >= overmoney)
		{
			GrandPatrons[indexGrand].name = Donater[i].name;
			GrandPatrons[indexGrand].money = Donater[i].money;
			++indexGrand;
			std::cout << "Here2" << std::endl;
		}
		else
		{
			Patrons[indexCommon].name = Donater[i].name;
			Patrons[indexCommon].money = Donater[i].money;
			++indexCommon;
			std::cout << "Here3" << std::endl;
		}
	}
	std::cout << "Here4" << std::endl;
}