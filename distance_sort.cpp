#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

struct dist_to_data
{
    std::string m_name;
    int m_number;

    // default constructor
    dist_to_data( std::string name="", int number = 0) :
    m_name(name), m_number(number) {}

    // less than operator
    bool operator <(dist_to_data b) const ;
};

// less than operator implementation ( I might have the const not quite right
// i struggle with const correctness.

bool dist_to_data::operator<(dist_to_data b) const
{
    int32_t t = m_name.compare( b.m_name);

    if( t > 0 ) {
        return false;
    }
    else if( t < 0 )
    {
        return true;
    }
    else if( m_number > b.m_number )
    {
        return true;
    }

    // add other tests
    // refer to std::sort
    return false;
}

int main(int argc, char **argv )
{

    std::vector<dist_to_data> data;
    dist_to_data d3("Munich", 173) ;
    dist_to_data d4("Biberach", 30);
    data.push_back( dist_to_data("Stuttgart", 173) );
    data.push_back( dist_to_data("Zurich", 30) );
    data.push_back( d3 );
    data.push_back( d4 );

    std::cout <<  "Distance from Weingarten \t" << std::endl;

    for( size_t i = 0; i < data.size(); ++i )
    {
        std::cout << "name, number:\t" <<
            data[i].m_name <<
            " " <<
            data[i].m_number << std::endl;
    }
    std::cout << std::endl;

    std::sort( data.begin(), data.end() );

    std::cout <<  "Sorting the Equal Distances from Weingarten \n" << std::endl;
    for( size_t i = 0; i < data.size(); ++i )
    {
        std::cout << "name, number:\t" <<
            data[i].m_name <<
            " " <<
            data[i].m_number << std::endl;
    }

    return 0;
}
