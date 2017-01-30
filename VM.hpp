#pragma once

#include "IOperand.hpp"
#include <deque>
#include <vector>

class VM
{
	public:

		VM(void);

		void eval(std::vector<std::string const&>);//TODO apramlexexx&shits

		~VM(void);

		std::deque<IOperand const*> stack;

	private:


		VM(VM const&);
		VM& operator=(VM const&);
};
