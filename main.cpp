#include <cstdlib>
#include <iostream>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Printer.h"

using namespace std;

class PrinterTest : public CppUnit::TestCase
{
	public:
		void checkPrinter() {
			Printer printer("YES! We did it!");
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Printer::constructor: printed message doesn't equal to input arguments!", printer.PrintMessage(), (string)"Print: YES! We did it!");
		};
		
		CPPUNIT_TEST_SUITE( PrinterTest );
		CPPUNIT_TEST( checkPrinter );
		CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION( PrinterTest );

int main(int argc, char* argv[]) {
	if (argc >= 3) {
		std::cout << "Too many arguments to this program" << std::endl;
		exit(1);
	}
	// I need to duplicate the code here
	// because of using various constructors in both cases
	else if (argc == 2) {
		Printer printer(argv[1]);
		std::cout << printer.PrintMessage() << std::endl;
	}
	else if (argc == 1){
		Printer printer("");
		std::cout << printer.PrintMessage() << std::endl;
	}
	
	CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
	CppUnit::TextTestRunner runner;
	runner.addTest(test);
	
	runner.run();
}