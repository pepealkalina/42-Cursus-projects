#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
        std::cout << "Error: wrong argument\n\n Usage: ./Scalar <argument>" << std::endl;
    return 0;
}
