#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

class Player
{
public:
	std::string nickname;
	int score = 0;
};

int ThrowCube(int cube)
{
	switch (cube)
	{
	case 1:
		std::cout << ">>>>>>>>>>>>" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@  @@@@@" << '\n';
		std::cout << "@@@@    @@@@" << '\n';
		std::cout << "@@@@@  @@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << ">>>>>>>>>>>>" << '\n';
		break;
	case 2:
		std::cout << ">>>>>>>>>>>>" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@@@@@" << '\n';
		std::cout << "@@  @@@@@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@@@@  @@" << '\n';
		std::cout << "@@@@@@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << ">>>>>>>>>>>>" << '\n';
		break;
	case 3:
		std::cout << ">>>>>>>>>>>>" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@  @@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << ">>>>>>>>>>>>" << '\n';
		break;
	case 4:
		std::cout << ">>>>>>>>>>>>" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << ">>>>>>>>>>>>" << '\n';
		break;
	case 5:
		std::cout << ">>>>>>>>>>>>" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@@@@  @@@@@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << ">>>>>>>>>>>>" << '\n';
		break;
	case 6:
		std::cout << ">>>>>>>>>>>>" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << "@@  @@@@  @@" << '\n';
		std::cout << "@@@@@@@@@@@@" << '\n';
		std::cout << ">>>>>>>>>>>>" << '\n';
		break;
	}
	return cube;
}

int Number_of_players(std::string n)
{
	int Num = 0;
	for (int i = 0; n[i] >= '0' && n[i] <= '9' && n.length() <= 2; i++)
	{
		Num = 10 * Num + (n[i] - '0');
	}
	return Num;
}

void REPEAT(Player* arr, int* num, int* MAX)
{

	Player* NewPlayers = new Player[*num];
	int* k = new int;
	*k = 0;
	for (int i = 0; i < *num; i++)
	{
		if (arr[i].score == *MAX)
		{
			NewPlayers[*k].nickname = arr[i].nickname;
			(*k)++;
		}
	}
	if (*k > 1)
	{
		std::cout << '\n';
		std::cout << "��������� ������ ������ � ������������ ����������� �����\n";
		*MAX = 0;
		char* Rep_throw = new char;
		*Rep_throw = 'U';
		for (int i = 0; i < *k; i++)
		{
			while (*Rep_throw != 'Y')
			{
				std::cout << "����� " << NewPlayers[i].nickname << " (����� ������� ����� ������� 'Y'): ";
				std::cin >> *Rep_throw;
				std::cout << '\n';
			}
			for (int j = 0; j < 2; j++)
			{
				NewPlayers[i].score += ThrowCube(rand() % 5 + 1);
			}
			*Rep_throw = 'u';
		}
		std::cout << "����� ����������:" << '\n';
		for (int i = 0; i < *k; i++)
		{
			std::cout << "���� ������ " << NewPlayers[i].nickname << ": " << NewPlayers[i].score << '\n';
			if (NewPlayers[i].score > * MAX)
			{
				*MAX = NewPlayers[i].score;
			}
		}
		REPEAT(NewPlayers, k, MAX);
		delete[] NewPlayers;
		delete Rep_throw;
		delete k;
	}
	else
	{
		delete[] NewPlayers;
		delete k;
	}
}

int main()
{

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(NULL));
	bool mistakes;
	int cube, quality;
	char StartGame = 'Y', Throw = 'U';
	std::string number;
	while (StartGame == 'Y')
	{
		system("cls");
		quality = 0;

		/*����������� ���������� �������:*/

		while (quality < 2)
		{
			std::cout << "������� ���-�� �������(������� 2 ������):";
			std::cin >> number;
			quality = Number_of_players(number);
		}
		Player* players = new Player[quality];

		/*���� ���� ������� � �������� �� �������:*/

		std::cin.ignore(32767, '\n');
		for (int i = 0; i < quality; i++)
		{
			mistakes = true;
			while (mistakes != false)
			{
				std::cout << i + 1 << " ����� ������� ���� ���: ";
				std::getline(std::cin, players[i].nickname);
				mistakes = false;
				for (int j = 0; j < i; j++)
				{
					if (players[i].nickname == players[j].nickname)
					{
						std::cout << "����� ��� ��� ����������" << '\n';
						mistakes = true;
						break;
					}
				}
			}
		}

		/*������� �������.������ ����� ,������� �������� ����� � ��������� ���������� ������ � ��������������
		���� ������ Player:*/


		for (int i = 0; i < quality; i++)
		{
			while (Throw != 'Y')
			{
				std::cout << "����� " << players[i].nickname << " (����� ������� ����� ������� 'Y'): ";
				std::cin >> Throw;
				std::cout << '\n';
			}
			for (int j = 0; j < 2; j++)
			{
				cube = rand() % 5 + 1;
				players[i].score += ThrowCube(cube);
			}
			Throw = 'u';
		}

		/*����� ����� ����������,���������� ����������� ���������� �������� ����� � �������� �� ��� ���� ����:*/

		int* max = new int;
		*max = 0;
		std::cout << "����� ����������:" << '\n';
		for (int i = 0; i < quality; i++)
		{
			std::cout << "���� ������ " << players[i].nickname << ": " << players[i].score << '\n';
			if (players[i].score > * max)
			{
				*max = players[i].score;
			}
		}
		REPEAT(players, &quality, max);
		std::cout << "���� ������ ����������,�� ������� 'Y', ��������� 'N' ";
		std::cin >> StartGame;
		while (StartGame != 'Y' && StartGame != 'N')
		{
			std::cout << "���� ������ ����������,�� ������� 'Y', ��������� 'N' ";
			std::cin >> StartGame;
		}
		delete[] players;
		delete max;
	}
	return 0;
}