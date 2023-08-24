#include "OccupancyMapVector.h"

#include <string>
#include <utility>        // std::pair
#include <vector>

//----------------------------------------------------------------------------------------------------------
// Implementation of occupancy map with 2D vector using base class for an occupancy map.
// An occupancy map accepts observed points, one at a time, to keep track of what parts of space are occupied.
// It offers a function to check if a given point in space is occupied.
//
// This implementation works on coordinates provided as std::pair<int,int>.
// It is acceptable to assume all observed points will be integer, non-negative, and less than 2048
//
// The base class includes a built-in function for evaluating the correctness and speed of a particular derived 
// class implementation of the occupancy map. See EvalPerformance() for details.

COccupancyMapVector::COccupancyMapVector()
{
  data = std::vector<std::vector<bool>>(2048, std::vector<bool>(2048, false));
}

// Return the name of the approach as a string, for display purposes
std::string COccupancyMapVector::GetNameOfApproach()
{
  return "Vector implementation";
}

// Add a location observed to be occupied to the map
void COccupancyMapVector::AddOccupiedLocation(std::pair<int,int> Location)
{
  data[Location.first][Location.second] = true;
}
    
// Check if a location is occupied
bool COccupancyMapVector::CheckIsOccupied( std::pair<int,int> Location )
{
  return data[Location.first][Location.second];
}
