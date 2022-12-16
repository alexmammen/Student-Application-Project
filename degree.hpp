#pragma once
#ifndef degree_hpp
#define degree_hpp
#include <string>

enum DegreeType { SECURITY, NETWORK, SOFTWARE };

//enum type is actually an integer so it is necessary to create a string type of the DegreeType so we can output that to the user
static const std::string degreeTypeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

#endif
