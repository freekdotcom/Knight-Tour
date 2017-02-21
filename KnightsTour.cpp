#include "KnightsTour.h"
#define N 8
#include<iostream>
using namespace std;

/// <summary>
/// Prints the solution.
/// </summary>
/// <param name="board">The board.</param>
void print_solution(int board[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}

/// <summary>
/// Determines whether the next move for the knight is possible.
/// </summary>
/// <param name="next_move">The next move of the knight.</param>
/// <param name="board">The board.</param>
/// <returns>
///   <c>true</c> if the next move is possible; otherwise, <c>false</c>.
/// </returns>
bool is_next_move_possible(knight_moves &next_move, int board[N][N]) {
	int i = next_move.x;
	int j = next_move.y;
	if ((i >= 0 && i < N) && (j >= 0 && j < N) && (board[i][j] == 0))
		return true;
	return false;
}


/// <summary>
/// Finds the next position for the knight.
/// </summary>
/// <param name="board">The board.</param>
/// <param name="current_move">The current move.</param>
/// <param name="move_count">The move count.</param>
/// <returns></returns>
bool find_next_position(int board[N][N], knight_moves &current_move, int move_count) {
	knight_moves next_knight_move;

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

	if (move_count == N * N - 1) {
		return true;
	}
	return false;
}

/// <summary>
/// Correctly checks the specified input.
/// </summary>
/// <param name="input">The input.</param>
/// <returns>if the input matches the given contraints</returns>
bool correct_input(int input)
{
	if (input == 0 || input == 7)
		return true;
	return false;
}

/// <summary>
/// Main instance.
/// </summary>
/// <returns></returns>
int main() {
	int input_value_row;
	int input_value_column;

	cout << "Please fill in for the row 0 or 7 \n";
	cin >> input_value_row;
	while (!correct_input(input_value_row))
	{
		cout << "That number is not allowed. Please try again \n";
		cin >> input_value_row;
	}

	cout << "Please fill in for the column 0 or 7 \n";
	cin >> input_value_column;
	while (!correct_input(input_value_column))
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
	knight_moves start_position = {input_value_row,input_value_column};

	cout << "Calculating a solution \n";
	if (find_next_position(board, start_position, 0) == true) {
		cout << "\nTour exist ...\n";
		print_solution(board);
		
	}
	else {
		cout << "There's no solution";
	}
	return 0;
}
