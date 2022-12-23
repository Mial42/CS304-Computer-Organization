/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Nicholas Wilson
 * nbwilson
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */
//Note: Made heavy use of this site: https://graphics.stanford.edu/~seander/bithacks.html
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
  //return 2;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  /*
  Right shift carries in the leftmost digit on signed ints
  So make the LSB the leftmost digit, then shift it all the way right again
  */
  x = x << 31;
  x = x >> 31;
  return x;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*
  Use & + a bitmask 0xff to get the final byte of x
  To get the n byte of x in the final position, need to shift it over rightwards
  If n = 0, shift it over 0 times. If n = 1; shift it over 8 bits, 
  if n = 2; shift it 16 bits, if n = 3, shift it 24 bits
  In other words, shift x rightwards by n shifted leftwards by 3
  */
  x = x >> (n << 3);
  x = x & 0xff;
  return x;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /*
    x ^ y will return a bit 1 if the bit in x and the bit in y are different
    If they're all the same, it will return all 0s. Not should invert that,
    getting the correct answer.
  */
  return !(x^y);
  //return 2;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /*
  Strategy: build two separate bitmasks
  Start with all ones, shift them over either
  highbit +1 or lowbit
  And them together to get final result
  */
  int high= ~0 << highbit;
  int low = ~0 << lowbit;
  high = ~(high << 1);
  return high & low;
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /*
  Strategy: Extract and shift each of four bytes
  Mask the appropriate bytes, then shift them the correct number of steps
  Bitwise OR all of them together to get the final result
  */
 	int temp1 =((x)&(0x000000FF))<<24;
	int temp2 =((x>>8)&(0x000000FF))<<16;
	int temp3 =((x>>16)&(0x000000FF))<<8;
	int temp4 =(x>>24)&(0x000000FF);
	return (temp1|temp2|temp3|temp4);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /*
  Create the one's and two's complement of x
  One's complement will be all 1s if x is 0 (= -1)
  Two's complement will be all 0s if x is 0 (= 0)
  The complement of the two's complement will be all 1s if
  x = 0. 1 & 1 = 1
  If x has a 1 in the MSB, the one's complement will have a 0
  and the two's complement will have a 1. Inverted, the two's
  complement will have a 0. 0 & 0 = 0
  If x has a 0 in the MSB, the one's complement will have a 1
  in the MSB and the two's complement will have a 0. Inverted two's
  complement will have a 1. 1 & 0 = 0
  The one's complement & the complement of the two's complement of x
  together will put either a 1 or a 0 in the MSB. If x is 0, it will put 
  a 1 in the MSB. If x =/=, it will put a 0 in the MSB. Then just use a mask
  and rightshift by 31 to return the MSB. 
  */
  int oComplement = ~x; //Ones complement of x
  int tComplement = oComplement + 1; //Two's complement of x
  x = oComplement & ~tComplement;
  return (x >> 31) & 1;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /*
  Taking the two's complement will give all 0s if x is 0
  If not, there will be a "ripple" of 1s carried over from adding
  1 to the one's complement until you reach the first point
  where the one's complement has a 0/the original has a 1
  To the left of this point, the one's and two's complement are the same
  To the right of this point, the two's complement is all 0s
  So the only bit which is 1 in both the two's complement and x
  is the least significant one bit.
  */
  int tComplement = (~x + 1);
  return x & tComplement;
  //return 2;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  /*
  One's complement of 0 is all ones, which is -1
  */
  return (~0);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /*
  Max two's complement integer is the one's complement of 1 shifted all the way
  to the left. 0 followed by all ones.
  */
  return ~(1 << 31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /*
  Goal is to check if -2^{n-1} <= x <= (2^{n-1} - 1)
  Find the difference between 32 and n
  Make all the digits except the last n ones the sign digit
  Checks that x == sign extended version of x
  */
 int difference = 32 + (~n + 1); //Difference between 32 and n
 int sign_extend = (x<<difference)>>difference;//Make all the digits except the last n ones the sign digit

 return !(x ^ sign_extend); //Checks that x == sign extended version of x
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /*
  Strategy: Get the raw sum of x + y and the sign bits for x, y, and the raw sum
  xSignBit ^ ySignBit tells you if the two have different signs
  Overflow is only possible if they have the same sign
  If they have the same signs, the complement of xSignBit ^ ySignBit will be all 1s
  xSignBit ^ sumSignBit tells you if x and the sum have the same sign. If they do,
  it will be all 1s. If not, it will be all 0s. If two operands have the same sign,
  but the sum has a different sign, you'll get 1, else 0. ! that gives you the correct answer.
  */
  int sum = x + y;
  int xSignBit = x >> 31;
  int ySignBit = y >> 31;
  int sumSignBit = sum >> 31;
  int temp1 = ~(xSignBit ^ ySignBit);
  int temp2 = xSignBit ^ sumSignBit;
  int temp3 = temp1 & temp2;
  return !temp3;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /*
  First, subtract y from x using + and ~ and shift the leftmost bit to the right
  If x > y, this will be 1, else 0, ignoring sign. With sign, other way around,
  hence !. This gives the answer provided x is negative or y is positive,
  but not if x is positive and y is negative.
  To make sure the sign bits work out, isolate the sign bits and return true if 
  x is positive and y is negative.
  */
  int step1 = !((x + ~y) >>31);
  int xSignBit = x >> 31;
  int ySignBit = y >>31; 
  int posXNegY = !xSignBit & ySignBit;
  int otherCase = step1 & (!xSignBit | ySignBit); //If x > y and x is negative or y is positive
  return posXNegY | otherCase;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  /*
  True IFF sign bit is 1
  Return x and a bitmask with signbit = 1 and everything else 0'd out
  */
  return ((x & (1 << 31)) >> 31) & 0x00000001;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
  /*
  Multiply x by 5 via leftshift by two and then adding it
  Then right shift by 3 to divide by 8
  Use the sign and a rounding number (& multByFive and 7, because 7 is 8 - 1)
  to make negative numbers round correctly
  */
 int multByFive = (x << 2) + x;
 int sign = x >> 31;
 int rounding = multByFive & (7);
 int divByEight = multByFive >> 3;
 return divByEight + ((sign) & (!!rounding));
 //return (((x << 2) + (x))) >> 3;
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  /*
  First, use >> 31 o tell whether or not x is negative
  Then, left shift x by 1 and right shift it by 1 to get the
  magnitude (if unsigned, you drop and add a 0, if signed, you drop a 0/add a 1)
  Create a mask that is the two's complement of the sign (1 if sign is OxFFFFFFFF),
  0 if sign is 0x00000000
  magnitude XOR this mask will either be identical to the original (if the original
  is positive) or will be the complement of the original, in which case
  adding sign will get you to the two's complement.
  */
  int sign = x >>31; 
  // int mag = x << 1 >> 1;
  // int mask = ~sign + 1;
  // int temp =  (mag ^ mask); 
  // return temp + sign;

  int correctSignedBits = sign << 31;
  //Gets rid of all bits except signed bits
  //Add 1 or 0 with sign & 1 as required to form two's complement
  return correctSignedBits + (x ^ sign) + (sign & 1);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  //Note: got help from here https://stackoverflow.com/questions/57968090/why-are-these-two-codes-giving-a-different-output-bits-c-float-i2f
  /*
  Strategy: First find the sign
  Then get the absolute value. minimum integer and 0 are special cases, so use if statements
  to deal with them.
  Find the exponent by moving the absolute value left until there's a 1 in the leftmost position
  While decrementing exponent from 158 (127 + 32 - 1)
  Use if statements to handle rounding to even; if the last 8 bits of the mantissa (which will be truncated)
  are more than 0x80, need to add 0x80 to round to even
  Then shift the mantissa/exponent into place, and or everything together to get the result
  */
  unsigned int sign = 0;
  unsigned int minimum = (0x01 << 31);
  unsigned int abs; //Absolute value of x
  unsigned int exponent = 158; //127 (float bias) + 31 (32 - 1)
  //First find the sign
  if (x == 0) { //Special case, floating point representation of 0 is just all 0s
    return 0;
  }
  else if (x == 0x80000000) { //Special Case; can't get the absolute value of this
    return 0xcf000000;
  }
  else if (x < 0) {
    x = -x;
    sign = 1;
  }
  abs = x;
  //Find the exponent by moving abs left until there's a 1 in the leftmost position
  //While decrementing exponent
  while ((abs & minimum) != minimum) {
    abs <<= 1;
    --exponent;
  }
  //For handling rounding to even
  if ((abs & 0xFF) > 0x80) {
    abs += 0x80;
  }
  else if ((abs & 0x1FF) == 0x180) {
    abs += 0x80;
  }
  //Place magnitude/mantissa where it needs to be
  if (abs & 0x80000000) {
    abs >>= 8;
    }
  else {
    exponent++;
    abs >>= 9;
  }
  //Remove the implicit 1 to get the mantissa down from 24 bits to 23 bits
  abs = abs & 0x7FFFFF;
  //Shift the exponent into place
  exponent <<= 23;
  return (sign << 31) | abs | exponent; //Or everything together to get the result
}
