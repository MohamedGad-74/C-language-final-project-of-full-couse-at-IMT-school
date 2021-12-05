#ifndef BITMATH_H 
#define BITMATH_H

#define SetBit(VAR,BIT) VAR | (1<<BIT) 
#define ClrBit(VAR,BIT) VAR & (~(1<<BIT))
#define TogBit(VAR,BIT) VAR ^ (1<<BIT)


