#include "Sed.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "Usage: ./replace <filename> <to_find> <replace>" << endl;
		return (1);
	}
	Sed sed(argv[1]);
	sed.sed2(argv[2], argv[3]);
	return (0);
}