#include <QtTest>
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "./../../GrayonSlam/src/datastore/stadium.hpp"

std::string randomString(int length)
{
    std::string string;

    for(int i = 0; i < length; i++)
        string += rand() % ('Z' - 'A') + 'A';

    return string;
}

void printStadium(const Stadium& stadium)
{
    std::cout << std::setw(19) << "ID: "                << stadium.getId()                            << std::endl
              << std::setw(19) << "Name: "              << stadium.getName()                          << std::endl
              << std::setw(19) << "Location: "          << stadium.getLocation()                      << std::endl
              << std::setw(19) << "Seat cap: "          << stadium.getSeatCap()                       << std::endl
              << std::setw(19) << "Year opened: "       << stadium.getYearOpened()                    << std::endl
              << std::setw(19) << "Center field dist: " << stadium.getCenterFieldDist()               << std::endl
              << std::setw(19) << "Roof: "              << Stadium::ROOF_STRING[stadium.roof]         << std::endl
              << std::setw(19) << "Surface: "           << Stadium::SURFACE_STRING[stadium.surface]   << std::endl
              << std::setw(19) << "Typology: "          << Stadium::TYPOLOGY_STRING[stadium.typology] << std::endl;
}

void printSouvenir(const Souvenir& souvenir)
{
    std::cout << std::left
              << std::setw(7) << "ID: "     << souvenir.getId()    << std::endl
              << std::setw(7) << "Name: "   << souvenir.getName()  << std::endl
              << std::setw(7) << "Price: $" << souvenir.getPrice() << std::endl
              << std::right;
}


class init_stadium : public QObject
{
Q_OBJECT

public:
init_stadium();
~init_stadium();

private slots:
void initTestCase();
void cleanupTestCase();
void test_case1();

};

init_stadium::init_stadium()
{
    std::vector<Stadium> stadiums;

    /* Create stadiums and put them into the vector */
    for(int i = 0; i < 5; i++)
    {
        Stadium stadium(randomString(5), randomString(5));
        stadium.hidden = false;
        stadium.roof = static_cast<Stadium::Roof>(i % 3);
        stadium.surface = static_cast<Stadium::Surface>(i % 3);
        stadium.typology = static_cast<Stadium::Typology>(i % 6);

        for(int j = 0; j <= i; j++)
        {
            stadium.addSouvenir(randomString(3), j * 10);
        }

        stadiums.push_back(stadium);
    }

    /* Display each stadium's info */
    for(Stadium stadium : stadiums)
    {
        printStadium(stadium);

        std::vector<Souvenir> souvenirs = stadium.getSouvenirs();

        //Print each souvenir
        std::for_each(souvenirs.begin(), souvenirs.end(), [](Souvenir souvenir){ printSouvenir(souvenir); });
    }

    std::cout << std::endl << std::endl;

    /*
     * Test findSouvenir by going through each of the stadiums
     * and find souvenirs with IDs of [0, vector size).
     * Print out the information of that souvenir regardless
     * whether or not it's an invalid souvenir (ID = -1).
     */
    std::cout << "Testing Stadium::findSouvenir()...\n";

    for(Stadium stadium : stadiums)
    {
        for(int i = 0; i < stadiums.size(); i++)
        {
            Souvenir souvenir = stadium.findSouvenir(i);
            printSouvenir(souvenir);
        }

        std::cout << std::endl;
    }
}

init_stadium::~init_stadium()
{

}

void init_stadium::initTestCase()
{

}

void init_stadium::cleanupTestCase()
{

}

void init_stadium::test_case1()
{

}

QTEST_MAIN(init_stadium)

#include "tst_init_stadium.moc"