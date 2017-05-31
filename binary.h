#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <string>
#include <fstream>

template <typename T>
void writeBinary(std::ostream & out, T & data)
{
    out.write( reinterpret_cast<char*>(&data), sizeof(T) );
}

template<>
void writeBinary<std::string>(std::ostream & out, std::string & data)
{
    out.write( data.c_str(), data.size() + 1 );
}

template <typename T>
void readBinary(std::istream & in, T & target)
{
    in.read( reinterpret_cast<char*>(&target), sizeof(T) );
}

template <>
void readBinary<std::string>(std::istream & in, std::string & target)
{
    getline(in, target, '\0');
}

#endif // BINARY_H
