/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target DFA Packetizer Tables                                               *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace llvm {

// Input format:
#define DFA_MAX_RESTERMS        4	// maximum AND'ed resource terms
#define DFA_MAX_RESOURCES       16	// maximum resource bits in one term

// AMDGPUDFAStateInputTable[][2] = pairs of <Input, NextState> for all valid
//                           transitions.
// 46	states
// 9	instruction classes
// 6	resources max
// 0	combo resources
// 1	stages max
const int64_t AMDGPUDFAStateInputTable[][2] = {
{0x1, 5},	{0xF, 1},	{0x10, 4},	{0x1F, 3},	{0x20, 2},	 // state 0: 0-4
{0x1, 6},	{0xF, 44},	{0x10, 27},	{0x1F, 34},	{0x20, 41},	 // state 1: 5-9
{0x1, 7},	{0xF, 41},	{0x10, 28},	{0x1F, 35},	 // state 2: 10-13
{0x1, 8},	{0xF, 34},	{0x10, 27},	{0x1F, 34},	{0x20, 35},	 // state 3: 14-18
{0x1, 9},	{0xF, 27},	{0x1F, 27},	{0x20, 28},	 // state 4: 19-22
{0xF, 6},	{0x10, 9},	{0x1F, 8},	{0x20, 7},	 // state 5: 23-26
{0xF, 25},	{0x10, 10},	{0x1F, 17},	{0x20, 22},	 // state 6: 27-30
{0xF, 22},	{0x10, 11},	{0x1F, 18},	 // state 7: 31-33
{0xF, 17},	{0x10, 10},	{0x1F, 17},	{0x20, 18},	 // state 8: 34-37
{0xF, 10},	{0x1F, 10},	{0x20, 11},	 // state 9: 38-40
{0xF, 15},	{0x1F, 15},	{0x20, 12},	 // state 10: 41-43
{0xF, 12},	{0x1F, 12},	 // state 11: 44-45
{0xF, 13},	{0x1F, 13},	 // state 12: 46-47
{0xF, 14},	{0x1F, 14},	 // state 13: 48-49
{-1, -1},	 // state 14: 50
{0xF, 16},	{0x1F, 16},	{0x20, 13},	 // state 15: 51-53
{0x20, 14},	 // state 16: 54
{0xF, 21},	{0x10, 15},	{0x1F, 21},	{0x20, 19},	 // state 17: 55-58
{0xF, 19},	{0x10, 12},	{0x1F, 19},	 // state 18: 59-61
{0xF, 20},	{0x10, 13},	{0x1F, 20},	 // state 19: 62-64
{0xF, 14},	{0x10, 14},	{0x1F, 14},	 // state 20: 65-67
{0xF, 16},	{0x10, 16},	{0x1F, 16},	{0x20, 20},	 // state 21: 68-71
{0xF, 23},	{0x10, 12},	{0x1F, 19},	 // state 22: 72-74
{0xF, 24},	{0x10, 13},	{0x1F, 20},	 // state 23: 75-77
{0x10, 14},	{0x1F, 14},	 // state 24: 78-79
{0xF, 26},	{0x10, 15},	{0x1F, 21},	{0x20, 23},	 // state 25: 80-83
{0x10, 16},	{0x1F, 16},	{0x20, 24},	 // state 26: 84-86
{0x1, 10},	{0xF, 32},	{0x1F, 32},	{0x20, 29},	 // state 27: 87-90
{0x1, 11},	{0xF, 29},	{0x1F, 29},	 // state 28: 91-93
{0x1, 12},	{0xF, 30},	{0x1F, 30},	 // state 29: 94-96
{0x1, 13},	{0xF, 31},	{0x1F, 31},	 // state 30: 97-99
{0x1, 14},	{0xF, 14},	{0x1F, 14},	 // state 31: 100-102
{0x1, 15},	{0xF, 33},	{0x1F, 33},	{0x20, 30},	 // state 32: 103-106
{0x1, 16},	{0xF, 16},	{0x1F, 16},	{0x20, 31},	 // state 33: 107-110
{0x1, 17},	{0xF, 39},	{0x10, 32},	{0x1F, 39},	{0x20, 36},	 // state 34: 111-115
{0x1, 18},	{0xF, 36},	{0x10, 29},	{0x1F, 36},	 // state 35: 116-119
{0x1, 19},	{0xF, 37},	{0x10, 30},	{0x1F, 37},	 // state 36: 120-123
{0x1, 20},	{0xF, 38},	{0x10, 31},	{0x1F, 38},	 // state 37: 124-127
{0x1, 14},	{0xF, 14},	{0x10, 14},	{0x1F, 14},	 // state 38: 128-131
{0x1, 21},	{0xF, 40},	{0x10, 33},	{0x1F, 40},	{0x20, 37},	 // state 39: 132-136
{0x1, 16},	{0xF, 16},	{0x10, 16},	{0x1F, 16},	{0x20, 38},	 // state 40: 137-141
{0x1, 22},	{0xF, 42},	{0x10, 29},	{0x1F, 36},	 // state 41: 142-145
{0x1, 23},	{0xF, 43},	{0x10, 30},	{0x1F, 37},	 // state 42: 146-149
{0x1, 24},	{0xF, 24},	{0x10, 31},	{0x1F, 38},	 // state 43: 150-153
{0x1, 25},	{0xF, 45},	{0x10, 32},	{0x1F, 39},	{0x20, 42},	 // state 44: 154-158
{0x1, 26},	{0xF, 26},	{0x10, 33},	{0x1F, 40},	{0x20, 43},	 // state 45: 159-163
{-1, -1}	 // state 46: 164
};

// AMDGPUDFAStateEntryTable[i] = Index of the first entry in DFAStateInputTable for
//                         the ith state.
// 46 states
const unsigned int AMDGPUDFAStateEntryTable[] = {
0, 5, 10, 14, 19, 23, 27, 31, 34, 38,    // states 0:9
41, 44, 46, 48, 50, 51, 54, 55, 59, 62,    // states 10:19
65, 68, 72, 75, 78, 80, 84, 87, 91, 94,    // states 20:29
97, 100, 103, 107, 111, 116, 120, 124, 128, 132,    // states 30:39
137, 142, 146, 150, 154, 159, 164,    // states 40:46
};
} // namespace

#include "llvm/CodeGen/DFAPacketizer.h"
namespace llvm {
DFAPacketizer *AMDGPUGenSubtargetInfo::createDFAPacketizer(const InstrItineraryData *IID) const {
   return new DFAPacketizer(IID, AMDGPUDFAStateInputTable, AMDGPUDFAStateEntryTable);
}

} // End llvm namespace 
