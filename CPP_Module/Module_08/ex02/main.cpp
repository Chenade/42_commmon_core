#include "MutantStack.hpp"
#include <list>
#include <algorithm>

int main()

{
	{
		std::cout << "/ ***** Stack ***** /" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		std::cout << "size: " << mstack.size() << std::endl << std::endl;

		mstack.pop();
		std::cout << "top: " << mstack.top() << std::endl;
		std::cout << "size: " << mstack.size() << std::endl << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		std::cout << "printning stack: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;
		std::stack<int> s(mstack);
		std::cout << "/ ***** Stack ***** /" << std::endl;
	}
	
	{
		std::cout << "/ ***** List ***** /" << std::endl;
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);
		std::cout << "top: " << lst.back() << std::endl;
		std::cout << "size: " << lst.size() << std::endl << std::endl;

		lst.pop_back();
		std::cout << "top: " << lst.back() << std::endl;
		std::cout << "size: " << lst.size() << std::endl << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator lst_it = lst.begin();
		std::list<int>::iterator lst_ite = lst.end();
		// ++it;
		// --it;
		std::cout << "printning list: ";
		while (lst_it != lst_ite)
		{
			std::cout << *lst_it << " ";
			++lst_it;
		}
		std::cout << std::endl;
		std::list<int> l(lst);		
		std::cout << "/ ***** List ***** /" << std::endl;
	}

	return (0);
}