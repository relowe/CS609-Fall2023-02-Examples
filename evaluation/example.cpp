#include <iostream>
#include <fstream>

class Simple
{
public:
    void f() const
    {
        std::cout << "f" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& lhs, const Simple &rhs)
{
    rhs.f();
    return lhs;
}


int main()
{
    Simple s;
    std::ofstream file;
    
    std::cout << "hello, world" << std::endl;
    std::cout << s << std::endl;

    file.open("output.txt");
    file << "hello, world" << std::endl;
    file << s << std::endl;
    file.close();
}