#include "KnightsTour.h"
#define N 8
#include<iostream>
using namespace std;

typedef struct knight_moves {
	int x;
	int y;
}knight_moves;

const knight_moves MOVES[8] = { { 2,1 },{ 1,2 },{ -1,2 },{ -2,1 },
{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } };


void print_solution(int board[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}

bool is_next_move_possible(knight_moves next_move, int board[N][N]) {
	int i = next_move.x;
	int j = next_move.y;
	if ((i >= 0 && i < N) && (j >= 0 && j < N) && (board[i][j] == 0))
		return true;
	return false;
}


bool find_next_position(int board[N][N], knight_moves current_move, int move_count) {
	knight_moves next_knight_move;

	if (move_count == N * N - 1) {
		return true;
	}

	for (int i = 0; i < N; i++) {

		next_knight_move.x = current_move.x + MOVES[i].x;
		next_knight_move.y = current_move.y + MOVES[i].y;

		if (is_next_move_possible(next_knight_move, board)) {
			board[next_knight_move.x][next_knight_move.y] = move_count + 1;
			if (find_next_position(board,  next_knight_move, move_count + 1) == true) {
				return true;
			}
			else {
				board[next_knight_move.x][next_knight_move.y] = 0;
			}
		}
	}
	return false;
}

bool correctinput(int input)
{
	if (input != 0 || input != 7)
		return false;
	return true;
}

int main() {
	int input_value_row, input_value_column;

	cout << "Please fill in for the row 0 or 7 \n";
	cin >> input_value_row;
	if(!correctinput(input_value_row))
	{
		cout << "That number is not allowed. Please try again \n";
		cin >> input_value_row;
	}


	cout << "Please fill in for the column 0 or 7 \n";
	cin >> input_value_column;
	if (!correctinput(input_value_column))
	{
		cout << "That number is not allowed. Please try again \n";
		cin >> input_value_column;
	}

	
	int board[N][N];
	//Needed in order to dynamicly fill in the array

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
	knight_moves start_move = {input_value_row,input_value_column};
	//board[start_move.x][start_move.y] = 0;


	cout << "Calculating a solution \n";
	if (find_next_position(board, start_move, 0) == true) {
		cout << "\nTour exist ...\n";
		print_solution(board);
		
	}
	else {
		cout << "There's no solution";
	}
	return 0;
}
