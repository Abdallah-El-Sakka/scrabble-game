#include <iostream>
using namespace std;

const int SIZE = 27;

int SCORES[] = { 1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };

struct scrabble {

	int score;
	char capLetter;
	char smallLetter;

};

void defineGameLists(scrabble list[])
{

	int i, start, end;

	//Smalls
	//ASCII from a(97) to z(122)
	start = 97;
	end = 122;
	i = 0;

	while (start <= end)
	{
		list[i].smallLetter = start;

		start++;

		i++;
	}

	 //Capitals
	//ASCII from A(65) to Z(90)
	start = 65;
	end = 90;
	i = 0;

	while (start <= end)
	{
		list[i].capLetter = start;

		start++;

		i++;
	}

	//scores
	for (int i = 0; i < SIZE; i++)
	{
		list[i].score = SCORES[i];
	}

}

void getInputsFromUser(string* player1, string* player2)
{
	cout << "Player1 : " << endl;
	cin >> *player1;

	cout << "Player2 : " << endl;
	cin >> *player2;
}

int getScore(string input, scrabble list[])
{

	int score = 0;

	int length = input.length();

	for (int i = 0 ; i < SIZE; i++)
	{

		for (int j = 0; j < length; j++)
		{

			(input[j] == list[i].smallLetter || input[j] == list[i].capLetter) ? score += list[i].score : NULL ;

		}

	}

	return score;
}

void printResults(string player1,string player2 , scrabble list[])
{

//		cout << "player 1 = " << getScore(player1, list) << endl;
//		cout << "player 2 = " << getScore(player2, list) << endl;

	if (getScore(player1, list) > getScore(player2, list))
		cout << "Player 1 wins!" << endl;
	else if (getScore(player1, list) < getScore(player2, list))
		cout << "Player 2 wins!" << endl;
	else
		cout << "Tie!" << endl;
}

int main()
{

	scrabble game[SIZE];
	defineGameLists(game);

	string player1, player2;
	getInputsFromUser(&player1, &player2);

	printResults(player1, player2, game);

	return 0;
}
