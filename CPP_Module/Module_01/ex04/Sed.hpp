# ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

using namespace std;

class Sed {
	private:
		string _inFile;
		string _outFile;

	public:
		Sed(string filename);
		~Sed();
		void 	sed2(string to_find, string replace_with);
};

#endif