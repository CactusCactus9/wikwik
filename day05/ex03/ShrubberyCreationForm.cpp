#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//--------def constructor--------//
ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shruberry", false, 145, 137){};

//--------copy constructor--------//
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj):AForm("Shruberry", false, 145, 137){
	*this = obj;
}

//--------copy assignment operator--------//
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this!= &other){
		this->_target = other._target;
	}
	return (*this);
}

//--------throw exceptions--------//
const char *ShrubberyCreationForm::ShrubberryException::what() const throw() {
	return "Error! File opening failed!";
}

//--------parameterized constructor--------//
ShrubberyCreationForm::ShrubberyCreationForm(std::string targ): AForm("Shruberry", false, 145, 137), _target(targ){};

//--------Others--------//
void	ShrubberyCreationForm::createFile(std::string &_target){
	std::ofstream output(_target + "_shrubbery");
	if (!(output.is_open()))
		throw ("file not open!");
	
																					
																				
output<<"                         .**/.                                                 "<<std::endl;   
output<<"                      ,/*/( /(/(%*/(/(  ,//, .,/*(/ ,. .  ,*  (                "<<std::endl; 
output<<"                //..*,/(/(//#%#%((///(((,(//(((/(((//(///((%/**                "<<std::endl;
output<<"           ///(/ /(/#/%/((//*(((%((*///(%(//((/(//((/(((#(%%,,%(.              "<<std::endl;
output<<"         ,/((./#%((/(#/(/,/(%/%//(/%(/((%(/(/((((((%/(/(#/(//(//((////          "<<std::endl;
output<<"         ./*.(#%#(/#%,#/,/##%# .#/((%(((((.(/((/%#//((/%(%((##((/(/((           "<<std::endl;
output<<"           *.((/(((///((((/(((((///&(%&((#//%(/(#..% %#%(%%#%/#(/(#//.,/        "<<std::endl;
output<<"        (*//(%(#((//((/%((/(%/%(%%/**(#((///((/%(#%(%%%%(*#.%%(//(%%((%/.       "<<std::endl;
output<<"       /,#/.&/%##//(//((%(/// %//(%((((((//(#/(((/((/(/(/(((/(%#/*((/((///(/(   "<<std::endl;
output<<"    ((%#(./((((%(/((#(((/((%/(/(,#(*## ( (/(/(#/(((/%(%/////#///#/(///((((/     "<<std::endl;
output<<"   /*,(/(%#%#(%((%%%/##(%(((((.//(((*//((#/(((((((/(//#(#(((((/(/(#(*#(%(/(%((  "<<std::endl;
output<<"   **(#(((/&//%.(* %(%%%%%(#(/%(//(#.%%*(%%  #%%%/ /%/%./(((((//,((##(%#(#%(/#  "<<std::endl;
output<<"    **/(#(%(##/*%,%%((%%%%#  (%#(//%%%(%%.#%  **#/.#/(&////((((((((//((/(%      "<<std::endl;
output<<"    .#%#(%%%/((%/*/%(((/%(#   *% %%&# %   (  #(%%%/#,/((((%/*&%#(/(#%#((((/     "<<std::endl;
output<<"       (  %%///((((((#/(#/#/   &&  %(     & (/ .%%,%  &/%*/(%(#/, (((#(/.(/*    "<<std::endl;
output<<"          ( /*&/#((#/((#/*      #&  %#    &%    & %  &   (&%#.##((#((*%%(% (,   "<<std::endl;
output<<"          *(#/*. *,%/% %*&&(,   ,&#& &( #%/   .&&#%(&.           .%  ,% %       "<<std::endl;
output<<"                    (%&            &(&(%&%*%&%#                                 "<<std::endl;
output<<"                                   .##&(&(&#                                    "<<std::endl;
output<<"                                     %&#&#(                                     "<<std::endl;
output<<"                                     %&%&##                                     "<<std::endl;
output<<"                                   (#(&#&(&#                                    "<<std::endl;
output<<"                               ,  &#(&&#(&#&&(                                  "<<std::endl;	
output.close();
}
void	ShrubberyCreationForm::execute(Bureaucrat const &executor){
	if (getIfSigned() == true && getExecutedGrade() >= executor.getGrade())
		createFile(_target);
	else
		throw GradeTooLowException();
}

//--------Destructor--------//
ShrubberyCreationForm::~ShrubberyCreationForm(){};


