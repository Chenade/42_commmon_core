
#include "Harl.hpp"

using namespace std;

int main(int argc, char *argv[] )
{
    Harl	harl;

    if (argc != 2)
    {
        cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << endl;
        return (1);
    }
    harl.complain(argv[1]);

    return (0);
}