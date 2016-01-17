// Tanya Lindermeier
//FILENAME: BigNum.cxx
// This is the implementation file of the BigNum class


#ifndef HW3_BIGNUM_CXX
#define HW3_BIGNUM_CXX
#include <algorithm>   // Provides copy function
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "BigNum.h"
using namespace std;

namespace HW3
{
	BigNum::BigNum()
	{
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned int[capacity]; 
		digits[0] = 0;
		positive = true;      
		used = 1;
	}    

	BigNum::BigNum(int num)
	{
		if (num == 0) 
		{
			digits = NULL;
			BigNum zero;
			*this = zero;
		}
    
		else 
		{
			if (num > 0) 
			{
				positive = true;
			}
			else 
			{
				positive = false;
				num = -num;
			}
      
			unsigned int i=0, temp = num;
      
			// count the digits
			while (temp > 0) 
			{
				temp = temp/10; 
				i++;
			}

			capacity = double_up_default(i); 
		
			digits = new unsigned int[capacity];

			temp = num;
		
			for (used=0; used < i; ++used) 
			{
				digits[used] = temp % 10;
				temp /= 10;
			}
		}
	}

	// Constructor that receives a character array, leading 0's will be ignored
	BigNum::BigNum(const char strin[])
	{
		digits = NULL;
		
		int len = strlen(strin);
		
		if (len == 0)
		{
			BigNum zero;
			*this = zero;
			return;
		}

		used = len;
		positive = true;
		
		int i = 0;

		if(strin[i] == '-')  
		{
			positive = false;
			i = 1;
			used--;
		}
		else if(strin[i] == '+')  
		{
			i = 1;
			used--;
		}
		
		capacity = double_up_default(used);
	
		digits = new unsigned int[capacity];

		for(unsigned int k = 0; k < used; ++k) 
		{
			digits[used - k - 1] = strin[i++] - '0';
		}
		
		trim();
	}
 
    BigNum::BigNum(const BigNum& anotherBigNum)
    {
		digits = NULL;
		*this = anotherBigNum;
    }

    BigNum::~BigNum()
    {
		delete [] digits;
    }
    
    // public function possibly useful in +, * routines
    unsigned int BigNum::get_digit(unsigned int index) const
    {
		assert(index < used);
		return digits[index];
    }

    // public function possibly useful in +, * routines
    void BigNum::set_digit(unsigned int digit, unsigned int index)
    {
		assert(index <= used);
		if (index == used)
		{
			if (used == capacity)
				resize(double_up_default(capacity+1));
			++used;
		}
		digits[index] = digit;
    }
    
    // public function possibly useful in +, * routines
    void BigNum::set_used(unsigned int new_used)
    {
		if (new_used >= capacity)
		{
			resize(new_used);
		}
		used = new_used;
    }

    // public function possibly useful in +, * routines
    unsigned int BigNum::get_used() const
    {
		return used;
    }

    // public function possibly useful in +, * routines
    unsigned int BigNum::get_capacity() const
    {
		return capacity;
    }
    
    bool BigNum::get_positive() const
    {
		return positive;
    }

    void BigNum::set_positive(bool pos_or_neg)
    {
		positive = pos_or_neg;
    }
	
	void BigNum::resize(unsigned int n)
	{
		unsigned int *largerArray;

		if (n < used) return; // Can't allocate less than we are using

		capacity = double_up_default(n);
		largerArray = new unsigned int[capacity];
		
		copy(digits, digits + used, largerArray);
		
		delete [] digits;
		digits = largerArray;
	}

	BigNum& BigNum::operator=(const BigNum& anotherBigNum)
	{
		if (this == &anotherBigNum)  return *this;
		
		if (digits != NULL)
			delete [] digits;
			
		capacity = anotherBigNum.capacity;
		digits = new unsigned int[capacity];
		
		positive = anotherBigNum.positive;
		used = anotherBigNum.used;
		copy(anotherBigNum.digits, anotherBigNum.digits + used, digits);
		return *this;
	}


  
  BigNum& BigNum::operator+=(const BigNum& addend)  
  {
		*this = *this + addend;
		return *this;	
		
  }


  BigNum& BigNum::operator-=(const BigNum& subtractand)
  {
	  *this = *this - subtractand;
	  return *this;
  }

  
  BigNum& BigNum::operator*=(const BigNum& multiplicand)
  {
	  *this = *this * multiplicand;
	  return *this;
  }

  
  BigNum& BigNum::operator/=(const BigNum& divisor)
  {
	  *this = *this / divisor;
	  return *this;
  }


  BigNum& BigNum::operator%=(const BigNum& divisor)
  {
	  *this = *this % divisor;
	  return *this;
  }


  BigNum& BigNum::operator++()
  {
	  BigNum tanya = 1;
	  *this += tanya;
	  return *this;
  }


  BigNum& BigNum::operator--()
  {
	  BigNum jeff = 1;
	  *this -= jeff;
	  return *this;
  }


