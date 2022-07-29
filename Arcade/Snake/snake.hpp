#pragma once
#include <SFML/System/Time.hpp>

#include <utility>
#include <vector>
#include <unordered_map>
#include <string>

//A piece is a node representing a part of the snake
//Each piece consists of a pair of coordinates representing it's position on the grid
//Each piece also contains direction, represented by a 2d unit vector
struct Piece
{
	std::pair<int, int> m_location_;
	std::pair<int, int> m_direction_; //(x,y)

	Piece(int x, int y, int x_dir, int y_dir)
		:m_location_{ x,y }, m_direction_{ x_dir, y_dir } {}
};


//A snake is a vector of pieces
class Snake
{
public:

	Snake(int x, int y) //Constructor
		:m_body_{ Piece{x,y,0,0} } {}


	void add_piece(); //Adds a piece to the tail of the snake, increasing the length of the snake by 1 node
	void update_direction(); //Updates directions of each piece in the snake
	void update_position(); //Updates positions of each piece in the snake
	bool contains(int x, int y) const; //Function that returns true if the node at coordinates (x,y) is a snake piece
	bool intersect() const; //Checks whether the snake has a self-collision
	void reset();

	Piece& front() { return m_body_[0]; } 
	const Piece& front() const { return m_body_[0]; }
	int size() const { return m_body_.size(); }

private:
	std::vector<Piece> m_body_; //The snake is  a vector of coordinate pairs. body[0] is the first element
};