#include "Sed.hpp"
#include <fstream>

using namespace std;

Sed::Sed(string filename) : _inFile(filename){
    this->_outFile = this->_inFile + ".replace";
}

Sed::~Sed()
{
}

void Sed::sed2(string to_find, string replace_with)
{
	ifstream ifs;
	string content;

	ifs.open(this->_inFile.c_str());
	if (!ifs) {
		cerr << "Unable to open the file." << endl;
		return;
	}
	if (getline(ifs, content, '\0')) {
		ofstream   ofs(this->_outFile.c_str());
		size_t          pos = content.find(to_find);

		while ( pos != string::npos ) {
			content.erase(pos, to_find.length());
			content.insert(pos, replace_with);
			pos = content.find(to_find);
		}
		ofs << content;
		ofs.close();
	}
	else
		cerr << "Empty file found." << endl;
	ifs.close();
}