#include "Bureaucrat.hpp"

int	main(){
	try {
        Bureaucrat bureaucrat;

        std::cout << bureaucrat << std::endl;

        bureaucrat.GradeInc();
        // bureaucrat.decrementGrade();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}