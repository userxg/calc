#pragma once

#ifndef _FUNCTION_VALUATION_
#define _FUNCTION_VALUATION_

#define _FUNCTION_NAME_ARRAY_SIZE_ 10
#include <iostream>
#include "MathFunctions.h"

const std::string FunctionNames[_FUNCTION_NAME_ARRAY_SIZE_] = { "Add",	"Sub","Mul",	  "Div","sin","cos","ln","lg","tg","ctg"};
const char FunctionValue[_FUNCTION_NAME_ARRAY_SIZE_]        = {   1,	  1,    2,			2,    3,    3,   3,   3,   3,    3};
vec2(*FunctionPointers[_FUNCTION_NAME_ARRAY_SIZE_])(const vec2&) = {};
#endif