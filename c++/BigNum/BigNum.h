// FILENAME: BigNum.h
// This is the definition of the BigNum class.

// CONSTRUCTORS and DESTRUCTORS for the BigNum class
//
//   BigNum() : Default constructor for the BigNum class. A positive BigNum with default value 0
//      is created after this constructor.
//
//   BigNum(int num) : A BigNum with the same value and sign as num is created after this function.
//
//   BigNum(const char string[]) : A BigNum with the corresponding interger value of string[] is
//      created after this function.
//
//   BigNum(const BigNum& anotherBigNum) : A BigNum with the corresponding interger value of string[] is
//      created after this function.
//
//   ~BigNum() : Dynamic memory allocated for the BigNum is released after this function.
//
// PUBLIC MEMBER FUNCTIONS of the BigNum class:
//
//    BigNum& operator=(const BigNum& anotherBigNum) : The BigNum has been assigned the same value
//       as anotherBigNum after this function is executed.
//
//    BigNum& operator+=(const BigNum& addend) : Addend has been added to this BigNum after this
//       function is executed.
//
//    BigNum& operator-=(const BigNum& subtractand) : Subtractand has been subtracted from this 
//       BigNum after this function is executed.
//
//    BigNum& operator*=(const BigNum& multiplicand) : This BigNum has been multiplied by multiplicand 
//       and the result is stored in this BigNum after this function  is executed.
//
//    BigNum& operator/=(const BigNum& divisor) : This BigNum has been divided by divisor and the
//       result has been stored in this BigNum after this function is executed.
//
//    BigNum& operator%=(const BigNum& divisor) : This BigNum has been taken modulus by divisor and 
//       the result has been stored in this BigNum after this function is executed.
//    
//    BigNum& operator++() : This BigNum has been incremented by 1 after this function is executed.
//
//    BigNum& operator--() : This BigNum has been decremented by 1 after this function is executed.
//
//    BigNum operator+(const BigNum& addend) : The result of the addition of this BigNum and addend
//       has been returned after this function is executed and neither this BigNum nor addend has been
//       changed.
//
//    BigNum operator-(const BigNum& subtractand) : This BigNum has been subtracted by subtractand and 
//       neither this BigNum nor subtractand has been changed and the result has been returned after 
//       this function is executed. 
//
//    BigNum operator*(const BigNum& multiplicand) : This BigNum has been multilpied by multiplicand and
//       neither this BigNum nor multiplicand has been changed and the result has been returned after 
//       this function is executed.
//
//    BigNum operator/(const BigNum& divisor) : This BigNum has been divided by divisor and neither this
//       BigNum nor divisor has been changed and the result has been returned after this function 
//       is executed.
//   
//    BigNum operator%(const BigNum& divisor) : This BigNum has been taken modulus by divisor and neither
//       this BigNum nor divisor has been changed and the result has been returned after this function
//       is executed.
//
//    bool operator>(const BigNum& anotherBigNum) : True will be returned if this BigNum is bigger than
//       anotherBigNum, otherwise false will be returned.
//
//    bool operator>=(const BigNum& anotherBigNum) : True will be returned if this BigNum is bigger than
//       or equal to anotherBigNum, otherwise false will be returned.
//
//    bool operator<(const BigNum& anotherBigNum) :  True will be returned if this BigNum is smaller than
//       anotherBigNum, otherwise false will be returned.
//
//    bool operator<=(const BigNum& anotherBigNum) :  True will be returned if this BigNum is smaller than
//       or equal to anotherBigNum, otherwise false will be returned.
//
//    bool operator==(const BigNum& anotherBigNum) :  True will be returned if this BigNum is equal to 
//       anotherBigNum, otherwise false will be returned.
//
//    bool operator!=(const BigNum& anotherBigNum) : True will be returned if this BigNum is not equal to
//       anotherBigNum, otherwise false will be returned.
//
//    BigNum factorial() : Factorial of this BigNum has been returned after this function is executed.
//
//    unsigned int get_used() const : Length of this BigNum has been returned after this function is executed.
//
//    unsigned int get_capacity() const : Size of the memory allocated for this BigNum has been returned after this 
//       function is executed.
//    
// Private MEMBER FUNCTIONS of the BigNum class:
//
//    void  resize(unsigned int n) : Size of the memory allocated for this BigNum has been changed to n
//      after this function is executed. If n is smaller than the length of this BigNum, this BigNum
//      will not be resized. The n value will be chosen for efficiency; resizing should generally double the
//      number's capacity.
//           
//    BigNum  diff(const BigNum& subtractand) : Precondition is that both this BigNum 
//      and subtractand are positive, and also that this BigNum >= subtractand. The result of subtraction
//      has been returned after this function is executed.
//
//    BigNum sum(const BigNum& addend) :  Precondition is that both this BigNum
//      and addend are positive. The result of addition has been returned after this function is executed.
//
//  FRIEND FUNCTIONS of the BigNum class:
//    friend std::ostream& operator<<(std::ostream &os, const BigNum& bignum) : This bignum has been
//      output to the console after this function is executed.
//
//    friend std::istream& operator>>(std::istream &is, BigNum& bignum) : This BigNum entered from the
//      console has been stored in bignum after this function is executed.
//



