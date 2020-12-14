// Task  7 - Напишите программу, которая читает слова по одному за раз, пока не будет введена
//			 отдельная буква 'q'. После этого программа должна сообщить количество слов,
//			 начинающихся с согласных, а также количество слов, не попадающих ни в одну из категорий.
//			 Одним из возможных подходов можеть быть применения isalpha() для различения слов,
//			 начинающихся с букв, и остальных, с последующим применением if или switch
//			 для идентификации тех слов, прошедших проверку isalpha(), которые начинаются
//			 с гласных.

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

int main()
{
	using namespace std;

	char vowel [] {"aeiouy"};
	unsigned short words = 0;
	unsigned short vowels = 0;
	unsigned short consonants = 0;
	unsigned short others = 0;

	string word;
	cin >> word;

	while (word != "q")
	{
		if (isalpha(word[0]))
		{
			strchr(vowel, tolower(word[0])) ? ++vowels : ++consonants;
		}
		else
			++others;
		++words;
		cin >> word;
	}
	cout << "Words: " << words << endl;
	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;

	return 0;
}