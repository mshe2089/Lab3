// OccupancyMap_Base.h
//
// Implementation of occupancy map with 2D vector using base class for an occupancy map.
//
// The base class knows how to evaluate the performance of a given occupancy map implementation by :
// 1) loading a pair of test files, one defining a list of test points corresponding to observed occupied
// locations, and one defining a set of test points corresponding to unoccupied space,
// 2) populating the occupancy map with observed points by calling its AddOccupiedLocation function, and
// 3) testing the occupancy map by checking that it returns correct values for the loaded test data
//
// The test also reports on how long it takes to run through all the test points, to allow a comparison
// of speed.

#ifndef _OCCUPANCYMAPVECTOR_H
#define _OCCUPANCYMAPVECTOR_H

#include "OccupancyMapBase.h"

#include <string>
#include <utility>        // std::pair
#include <vector>

class COccupancyMapVector : public COccupancyMapBase
{
  public:
    // Con struc tor
    COccupancyMapVector();

    // Return the name of the approach as a string, for display purposes
    std::string GetNameOfApproach();

    // Add a location observed to be occupied to the map
    void AddOccupiedLocation(std::pair<int,int> Location);
    
    // Check if a location is occupied
    bool CheckIsOccupied( std::pair<int,int> Location );

  private:

  std::vector<std::vector<bool>> data;

};

#endif // _OCCUPANCYMAPVECTOR_H