  BigNum BigNum::diff(const BigNum& subtractand) const
  {
	  BigNum result;
	  result.resize(this->used);//sets size to n1 from operator-
	  
	  unsigned int i = 0;
	  unsigned int borrow = 0;
	  
	  result.used = 0;

	  for (i = 0; i < this->used; ++i)
	  {
		  result.digits[i] = this->digits[i];
		  if (i < subtractand.get_used())
		  {
			  if (result.digits[i] >= 1 + subtractand.get_digit(i))
			  {
				  result.digits[i] -= (borrow + subtractand.get_digit(i));
				  borrow = 0;
				  result.used++;
			  }
			  else
			  {
				  result.digits[i] = result.digits[i]+10 - borrow - subtractand.get_digit(i);	// add 10 first
				  borrow = 1;
				  result.used++;
			  }
		  }
			else
			 {
				if (result.digits[i] >= borrow)
				  {
					  result.digits[i] -= borrow;
					  borrow = 0;
					  result.used++;
				  }
				  else
				  {
					  result.digits[i] =result.digits[i]+ 10  - borrow;	// add 10 first
					  borrow = 1;
					  result.used++;
				  }
				  
			  } 
	  }
	  
	  // all borrowing should be done by this point
	  
	  result.trim();	
	  
	  return result;
  }
  

