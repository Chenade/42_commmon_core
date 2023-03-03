
#include "Zombie.hpp"

#define N 10

int main( void ) {
    Zombie *zombies = zombieHorde(N, "zombies");

    for (size_t i = 0; i < N; i++) {
        zombies[i].announce();
    }

    delete [] zombies;
    return 0;
}