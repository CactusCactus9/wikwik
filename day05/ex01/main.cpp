#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){
	try{
		Bureaucrat	a("Director", 44);
		Form		f("Top Secret", false, 45, 1);
		Bureaucrat	b("Assistant", 70);
		Form		ff("Secret", true, 45, 1);
		std::cout << f << std::endl;
		a.signForm(f);
		b.signForm(ff);
	}
	catch(std::exception &e){
		std::cout << "Error caught: " << e.what() << std::endl; 
	}

}