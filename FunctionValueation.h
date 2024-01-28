#pragma once

#ifndef _FUNCTION_VALUATION_
#define _FUNCTION_VALUATION_

#define _FUNCTION_NAME_ARRAY_SIZE_ 100
#include <iostream>
#include "MathFunctions.h"
#include "HashMap.h"


const std::string FunctionNames[_FUNCTION_NAME_ARRAY_SIZE_]   = {"+",    "-",     "*",     "/",    "e",   "pi",     "ceil",          "floor",         "round",   "rad",   "fuct",     "dfuct",   "abs",    "^",      "sqrt",    "exp",    "ln",	  "log",	 "W",    "sin",     "cos",    "tg",   "ctg",     "sec",    "cosec",    "arcsin",   "arccos",    "arctg",    "arcctg",    "sh",    "ch",    "th",    "cth",    "sch",     "csch",    "P",    "C"};
const char FunctionValue[_FUNCTION_NAME_ARRAY_SIZE_]          = { 1,	  1,      2,	    2,      3,      3,         3,               3,               3,        3,       3,           3,        3,       3,          3,        3,       3,       3,        3,       3,         3,        3,      3,         3,          3,         3,           3,          3,           3,         3,       3,       3,       3,        3,          3,       3,      3};
void* FunctionPointers[_FUNCTION_NAME_ARRAY_SIZE_]	  =         {nullptr,nullptr,nullptr,nullptr,const_e,const_pi, ceil_vec2,       floor_vec2,     round_vec2,   rad,  fuct_vec2, dfuct_vec2, abs_vec2, pow_vec2, sqrt_vec2, exp_vec2, ln_vec2, log_vec2, W_vec2,  sin_vec2, cos_vec2, tg_vec2, ctg_vec2, sec_vec2, cosec_vec2, arcsin_vec2, arccos_vec2, arctg_vec2, arcctg_vec2, sh_vec2, ch_vec2, th_vec2, cth_vec2, sch_vec2, csch_vec2, P_vec2, C_vec2};
void* FunctionLimitPointers[_FUNCTION_NAME_ARRAY_SIZE_] =		{nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,l_approximation,l_approximation,l_approximation,nullptr,nullptr,   nullptr,    nullptr,  nullptr,  nullptr,  nullptr, l_ln_vec2,l_log_vec2,l_W_vec2,nullptr,  nullptr,  nullptr,  nullptr,  nullptr, nullptr,   l_arc_vec2,  l_arc_vec2,  l_arc_vec2, l_arc_vec2,  nullptr, nullptr, nullptr, nullptr,  nullptr,  nullptr, l_P_vec2, l_C_vec2 };
const std::string FunctionDataType[_FUNCTION_NAME_ARRAY_SIZE_] = { "vec2","vec2",  "vec2", "vec2","vec2", "vec2",  "vec2",           "vec2",         "vec2",        "ld",  "lli",        "lli",    "vec2",   "vec2",   "vec2",   "vec2",    "vec2", "vec2",   "vec2",   "vec2",   "vec2",  "vec2",   "vec2",   "vec2",    "vec2",   "vec2",     "vec2",       "vec2",      "vec2",     "vec2",  "vec2", "vec2",   "vec2",   "vec2",   "vec2",   "lli",    "lli" };
#endif