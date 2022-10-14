#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): Form("Shrubbery Creation Form", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src)
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	ShrubberyCreationForm(rhs).swap(*this);
	if (M_DEBUG == 1)
		std::cout << "Form " << this->getName() << " copy operated" << std::endl;
	return (*this);
}

/* void	ShrubberyCreationForm::swap(ShrubberyCreationForm &other)
{
	std::swap(this->_isSigned, other._isSigned);
} */

void	ShrubberyCreationForm::executeConcrete() const
{
	std::ofstream	shrubbery;
	std::string		OutputFileName = this->getTarget();

	OutputFileName.append("_shrubbery");
	shrubbery.open(OutputFileName.c_str());
	shrubbery << "                                               ." << 		std::endl;
	shrubbery << "                                    .         ;" << 		std::endl;
	shrubbery << "       .              .              ;%     ;;" << 		std::endl;
	shrubbery << "         ,           ,                :;%  %;" << 		std::endl;
	shrubbery << "          :         ;                   :;%;'     .," << 	std::endl;
	shrubbery << " ,.        %;     %;            ;        %;'    ,;" << 	std::endl;
	shrubbery << "   ;       ;%;  %%;        ,     %;    ;%;    ,%'" << 	std::endl;
	shrubbery << "    %;       %;%;      ,  ;       %;  ;%;   ,%;'" << 		std::endl;
	shrubbery << "     ;%;      %;        ;%;        % ;%;  ,%;'" << 		std::endl;
	shrubbery << "      `%;.     ;%;     %;'         `;%%;.%;'" << 			std::endl;
	shrubbery << "       `:;%.    ;%%. %@;        %; ;@%;%'" << 			std::endl;
	shrubbery << "          `:%;.  :;bd%;          %;@%;'" << 				std::endl;
	shrubbery << "            `@%:.  :;%.         ;@@%;'" << 				std::endl;
	shrubbery << "              `@%.  `;@%.      ;@@%;" << 					std::endl;
	shrubbery << "                `@%%. `@%%    ;@@%;" << 					std::endl;
	shrubbery << "                  ;@%. :@%%  %@@%;" << 					std::endl;
	shrubbery << "                    %@bd%%%bd%%:;" << 					std::endl;
	shrubbery << "                      #@%%%%%:;;" << 						std::endl;
	shrubbery << "                      %@@%%%::;" << 						std::endl;
	shrubbery << "                      %@@@%(o);  . '" << 					std::endl;
	shrubbery << "                      %@@@o%;:(.,'" << 					std::endl;
	shrubbery << "                  `.. %@@@o%::;" << 						std::endl;
	shrubbery << "                     `)@@@o%::;" << 						std::endl;
	shrubbery << "                      %@@(o)::;" << 						std::endl;
	shrubbery << "                     .%@@@@%::;" << 						std::endl;
	shrubbery << "                     ;%@@@@%::;." << 						std::endl;
	shrubbery << "                    ;%@@@@%%:;;;." << 					std::endl;
	shrubbery << "                ...;%@@@@@%%:;;;;,.." << 					std::endl;
}