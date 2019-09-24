#include "mazeSolver.h"
#include <iostream>
using namespace std;
mazeSolver::mazeSolver(const vector<vector<char>>& rhsMaze)
{
	this->maze = rhsMaze;
	counter = 0;
	min = 0;
}
void mazeSolver::printMaze()
{
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			cout << maze[index][index2];
		}
		cout << endl;
	}
}
int mazeSolver::findStartX()
{
	int x = -1; //returns -1 if not found
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			if (maze[index][index2] == 'S')
			{
				x = index;
				goto end;
			}
		}
	}
	end:
	return x;
}
int mazeSolver::findStartY()
{
	int y = -1;
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			if (maze[index][index2] == 'S')
			{
				y = index2;
				goto end;
			}
		}
	}
	end:
	return y;
}
int mazeSolver::shortestPath(int row, int col) 
{
	if (maze[row][col] == 'E')
	{
		return counter; //test to return max jumps
	}
	
	maze[row][col] = 'X';
	//check up, down, left, right
	if (row - 1 >= 0) // check up
	{
		if (maze[row - 1][col] == 'O' || maze[row - 1][col] == 'E') 
		{
			counter++; //increment once
			shortestPath(row - 1, col);
			counter--; //decrement once
		}
	}

	if (row + 1 <= maze.size() - 1) //check down
	{
		if (maze[row + 1][col] == 'O' || maze[row+1][col] == 'E')
		{
			counter++;
			shortestPath(row + 1, col);
			counter--;
		}
	}
	if (col - 1 >= 0) //check left
	{
		if (maze[row][col - 1] == 'O' || maze[row][col - 1] == 'E') //check left
		{
			counter++;
			shortestPath(row, col - 1);
			counter--;
		}
	}
	if (col + 1 <= maze[row].size() - 1) //check right
	{
		if (maze[row][col + 1] == 'O' || maze[row][col + 1] == 'E')
		{
			counter++;
			shortestPath(row, col + 1);
			counter--;
		}
	}

	//put back
	maze[row][col] = 'O';
}


