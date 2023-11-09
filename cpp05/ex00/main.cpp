#include "Bureaucrat.hpp"

int	main(){
	try {
        Bureaucrat bureaucrat("Ayoub", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.GradeInc();
        bureaucrat.GradeDec();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}