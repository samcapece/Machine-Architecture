/*
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this part of the project by
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
3. Has unpredictable behavior when shifting if the shift amount
is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the spec) to
check the legality of your solutions.
2. Each function has a maximum number of operations (integer, logical,
or comparison) that you are allowed to use for your implementation
of the function.  The max operator count is checked by dlc.
Note that assignment ('=') is not counted; you may use as many of
these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest checker to verify that your solutions produce
 *      the correct answers.
 */
#endif


/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) { 
    //gets 0xffffffff or -1 using complement 
    int m = 0;
    m = ~m;

    return m;
}

/*
 * thirdBits - return int with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) { 
    //73 is biggest int I can use that gives me every 3rd bit, by shifting this left a few times and combining we get a full 32 bit int of every 3rd bit
    int a = 73;
    int b = a << 9;
    int c = b << 9;
    int d = c << 9; //creates 3 ints copied of each other shifted right by 9 each
    
    a = a | b;
    a = a | c;
    a = a | d; //combines a and all three of the ints previously created

    return a;
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) { 
    /*  Our goal is to get two ints with bytes that have all 1's in the nth and mth bytes respectively.
        By shifting m and n to the left by three we get ints that we can use to shift y (or one byte of 1s) to their respective positions.
        Once we have our two seperate y's we combine them and get the complement, then we can get an int with zeroes for the two bytes
        we want to swap, and we can fill them in with the bytes we seperated shifted back by the opposite m/n. */
    int y = 0xFF;
    int ny; int my; int by; int z; int az;
    int xy = x;
    
    n = n << 3;
    m = m << 3;     //gets n and m to the amount we need to shift y by
    ny = y << n;
    my = y << m;    //y gets shifted by n and m
    z = ny | my;
    az = ~z;        //create a variable that gets all the other bytes besides the ones shifted
    ny = ny & x;    // seperates n from x
    my = my & x;    //seperates m from x
    ny = ny >> n; 
    my = my >> m;   //shifts n and m to first 2 bytes
    ny = ny & y;
    my = my & y;    //gets rid of any extra bits
    ny = ny << m;
    my = my << n;   //changes the positions of m and n
    by = my | ny;   //variable that holds both
    xy = xy & az;   //combines x and variable with 0'd out n and m
    x = xy | by;    //combines xy with new m and n positions

    return x;
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    /*we use the & operator to get a bit that is the same as the least significant bit, then by getting 0xFFFFFFFF
    and adding it to the bit we created we either get the 0xFF.. int or 0, we get the XOR of y in order to have this
    be the opposite since 1 gives us 0 and 0 gives us 1.*/
    int o = 1;
    int z = 0;
    int y = x&o;    //gets the least significant bit
    
    y = y^o;        //gets the opposite of the least significant bit
    z = ~z;         //gets the hex of all 1s
    y = y + z;      //adds y and z giving us all 0s or all 1s

    return y;
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x) {
    /* We first get an int holding !x which tells us if x is zero or not. Then we check if x is negative by comparing its
    sign bit with the negative sign bit 0x800000000, we use the & operator to compare these integers getting us either
    1 or 0 */
    int az;
    int z = 0x8;
    int y = !x; 

    y = y^1;    //sets y to opposite of !x
    z = z<<28;  //shits 0x8 so it is at the sign bit
    x = x^z;    //gets the opposite of the sign bit
    az = x>>31; //shifts to front
    az = az&1;  //clears all other bits
    az = az&y;  //checks in case 0 is inputted (otherwise 0 would count as positive)

    return az;
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    /* We start by getting values that we can compare uf to to check if its not a number. The if statement checks this by seeing
    if ufs exponent is above our nan value. Then we just add 1 to the sign value getting us the bit-level representation of the 
    float */
    int check = ~(1<<31);
    int nan = (0x7f << 24) + (0x8 << 20) + (0x1);
    unsigned bf;

    if((uf & check) >= nan) {   // if uf is nan it will be equal to or larger than 0x7f100000
        return uf;

    } else {
        bf = uf + (1<<31);      //adding 1 to the sign value gives us the bit level representation
        return bf;  

    }
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in input set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
    /* We create an int with all even numbers set to one and then we compare this to x. We then use the !
    operator to check if there are any even numbers as if there are x will be above 0. Then we XOR x compared
    to 1 to get 1 if it has even numbered bits and 0 if it doesn't. */
    int e = 0x55;   //01010101
    int xr;

    e = e | e<<8;
    e = e | e<<16;  //gets a full int of e
    xr = x&e;       //finds if any values match the even bits
    xr = !xr;       //if not 0, then at least 1 number even
    xr = xr^1;      //gets opposite for correct output

    return xr;
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /* We create upper and lower bounds and change the last bit in our upperbound so the overflow works how we want it to. Then we get the complement of both of these values.
    We then add x to our upper and lowerbound, I had to add 1 to the lowerbound or else 0x30 wouldn't work. If our x int is in the bounds then the upper 
    and lower variables will be positive and have 0 for their sign bit, otherwise it will be negative, so if we check the sign bit we can tell if the
    int is an ASCII digit. */
    int u = 0x39;
    int l = 0x30;
    int xr;

    u = u | 1 << 31;    //set sign bit to 1 in upper for overflow
    u = ~u;             
    l = ~l;             //gets complements of upper and lower bound
    u = u + x;
    l = l + x + 1;      //stops -0 from happening
    u = u & 1 << 31;
    l = l & 1 << 31;
    u = u >> 31;
    l = l >> 31;        //seperates sign bit from int
    xr = l | u;         //if either is 1 xr will be 1

    return !xr;         //return !xr for output reasons
}

