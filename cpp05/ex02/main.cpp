#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(){
    try {
        std::cout << "----------------------------------" << std::endl;
        Bureaucrat bureaucrat("Ayoub", 20);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);

        std::cout << "----------------------------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);

        std::cout << "----------------------------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
        std::cout << "----------------------------------" << std::endl;
        
        std::cout << form1 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}