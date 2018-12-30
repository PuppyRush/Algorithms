
#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <array>
#include <cassert>

using namespace std;

typedef struct COORD {
public:
	int x;
	int y;
    COORD(){}
    COORD(const int x, const int y)
    :x(x),y(y)
    {}

    friend bool operator<(const COORD &lhs, const COORD& rhs)
    {
        if(lhs.x == rhs.x)
            return lhs.y < rhs.y;
        else
            return lhs.x < rhs.x;
    }

}COORD;


int figureType[4][3][2] =
{
	{
		{0,0},{1,0},{0,1}
	},
	{
		{0,0},{0,1},{1,1}
	},
	{
		{0,0},{1,0},{1,1}
	},
	{
		{ 0,0 },{ 1,0 },{ 1,-1 }
	}
};

int next[4][2] =
{
	{0,-1},
	{-1,0},
	{1,0},
	{0,1},
};

bool draw(int **board,set<COORD> unique, const int W, const int H, const int x,const int y, const int figure, bool dr)
{
    int l=0;
    array<COORD,3> coord;
    for (l = 0; l < 3; l++) {
        int next_x = x + figureType[figure][l][0];
        int next_y = y + figureType[figure][l][1];

        if (next_x < 0 || next_x >= W || next_y < 0 || next_y >= H)
            break;

        if (board[next_y][next_x] == '#')
            break;

        coord[l].x = next_x;
        coord[l].y = next_y;
    }
    if(l==3)
    {
        if(dr)
        {
            for(int l=0 ; l < 3 ; l++)
            {
                COORD c(coord[l].y, coord[l].x);
                board[c.y][c.x] = '#';
                unique.erase(std::move(c));
            }
        }
        else
        {
            for(int l=0 ; l < 3 ; l++)
            {
                COORD c(coord[l].y, coord[l].x);
                board[c.y][c.x] = '.';
                unique.insert(std::move(c));
            }
        }
    }
}

vector<array<COORD,3>> getNext(int **board, const int H, const int W,const int x,const int y)
{
    vector<array<COORD,3>> coords;
    coords.reserve(4);
    for(int i=0 ; i < 4 ; i++) {
        int l = 0;
        array<COORD,3> coord;
        for (l = 0; l < 3; l++) {
            int next_x = x + figureType[i][l][0];
            int next_y = y + figureType[i][l][1];

            if (next_x < 0 || next_x >= W || next_y < 0 || next_y >= H)
                break;

            if (board[next_y][next_x] == '#')
                break;

            coord[l].x = next_x;
            coord[l].y = next_y;
        }
        if(l==3) {
            coords.push_back(coord);
        }
    }

    return coords;
}

int answer=0;
bool find2(int **board,set<COORD> unique, const int H, const int W,const int x,const int y, const int figure)
{
    if(!draw(board,unique,W,H,x,y,figure,true))
        return false;

    for(int i=0 ; i < 4 ; i++)
    {
        find2(board,unique,H,W,x,y,i+1);
    }

    draw(board,unique,W,H,x,y,figure,false);

    /*if(unique.empty()) {
        return true;
    }*/
}

int main()
{

	int C=0;
	scanf("%d", &C);

	for(int i=0 ; i < C ; i++)
	{
		int H=0;
		int W=0;
		scanf("%d %d",&H, &W);

		int **board = new int*[H];
		for(int l=0 ; l < H ; l++)
			board[l] = new int[W];

		set<COORD> coords;
		for(int i=0 ; i < H ; i++) {
			for (int l = 0; l < W; ) {
			    char c = 0;
				scanf("%c", &c);
				if( c == '\n' || c == ' ')
				    continue;
				board[i][l] = c;
				if (board[i][l] == '.')
                    coords.insert(COORD(l,i));
				l++;
			}
		}

        for(const auto coord : coords)
        {
            find2(board,coords, H, W, coord.x, coord.y);
        }

	}

}