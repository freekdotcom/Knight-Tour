#pragma once
#include <vector>;

using namespace std;

struct knight_moves;

void print_solution(int **board);

bool is_next_move_possible(knight_moves next_move,int **board);

bool find_next_position(int **board, knight_moves curr_move, int move_count);

bool correct_input(int input);
