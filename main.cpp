
// a start on a test file for developing your occupancy maps
#include "OccupancyMapVector.h"
#include "OccupancyMapHash.h"
#include <iostream>

//- Forward declarations ----------------------------------------------------------------------------

void TestOccupancyMapHash(); // Test set based occupancy map

void TestOccupancyMapVector(); // Test vector based occupancy map

//- Main program ----------------------------------------------------------------------------

int main()
{
  TestOccupancyMapVector();

  TestOccupancyMapHash();

  return 0;
}

//- Test functions ----------------------------------------------------------------------------

void TestOccupancyMapHash()
{
  // Simple correctness test
  {
    COccupancyMapHash myOccupancyMap;

    std::pair<int,int> TestLocation = std::make_pair(3, 4);
    myOccupancyMap.AddOccupiedLocation( TestLocation );
    
    std::cout << "Location: " << TestLocation.first << " " << TestLocation.second << " returns ";
    std::cout << myOccupancyMap.CheckIsOccupied( TestLocation ) << std::endl; 
    
    TestLocation.first = 0;
    std::cout << "Location: " << TestLocation.first << " " << TestLocation.second << " returns ";
    std::cout << myOccupancyMap.CheckIsOccupied( TestLocation ) << std::endl; 
  }

  // More comprehensive test
  {
    COccupancyMapHash myMap;
    myMap.EvalPerformance( "ExampleObservations_Small.txt", "ExampleNotObserved_Small.txt" );
  }
}

void TestOccupancyMapVector()
{
  // Simple correctness test
  {
    COccupancyMapVector myOccupancyMap;

    std::pair<int,int> TestLocation = std::make_pair(3, 4);
    myOccupancyMap.AddOccupiedLocation( TestLocation );
    
    std::cout << "Location: " << TestLocation.first << " " << TestLocation.second << " returns ";
    std::cout << myOccupancyMap.CheckIsOccupied( TestLocation ) << std::endl; 
    
    TestLocation.first = 0;
    std::cout << "Location: " << TestLocation.first << " " << TestLocation.second << " returns ";
    std::cout << myOccupancyMap.CheckIsOccupied( TestLocation ) << std::endl; 
  }

  // More comprehensive test
  {
    COccupancyMapVector myMap;
    myMap.EvalPerformance( "ExampleObservations_Small.txt", "ExampleNotObserved_Small.txt" );
  }
}