/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    /* We start by getting the sign values for both of our variables. Then we check for NAN like we did previously for both usngigned variables.
    Then we check for +0 or -0. Then we have a series of if statements that check for each scenario and compares the numbers according to their
    sign values, and if they are the same we have a check for whether its positive or negative so we can appropriately compare the variables. */
    int sf = uf >> 31;
    int sg = ug >> 31;  //grab sign values
    int check = ~(1<<31);
    int nan = (0x7f << 24) + (0x8 << 20);

    if ((uf & check) > nan || (ug & check) > nan) {
        return 0;
    }   //previously used nan check

    if((uf | ug) == 0 || (uf | ug) == 1<<31) {
        return 0;
    }   //check for +0 and -0

    if (sf > sg) {  //if the sign of f is negative and sign of g is positive, then f<g is true
        return 1;
    } else if ((sg == sf) && (((ug < uf) && ((sg | sf) == 1)) || ((uf < ug) && ((sg | sf) == 0)))) {
        return 1;   //(first checks that the sign values are equal) and ((if negative and g is less than f, than g would be greater than f) or (if positive and g is greater than f)
    } else {        //since first 3 statements cover all bases our else can just return 0
        return 0;
    }

}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    /* Our goal is to get two integers where we can compare them using the & operator to get our answer.
    If we want to shift 1 bit to the right ie: 0100 0000, our two variables would be 1110 0000 and 0011 1111. Using
    the & operator on these variables gives our answer: 0010 0000. We accomplish this by shifting x by n, and then
    creating an int of 1's shifted to the left by 32 - n (in this case 32 + ~n) and then 1 extra. Then we use the & operator. */
    int s = x >> n;             // original shift right
    int y;
    y = ~0;                     //get int of all 1s
    y = y << (32 + ~n) << 1;    //shift y to the right by 32 - n then 1 extra for correct value
    y = ~y;
    s = s & y;                  //combine to get answer
    return s;
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x) {
    /* Our goal is to create a bit with all 1's after the most significant bit. For example if given 0100 0000,
    our goal is to get 0111 1111. We accomplish by using the or operator and shifting x over until all possible after 
    the most significant bit will be 1. Then comparing it to its complement shifted right one xor'd by the sign bit 
    (in case it is the most significant bit) */
    int xr;

    xr = x | x >> 1;
    xr = xr | xr >> 2;
    xr = xr | xr >> 4;
    xr = xr | xr >> 8;
    xr = xr | xr >> 16; //we don't need to shift by 1 31 times because we know there will be at least 2 1s then 4 then 8 etc
    xr = xr & ((~xr >> 1) ^ (1 << 31)); //complement of xr shifted right 1 will have 1s in the greatest bit position and to the left and 0s elsewhere
    return xr;                          //we xor with 1<<31 because if the greatest bit is the last bit then xr will be 0 (otherwise it is always 1)
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf) {
    /* for reference: sign -> 31st bit, exponent -> 30th through 23rd bit, -> fraction 22nd through 0 bit
       our goal is to seperate the sign and the exponent of uf and check three things: 1. does uf have a
       undefinable exponent (NAN) 2. does uf have a real exponent (NAN > exponent > 0) 3. does uf have no exponent
       if uf's exponent is nan we return uf, if it is real we can subtract uf's exponent by 1 to get 0.5*f, if it is 0 then
       we have to make sure uf is even and then subtract its exponent */
    
    int check = ~(1<<31);
    int nan = (0x7f << 24) + (0x8 << 20);
    //int sf = uf & 1<<31;
    int ef = uf & nan;
    int odd = !(uf & 3);


    if (uf == 0 || uf == 1<<31){
        return uf;

    } else if ((uf & check) > nan) { //nan
        return uf;

    } else if (ef > 1) { //exponent greater than 1
        uf = ef | ((uf^ef) >> 1);

    } else if (ef <= 1) { //exponent 0
        uf = uf + odd;
        uf = ef | ((uf^ef) >> 1);

    }
    
    return uf;  //doesn't work, didn't finish in time
}
