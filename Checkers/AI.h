#include "Board.h"
#include <vector>

struct Coord{
	int x, y, x_, y_;
	Coord(int x, int y, int x_, int y_){
		this->x = x;
		this->y = y;
		this->x_ = x_;
		this->y_ = y_;
	}
};

class AI 
{
public:
	AI(Coord, int, Board);
	AI(Board);
	~AI();
	void movements();
	void rating();
	int getValue();
private:
	int value, cavity;
	vector<AI> node;
	vector<Coord> _coord;
	Board board;
	PLAYER player, opponent;
};

