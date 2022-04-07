#include <iostream>
#include <ctime>
#include <string>


void FAILS(int quantity)
{
	switch (quantity)
	{
	case 1:
		std::cout << "                            " << '\n';
		std::cout << " # # # # # # # # # # #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   O      " << '\n';
		std::cout << " #                   |      " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		break;
	case 2:
		std::cout << "                            " << '\n';
		std::cout << " # # # # # # # # # # #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   O      " << '\n';
		std::cout << " #                   |      " << '\n';
		std::cout << " #                   |      " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		break;
	case 3:
		std::cout << "                            " << '\n';
		std::cout << " # # # # # # # # # # #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   O      " << '\n';
		std::cout << " #                   |\\    " << '\n';
		std::cout << " #                   |      " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		break;
	case 4:
		std::cout << "                            " << '\n';
		std::cout << " # # # # # # # # # # #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   O      " << '\n';
		std::cout << " #                  /|\\    " << '\n';
		std::cout << " #                   |      " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		break;
	case 5:
		std::cout << "                            " << '\n';
		std::cout << " # # # # # # # # # # #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   O      " << '\n';
		std::cout << " #                  /|\\    " << '\n';
		std::cout << " #                   |      " << '\n';
		std::cout << " #                    \\    " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		break;
	case 6:
		std::cout << "                            " << '\n';
		std::cout << " # # # # # # # # # # #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   #      " << '\n';
		std::cout << " #                   O      " << '\n';
		std::cout << " #                  /|\\    " << '\n';
		std::cout << " #                   |      " << '\n';
		std::cout << " #                  / \\    " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		std::cout << " #                          " << '\n';
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int FULLword = 0, Fails = 0, h = 0, l;
	char letter;
	std::string Word, Hide_Word;
	std::cout << "Введите слово: ";
	std::getline(std::cin, Word);
	Hide_Word = Word;
	system("cls");
	l = Word.length();
	for (int i = 0; i < l; i++)
	{
		Hide_Word[i] = '*';
		std::cout << Hide_Word[i];
	}
	std::cout << '\n';
	while (FULLword < l && Fails < 6)
	{
		std::cin >> letter;
		for (int i = 0; i < l; i++)
		{
			if (letter == Word[i])
			{
				FULLword++;
				h++;
				Hide_Word[i] = letter;
			}
		}
		if (h == 0)
		{
			Fails++;
			FAILS(Fails);
		}
		else
		{
			for (int i = 0; Hide_Word[i] != '\0'; i++)
			{
				std::cout << Hide_Word[i];
			}
			std::cout << '\n';
		}
		h = 0;
	}
	if (Fails == 6)
	{
		std::cout << "Вы проиграли,загаданное слово: " << Word << '\n';
	}
	else
	{
		std::cout << "Вы выиграли!" << '\n';
	}
	return 0;
}