#include "AI.h"

AI::AI(Coord coord, int cavity, Board board){
	this->board = Board(board);
	this->board.moveTo(coord.x, coord.y, coord.x_, coord.y_);
	this->cavity = cavity + 1;
	if ((cavity % 2) == 1){
		player = P_BLACK;
	}
	else{
		player = P_WHITE;
	}
}
AI::AI(Board board){
	this->board = Board(board);
	this->cavity = 0;
	player = P_WHITE;
}

AI::~AI(){
}

void AI::movements(){
	for (size_t i = 0; i < 8; i++){
		for (size_t j = 0; j < 8; j++){
			if (board.getField(i, j) == player){
				if (player == P_WHITE){
					if (board.getField(i + 1, j + 1) == EMPTY){
						_coord.push_back(Coord(i, j, i + 1, j + 1));
					}
					else if (board.getField(i - 1, j + 1) == EMPTY){
						_coord.push_back(Coord(i, j, i - 1, j + 1));
					}
					else if ((i < 6 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i + 1, j + 1) > EMPTY)){
						_coord.push_back(Coord(i, j, i + 2, j + 2));
					}
					else if ((i < 6 && j > 1) && (board.getField(i + 2, j - 2) == EMPTY) && (board.getField(i + 1, j - 1) > EMPTY)){
						_coord.push_back(Coord(i, j, i + 2, j - 2));
					}
					else if ((i > 1 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i - 1, j + 1) > EMPTY)){
						_coord.push_back(Coord(i, j, i + 2, j + 2));
					}
					else if ((i > 1 && j > 1) && (board.getField(i - 2, j - 2) == EMPTY) && (board.getField(i - 1, j - 1) > EMPTY)){
						_coord.push_back(Coord(i, j, i - 2, j - 2));
					}
				}
				else{
					if (board.getField(i + 1, j - 1) == EMPTY){
						_coord.push_back(Coord(i, j, i + 1, j - 1));
					}
					else if (board.getField(i - 1, j - 1) == EMPTY){
						_coord.push_back(Coord(i, j, i - 1, j - 1));
					}
					else if ((i < 6 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i + 1, j + 1) < EMPTY)){
						_coord.push_back(Coord(i, j, i + 2, j + 2));
					}
					else if ((i < 6 && j > 1) && (board.getField(i + 2, j - 2) == EMPTY) && (board.getField(i + 1, j - 1) < EMPTY)){
						_coord.push_back(Coord(i, j, i + 2, j - 2));
					}
					else if ((i > 1 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i - 1, j + 1) < EMPTY)){
						_coord.push_back(Coord(i, j, i + 2, j + 2));
					}
					else if ((i > 1 && j > 1) && (board.getField(i - 2, j - 2) == EMPTY) && (board.getField(i - 1, j - 1) < EMPTY)){
						_coord.push_back(Coord(i, j, i - 2, j - 2));
					}
				}
			}
			if (board.getField(i, j) == player * 2){

			}
		}
	}
}