  BigNum BigNum::sum(const BigNum& addend) const
    {
	BigNum result;
	result.resize(this->used + 1); //n1's used from operator+
	unsigned int i = 0;
	unsigned int carry = 0;
	result.used = 0;
	for (i=0; i < this->used; ++i)
	{
		result.digits[i] = this->digits[i] + carry;
		if (i < addend.get_used())
		{
			result.digits[i] += addend.get_digit(i);
		}	
		if (result.digits[i] > 9)
		{
			result.digits[i] %= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result.used++;
	}				
	if (carry != 0)
	{
		result.digits[result.used] = carry;
		result.used += 1;
	}	
	return result;
  }

  BigNum BigNum::operator+(const BigNum& addend)
  {
	BigNum result;
	BigNum n1 = *this;
	n1.positive = true; //n1.set.positive(true);
	BigNum n2 = addend;
	n2.positive = true;//n2.set.positive(true);
	
	if (get_positive() == addend.get_positive())
	{
		if (n1 > n2)
		{
			result = n1.sum(n2); // n1 is *this for sum, n2 is addend
			if (result == 0)
			{
				result.positive = true;
			}
			else	
			{
				result.set_positive(get_positive());
			}
		}
		else
		{
			result = n2.sum(n1); // n1 is *this for sum, n2 is addend route n2 to sum
			if (result == 0)
			{
				result.positive = true;
			}
			else	
			{
				result.set_positive(get_positive());
			}
		}
	}
	else
	{
		
		
		if (n1 > n2)
		{
			result = n1.diff(n2);
			if (result == 0)
			{
				result.positive = true;
			}
			else	
			{
				result.set_positive(this->get_positive());
			}	
		}
		if (n2 > n1)
		{
			result = n2.diff(n1);
			if (result == 0)
			{
				result.positive = true;
			}
			else	
			{
				result.set_positive(addend.get_positive());
			}
		}
	}
	
	return result;
  }

  BigNum BigNum::operator-(const BigNum& subtractand)
	{
		BigNum result;
		BigNum n1 = *this;
		n1.positive = true;
		BigNum n2 = subtractand;
		n2.positive = true;
		
		if(n1 == 0 && n2 == 0)
		{
			result = 0;
			result.positive = true;
		}
	
		else{
		if (get_positive() != subtractand.get_positive())
		{
			if (n1 > n2)
			{
				result = n1.sum(n2);
				if (result == 0)
				{
					result.positive = true;
				}
				else	
				{
					result.set_positive(get_positive());
				}
			}
			else
			{
				result = n2.sum(n1);
				if (result == 0)
				{
					result.positive = true;
				}
				else	
				{
					result.set_positive(get_positive());
				}
			}
		}
		else
		{
			if(positive==true){
			if (n1 > n2)
			{
				result = n1.diff(n2); // n1 is *this for sum, n2 is addend
				if (result == 0)
				{
					result.positive = true;
				}	
				else	
				{
					result.set_positive(true);
				}
			}
			else
			{
				result = n2.diff(n1); // n1 is *this for sum, n2 is addend
				if (result == 0)
				{
					result.positive = true;
				}
				else	
				{
					result.set_positive(false);
				}
			}
		}
	
		else{
						if (n1 > n2)
			{
				result = n1.diff(n2); // n1 is *this for sum, n2 is addend
				if (result == 0)
				{
					result.positive = true;
				}	
				else	
				{
					result.set_positive(false);
				}
			}
			else
			{
				result = n2.diff(n1); // n1 is *this for sum, n2 is addend
				if (result == 0)
				{
					result.positive = true;
				}
				else	
				{
					result.set_positive(true);
				}
			}
			
	}	
	}
}	
				if(n1==n2 && positive==subtractand.positive){
					result=0;
					result.positive=true;
				}
		return result;
	}
      

  BigNum BigNum::operator*(const BigNum& multiplicand)
  {
	BigNum result;
	BigNum temp = 0;
	
	unsigned int carry = 0;
	unsigned int product = 0;
	unsigned int i;
	unsigned int j; 
	unsigned int k;
	
	for (i=0; i < get_used(); ++i)
	{
		for (k=0; k < i; ++k) //before entering this loop, previous loop loops once  so i becomes 1 and k is 0 and then this loop is initiated
		{
			temp.set_used(k+1);
			temp.set_digit(0,k); //add a zero for each step
		}
		carry = 0;
		for (j=0; j < multiplicand.get_used(); j++)
		{
			product = (get_digit(i) * multiplicand.get_digit(j)) + carry; //this.get_digit[i]	
			{
				if((i+j) == temp.get_used())
				{
					temp.set_used(i + j + 1);//         result?
				}
				temp.set_digit(product % 10, (i + j));
				carry = product / 10;
			}
		}
		while (carry > 0)
		{
			if ((k + j) == temp.get_used()) // >
			{
				temp.set_used(i + j+ 1);
			}
			temp.set_digit(carry % 10, (k + j));
			carry = carry / 10;
			++k;
		}
		result = result + temp;
	}	
	
	result.trim();
	if (positive == multiplicand.positive)
	{
		result.positive = true;
	}
	else
	{
		if (result == 0)
		{
			result.positive = true;
		}
		else	
		{
			result.positive = false;
		}
	}
					
	
	return result;
 }


  BigNum BigNum::operator/(const BigNum& divisor)
  {
	  BigNum result;
	  return result;
  }	
  
  
  BigNum BigNum::operator%(const BigNum& divisor)
  {
	BigNum result;
	//BigNum temp;
	
	//temp = divisor % 10;
	//result = temp;
	return result;
  }


  bool BigNum::operator>(const BigNum& anotherBigNum)
  {
    if(*this == anotherBigNum)  return false;

    if(positive == true && anotherBigNum.positive == false)  return true;
    else if(positive == false && anotherBigNum.positive == true)  return false;
    else {
      if(used > anotherBigNum.used) {
        if(positive == true)  return true;
	else  return false;
      }
      else if(used < anotherBigNum.used) {
        if(positive == true)  return false;
        else  return true;
      }
      else {
        for(unsigned int i=used-1; i>=0; i--) {
          if(digits[i] > anotherBigNum.digits[i])  {
            if(positive == true)  return true;
	    else  return false;
          }

          if(digits[i] < anotherBigNum.digits[i])  {
            if(positive == true)  return false;
            else  return true;
          }
        }
      }          
    }
  }


  bool BigNum::operator>=(const BigNum& anotherBigNum)
  {
    return ((*this > anotherBigNum) || (*this == anotherBigNum));
  }


  bool BigNum::operator<(const BigNum& anotherBigNum)
  {
    return !(*this >= anotherBigNum);
  }


  bool BigNum::operator<=(const BigNum& anotherBigNum)
  {
    return !(*this > anotherBigNum);
  }


  bool BigNum::operator==(const BigNum& anotherBigNum)
  {
//    if((positive == false) && (anotherBigNum.positive == false))  return true;  // Both BigNums are 0

    if((positive != anotherBigNum.positive) || (used != anotherBigNum.used))
      return false;

    for(unsigned int i=0; i<used; i++) {
      if(digits[i] != anotherBigNum.digits[i]) 
        return false;
    }

    return true;
  }


  bool BigNum::operator!=(const BigNum& anotherBigNum)
  {
    return !(*this == anotherBigNum);
  }


  std::ostream& operator<<(std::ostream &os, const BigNum& bignum)
  {
      unsigned int i = 0;
      unsigned int j = 0;

    if(bignum.positive == false)  cout << '-';

    for(i=0; i<bignum.get_used(); ++i) {
      cout << bignum.get_digit(bignum.get_used() - i - 1);
      if(j<60) ++j; 
      else {
	cout << endl;
	j = 0;
      }
    }
    
    return os;
  } 


  std::istream& operator>>(std::istream &is, BigNum& bignum)
  {
    string str;
    is >> str;
	BigNum temp = str.c_str();
	bignum = temp;
	return is;
  }
  
  	// compute closest doubling of DEFAULT_CAPACITY that will hold the number min
	unsigned int BigNum::double_up_default(unsigned int min)
	{
		unsigned int k = 1;
		while (k * DEFAULT_CAPACITY < min)
		{
			k *= 2;
		}
		return k * DEFAULT_CAPACITY; 
	}

	// trim leading zeros
	void BigNum::trim()
	{
		while (used > 1 && digits[used - 1] == 0)
			used--;
	}
	
		BigNum BigNum::factorial()
	{
	BigNum result = 1;
    return result;    
    }
	
	BigNum factorial(const BigNum& a)
	{
		BigNum result = 1;
		return result;
	}
}

#endif

