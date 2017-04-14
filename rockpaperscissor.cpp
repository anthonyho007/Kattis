#include <iostream>
#include <string>

using namespace std;

int main ()
{
	int num_player, num_game;
	string rock = "rock";
	string paper = "paper";
	string scissors = "scissors";
	int player1, player2;
	string move1, move2;

	scanf("%d", &num_player);
	while ( num_player != 0)
	{
		int player_score[num_player+2][2];
		for ( int i = 0; i < num_player+2; i++)
		{
			player_score[i][0] = 0;
			player_score[i][1] = 0;
		}
		scanf("%d", &num_game);
		int game = num_game*num_player*(num_player -1)/2;
		for ( int x = 0; x < game; x++)
		{
			cin >> player1 >> move1 >> player2 >> move2;
		//cout << player1 << move1 << player2 << move2 << endl;
			if ( (move1.compare(rock) == 0 && move2.compare(scissors) == 0) || (move1.compare(paper) == 0 && move2.compare(rock) == 0) || (move1.compare(scissors) == 0 && move2.compare(paper) == 0))
			{
				player_score[player1][0] +=1;
				player_score[player2][0] +=1;
				player_score[player1][1] +=1;
			} else if (move1.compare(move2) == 0){
				continue;
			}
			else {
				player_score[player1][0] +=1;
				player_score[player2][0] +=1;
				player_score[player2][1] +=1;
			}
		}
		long double score;
		for ( int y = 1; y <= num_player; y++)
		{
			if (player_score[y][0] == 0)
			{
				printf("-\n");
			} else {
				score =(long double) player_score[y][1] / player_score[y][0];
				printf("%.3LF\n", score);
			}
		}
		cout << endl;
		scanf("%d", &num_player);
	}
}