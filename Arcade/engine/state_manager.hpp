#pragma once
#include <stack>
#include <memory>
#include "game_state.hpp"

namespace engine
{
	class StateManager
	{
	public:
		StateManager() {};
		~StateManager() {};


		void AddState(std::unique_ptr<GameState> state, bool replace);
		void RemoveState() { if (!m_state_stack_.empty()) m_state_stack_.pop(); }


		const std::unique_ptr<GameState>& CurrentState() const { return m_state_stack_.top(); } //top() is UB if stack is empty...

	private:
		std::stack<std::unique_ptr<GameState>> m_state_stack_;
	};
}
/*
TODO
- Add a 	void ProcessStateChanges() function.
	- We can then move modifications of the stack into this function.
	- AddState() will then set flags to tell the  ProcessStateChanges() function what to do.
*/