// Based on: boost_1_79_0/libs/serialization/doc/index.html
// A more complex example at: boost_1_79_0/libs/serialization/example/demo.cpp

/*
 * You need to build the library first.
 * The easy recipe in Windows is: 
 * 1. Go to the source forder, and execute "bootstrap.bat"
 * 2. Execute "b2.exe install --prefix=${REPO_DIR}/libs/boost/install" // replacing ${REPO_DIR} for your repository directory.
 * Your build will be located at the new folder "bin.v2" in the same source directory.
 * Detailed instructions at: boost_1_79_0/more/getting_started/windows.html
 */

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <fstream>

class gps_position
{
public:
    int degrees;
    int minutes;
    float seconds;
    gps_position(){};
    gps_position(int d, int m, float s) :
        degrees(d), minutes(m), seconds(s)
    {}
};

namespace boost
{
    namespace serialization
    {

    template<class Archive>
    void serialize(Archive & ar, gps_position & g, const unsigned int version)
    {
        ar & g.degrees;
        ar & g.minutes;
        ar & g.seconds;
    }

    } // namespace serialization
} // namespace boost

std::ostream & operator<<(std::ostream& os, const gps_position &position)
{
    return os << position.degrees << "\370 " << position.minutes << "\' " << position.seconds << "\'\'";
}

void save_schedule(const gps_position& s, const char * filename){
    // make an archive
    std::ofstream ofs(filename);
    boost::archive::text_oarchive oa(ofs);
    oa << s;
}

void restore_schedule(gps_position& s, const char * filename)
{
    // open the archive
    std::ifstream ifs(filename);
    boost::archive::text_iarchive ia(ifs);

    // restore the schedule from the archive
    ia >> s;
}

void main()
{
    gps_position position(180, 31, 0);

    // display the position
    std::cout << "gps position: ";
    std::cout << position << std::endl;

    std::string filename = "demofile.txt";

    // save the gps position
    save_schedule(position, filename.c_str());

    // ... some time later
    gps_position restored_position;

    restore_schedule(restored_position, filename.c_str());

    // and display
    std::cout << "restored gps position: ";
    std::cout << restored_position << std::endl;
}