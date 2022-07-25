#include "snake.hpp"

void Snake::add_piece()
{
	Piece last_piece = m_body_.back();
	std::pair<int, int> new_coords{ last_piece.m_location_.first - last_piece.m_direction_.first, //coords of piece to be added
									last_piece.m_location_.second - last_piece.m_direction_.second };
	std::pair<int, int> new_dir{ last_piece.m_location_.first - new_coords.first, last_piece.m_location_.second - new_coords.second };

	m_body_.emplace_back(new_coords.first, new_coords.second, new_dir.first, new_dir.second);
}

void Snake::update_direction()
{
	for (int i = 1;i < m_body_.size();++i) //Index from 1 since the first piece's direction is determined by user input
	{
		m_body_[i].m_direction_.first = m_body_[i - 1].m_location_.first - m_body_[i].m_location_.first;
		m_body_[i].m_direction_.second = m_body_[i - 1].m_location_.second - m_body_[i].m_location_.second;
	}
}

void Snake::update_position()
{
	for (auto& piece : m_body_)
	{
		piece.m_location_.first += piece.m_direction_.first;
		piece.m_location_.second += piece.m_direction_.second;
	}
}


bool Snake::intersect() const
{
	for (int i = 1;i < m_body_.size();++i) //Start at index 1 to avoid weirdness
	{
		if (m_body_[0].m_location_ == m_body_[i].m_location_) return true;
	}
	return false;
}




bool Snake::contains(int x, int y) const //Checks whether a piece of the snake lies on node with coordinates (x,y)
{
	for (const auto& piece : m_body_)
	{
		if (piece.m_location_.first == x && piece.m_location_.second == y) return true;
	}
	return false;
}

//Reset snake to starting point, with only one piece
void Snake::reset()
{
	Piece start{ 10,10,0,0 };
	m_body_ ={ start };
}