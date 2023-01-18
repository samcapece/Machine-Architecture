# Read the following instructions carefully
# You will complete your solution to the bitwise portion of the project by
# editing the collection of functions in this source file.
#
# Some rules from Project 2 are still in effect for your assembly code here:
#  1. No global variables are allowed
#  2. You may not define or call any additional functions in this file.
#  3. You may not use any floating-point assembly operations.
#
# You may assume that your machine:
#  1. Uses two's complement, 32-bit representations of integers

# Use the 'btest_driver' program to check your functions for correctness

.text

# minusOne - return a value of -1
#   Rating: 1
.global minusOne
minusOne:       
    movl    $0, %eax       #moves 0 to eax
    notl    %eax           #not operator
    ret

# thirdBits - return int with every third bit (starting from the LSB) set to 1
#   Rating: 1
.global thirdBits
thirdBits:
    movl    $0x49249249, %eax     
    ret

# byteSwap - swaps the nth byte and the mth byte
#  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
#            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
#  You may assume that 0 <= n <= 3, 0 <= m <= 3
#  Rating: 2
.global byteSwap
byteSwap:
    movl    %edi, %r8d      #x
    movl    %esi, %r9d      #n
    movl    %edx, %r10d     #m
    movl    $0, %eax        #return variable  
    shll    $3, %r9d        #shifts n left by 3
    shll    $3, %r10d       #shifts m left by 3

    movl    %r8d, %r11d   
    movl    %r8d, %edx
    movl    %r9d, %ecx      #moves variables to keep safe
    sarl    %rcx, %r11d      #shifts x right by n
    movl    %r10d, %ecx     #moves m to shift registry
    sarl    %ecx, %edx      #shifts x right by m
    xorl    %edx, %r11d      #xors both shifted x's
    andl    $255, %r11d

    movl    %r8d, %eax      
    movl    %r9d, %ecx      
    movl    %r11d, %edx      #stores variables into temp registers
    shll    %ecx, %edx      #shifts y left by n
    movl    %r10d, %ecx     #moves m into shift register
    shll    %ecx, %r11d      #shifts y left by m
    xorl    %edx, %eax
    xorl    %r11d, %eax      #xors x by shifted y's, x is in return registry  

    ret

# copyLSB - set all bits of result to least significant bit of x
#   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
#   Rating: 2
#/
.global copyLSB
copyLSB:
    movl    %edi, %r8d
    andl    $1, %r8d
    xorl    $1, %r8d    #moves x to r8d, then xors and ands it by 1
    movl    $0, %r11d    
    notl    %r11d        #gets hex of all 1's
    addl    %r11d, %r8d  #adds to x
    movl    %r8d, %eax  #moves x to return register
    ret

# isPositive - return 1 if x > 0, return 0 otherwise
#   Example: isPositive(-1) = 0.
#   Rating: 2
.global isPositive
isPositive:
    movl    %edi, %eax          
    movl    %eax, %r11d          #gets copy of x
    cmpl    $0, %r11d            #compares it with 0
    sete    %al
    movzbl  %al, %r11d           #gets logical complement and sets it to r11d
    xorl    $1, %r11d            #gets opposite of complement
    xorl    $0x80000000, %eax   #gets opposite of sign value
    sarl    $31, %eax           
    andl    $1, %eax            #shifts sign value to front and clears rest of bits
    andl    %r11d, %eax          #checks if zero
    ret

# floatNegate - Return bit-level equivalent of expression -f for
#   floating point argument f.
#   Both the argument and result are passed as unsigned int's, but
#   they are to be interpreted as the bit-level representations of
#   single-precision floating point values.
#   When argument is NaN, return argument.
#   Rating: 2
.global floatNegate
floatNegate:
    movl    %edi, %r8d          #uf
    movl    $0x7FFFFFFF, %r11d   #check
    movl    $0x7F800001, %ecx   #nan
    
    andl    %r8d, %r11d          #and operator for uf and check
    cmpl    %ecx, %r11d          #compares uf and check to nan
    jb      .L2fn                 #checks compare
    movl    %r8d, %eax          #return uf if uf and check are greater or equal to nan
    jmp     .L3fn

    .L2fn:
    addl    $0x80000000, %r8d   #else add 1<<31 to uf and return
    movl    %r8d, %eax

    .L3fn:
    ret

# anyEvenBit - return 1 if any even-numbered bit in input set to 1
#   where bits are numbered from 0 (least significant) to 31 (most significant)
#   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
#   Rating: 2
.global anyEvenBit
anyEvenBit:
    movl    %edi, %eax
    andl    $0x55555555, %eax   #ands the even bit hex with x
    cmpl    $0, %eax            #gets logical complement of eax
    sete    %al
    movzbl  %al, %eax           #moves logical complement to eax
    xorl    $1, %eax            #xors logical complement
    ret

# isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
#   Example: isAsciiDigit(0x35) = 1.
#            isAsciiDigit(0x3a) = 0.
#            isAsciiDigit(0x05) = 0.
#   Rating: 3
.global isAsciiDigit
isAsciiDigit:
    movl    %edi, %eax
    movl    $0x80000000, %r11d
    movl    %r11d, %r8d
    orl     $0x39, %r8d         
    notl    %r8d                #upperbound
    movl    $0x30, %r9d
    notl    %r9d                #lowerbound

    addl    %eax, %r8d          #adds x to upperbound
    sarl    $31, %r8d           #shifts it right by 31
    andl    %r11d, %r8d          #ands it with 1<<31

    addl    %eax, %r9d
    addl    $1, %r9d
    sarl    $31, %r9d
    andl    %r11d, %r9d          #same done to lowerbound
    
    orl     %r8d, %r9d          #ors upper and lower bound
    cmpl    $0, %r9d
    sete    %al                 
    movzbl  %al, %eax           #returns logical complement

    ret

# floatIsLess - Compute f < g for floating point arguments f and g.
#   Both the arguments are passed as unsigned int's, but
#   they are to be interpreted as the bit-level representations of
#   single-precision floating point values.
#   If either argument is NaN, return 0.
#   +0 and -0 are considered equal.
#   Rating: 3
.global floatIsLess
floatIsLess:
    movl    %edi, %eax
    movl    %esi, %edx
    movl    %eax, %r8d
    movl    %edx, %r9d
    sarl    $31, %r8d               #sf
    sarl    $31, %r9d               #sg
    andl    $1, %r8d
    andl    $1, %r9d

    andl    $0x7FFFFFFF, %eax
    cmpl    $0x7F800000, %eax
    ja      .L2    
    andl    $0x7FFFFFFF, %edx
    cmpl    $0x7F800000, %edx
    jbe     .L3                     #checks if uf or ug are nan
    
    .L2:
    movl    $0, %eax
    jmp     .L4                     #if uf or ug is nan returns 0

    .L3:                            #continues if not nan
    movl    %edi, %eax
    movl    %esi, %edx
    orl     %edx, %eax
    cmpl    $0, %eax                
    je      .L5                     
    cmpl    $0x80000000, %eax
    jne     .L6                     #checks if uf and ug are both 0

    .L5:                            #if both 0 return 0
    movl    $0, %eax
    jmp .L4

    .L6:                            #if not both 0 continue
    cmpl    %r9d, %r8d
    jle     .L7
    movl    $1, %eax
    jmp     .L4                     #if uf is less than ug return 1

    .L7:                            #if uf not less than ug continue 
    cmpl    %r8d, %r9d
    jne     .L8                     #if uf and ug are not equal return 0
    movl    %edi, %eax
    movl    %esi, %edx
    cmpl    %eax, %edx
    jnb     .L9                     #if ug is greater than uf the first or case is false continue to second
    movl    %r9d, %r10d
    orl     %r8d, %r10d
    cmpl    $1, %r10d
    je      .L10                    #since ug is less than uf and both signs are negative return 1

    .L9:
    cmpl    %edx, %eax
    jnb     .L8                     #if uf is greater than ug return 0
    movl    %r9d, %r10d
    orl     %r8d, %r10d
    cmpl    $0, %r10d
    jne     .L8                     #if ug is greater than uf and both signs are positive return 0

    .L10:                           #uf is greater than ug
    movl    $1, %eax
    jmp     .L4

    .L8:                            #uf is not greater than ug
    movl    $0, %eax

    .L4:   
    ret


# logicalShift - shift x to the right by n, using a logical shift
#   Can assume that 0 <= n <= 31
#   Examples: logicalShift(0x87654321,4) = 0x08765432
#   Rating: 3
.global logicalShift
logicalShift:
    movl    %edi, %eax
    movl    %esi, %ecx
    sarl    %ecx, %eax          #shifts x right by n
    movl    $0xFFFFFFFF, %edx
    movl    $31, %r8d
    subl    %ecx, %r8d          #subtracts 31 by n
    movl    %r8d, %ecx
    shll    %ecx, %edx          #shifts our F hex left by r8d
    shll    $1, %edx            #shifts f hex 1 more
    notl    %edx                #gets complement of shifted f hex
    andl    %edx, %eax          #ands f hex with shifted x
    ret

# greatestBitPos - return a mask that marks the position of the
#               most significant 1 bit. If x == 0, return 0
#   Example: greatestBitPos(96) = 0x40
#   Rating: 4
.global greatestBitPos
greatestBitPos:
    movl    %edi, %eax
    movl    %eax, %edx
    sarl    $1, %edx
    orl     %edx, %eax
    movl    %eax, %edx
    sarl    $2, %edx
    orl     %edx, %eax
    movl    %eax, %edx
    sarl    $4, %edx
    orl     %edx, %eax
    movl    %eax, %edx
    sarl    $8, %edx
    orl     %edx, %eax
    movl    %eax, %edx
    sarl    $16, %edx
    orl     %edx, %eax          #shifts x to the right and ors with x 5 times
    movl    %eax, %edx          #creates 2nd x
    notl    %edx                #gets complement of x
    sarl    $1, %edx            #shifts complement right by 1
    xorl    $0x80000000, %edx   #xors complement by -0
    andl    %edx, %eax          #ands first and second x's
    ret
