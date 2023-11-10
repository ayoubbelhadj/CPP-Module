#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){
	try
	{
		Bureaucrat	agent = Bureaucrat("Ayoub", 1);
		Form file = Form("FBI", 4, 3);
		agent.signForm(file);
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}