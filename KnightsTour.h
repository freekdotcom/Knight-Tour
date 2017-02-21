#pragma once
#include <vector>;

using namespace std;

typedef struct knight_moves {
	int x;
	int y;
}knight_moves;

const knight_moves MOVES[8] = { { 2,1 },{ 1,2 },{ -1,2 },{ -2,1 },
{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } };

void print_solution(int **board);

bool is_next_move_possible(knight_moves next_move,int **board);

bool find_next_position(int **board, knight_moves curr_move, int move_count);

bool correct_input(int input);
