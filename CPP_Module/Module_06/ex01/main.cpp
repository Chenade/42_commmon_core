#include <iostream>

struct Data
{
    std::string name;
    int         age;
};
/*
	Serialization is the process of converting an object in memory 
	to a stream of bytes that can be stored on disk or transmitted 
	over a network. The opposite process is called deserialization, 
	which is the process of converting the stream of bytes back into 
	an object in memory.
*/

/*
	uintptr_t was introduced in C++11 and is not part of the C++98 standard.
	Therefore, if you're using a C++98 compiler, the uintptr_t type will not 
	be recognized and you'll get a compiler error.

	In C++98, you can use unsigned int or unsigned long instead of uintptr_t.
	However, note that the size of unsigned int or unsigned long may vary depending
	on the platform and compiler, so you may need to use a platform-specific type
	or define your own type to ensure portability across different platforms.
*/

// unsigned long    serialize(Data *data)
uintptr_t serialize(Data* data)
{
    return ( reinterpret_cast< unsigned long >( data ) );
}

// Data*   deserialize(unsigned long data)
Data* deserialize(uintptr_t raw)
{
    return ( reinterpret_cast<Data*>(raw) );
}

int main( void )
{
    Data *data = new Data;

    data->name = "ykuo";
    data->age = 23;

    std::cout << "Name: " << deserialize(serialize(data))->name << std::endl;
    std::cout << "Age: " << deserialize(serialize(data))->age << std::endl;

    delete data;

    return (0);
}