#ifndef HW3_BIGNUM_H
#define HW3_BIGNUM_H
#include <cstdlib>  // Provides unsigned int
#include <iostream> // Provides istream and ostream

namespace HW3
{
    class BigNum 
    {
    public:
	
	// CONSTRUCTORS and DESTRUCTORS
	BigNum();                            
	BigNum(int num);                         
	BigNum(const char strin[]);
	BigNum(const BigNum& anotherBigNum);  
	~BigNum();
	
	
	// MEMBER FUNCTIONS
	unsigned int get_digit(unsigned int index) const;
	unsigned int get_used() const;
	unsigned int get_capacity() const;
	bool get_positive() const;
	
	BigNum& operator=(const BigNum& anotherBigNum);
	BigNum& operator+=(const BigNum& addend);
	BigNum& operator-=(const BigNum& subtractand);
	BigNum& operator*=(const BigNum& multiplicand);
	BigNum& operator/=(const BigNum& divisor);
	BigNum& operator%=(const BigNum& divisor);
	BigNum& operator++();  // overload prefix increment
	BigNum& operator--();  // overload prefix decrement
	
	
	BigNum operator+(const BigNum& addend);
	BigNum operator-(const BigNum& subtractand);
	BigNum operator*(const BigNum& multiplicand);
	BigNum operator/(const BigNum& divisor);
	BigNum operator%(const BigNum& divisor);
	bool operator>(const BigNum& anotherBigNum);
	bool operator>=(const BigNum& anotherBigNum);
	bool operator<(const BigNum& anotherBigNum);
	bool operator<=(const BigNum& anotherBigNum);
	bool operator==(const BigNum& anotherBigNum);
	bool operator!=(const BigNum& anotherBigNum);
	BigNum factorial();

	// small method used in testing
	char* printBigNum(){
	    int i = 0;
	    int offset = 0;
	    char* result; 
	    if (!(positive)){
		result = new char[used + 2];
		result[0] = '-';
		offset = 1;
	    }else{
		result = new char[used + 1];
	    }
	    for (i = used - 1; i >= 0 ; --i)
	    {
		result[used - 1 - i + offset] = digits[i] + 48;
	    }
	    result[used + offset] = '\0';
	    return result;
	}

	// FRIEND FUNCTIONS
	friend std::ostream& operator<<(std::ostream& os, const BigNum& bignum);
	friend std::istream& operator>>(std::istream& is, BigNum& bignum);
  private:
	unsigned int *digits;         // Pointer to the array of BigNum digits 
	bool positive;          // Indicates the sign of BigNum (true for positive, false for negative)
	unsigned int used;            // Length of the array for BigNum Digits  
	unsigned int capacity;        // Size of the memory allocated for tis BigNum 

	void set_positive(bool pos_or_neg);
	void set_digit(unsigned int digit, unsigned int index);
	void set_used(unsigned int new_used);
	void resize(unsigned int n);  
	BigNum diff(const BigNum& subtractand) const;
	BigNum sum(const BigNum& addend) const;
	void trim();
	unsigned int double_up_default(unsigned int min);
	static const unsigned int DEFAULT_CAPACITY = 20;
    };
}

#endif

