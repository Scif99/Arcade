#pragma once
#include <stack>
#include <memory>
#include "state_base.hpp"

namespace engine
{
	class StateManager
	{
	public:
		StateManager() {};
		~StateManager() {};


		void AddState(std::unique_ptr<StateBase> state, bool replace);
		void RemoveState() { if (!m_state_stack_.empty()) m_state_stack_.pop(); }


		StateBase& CurrentState() const { return *m_state_stack_.top(); } //top() is UB if stack is empty...

	private:
		std::stack<std::unique_ptr<StateBase>> m_state_stack_; //Needs to be of pointer type for polymorphism
	};
}
/*
TODO
- Add a 	void ProcessStateChanges() function.
	- We can then move modifications of the stack into this function.
	- AddState() will then set flags to tell the  ProcessStateChanges() function what to do.
*/