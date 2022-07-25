#include "state_manager.hpp"



//Changes the state associated with a context by pushing the new state onto the stack.
//If the replace flag is set to true, remove the old state from the stack before pushing the new one.
void engine::StateManager::AddState(std::unique_ptr<engine::GameState> new_state, bool replace)
{
	//ASSERT: stack should not be empty is replace is flagged true
	if (replace && !m_state_stack_.empty())
	{
		m_state_stack_.pop();
	}

	m_state_stack_.push(std::move(new_state));

}