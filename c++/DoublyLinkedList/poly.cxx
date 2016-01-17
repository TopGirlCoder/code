#include "poly.h"


using namespace std;

namespace main_savitch_5
{
	polynomial::polynomial(double c, unsigned int exponent)
	{
		//cout << "***********  running default constructor  ***********" << endl;
		EPSILON = std::numeric_limits<double>::epsilon();
		head_ptr = new polynode(c,0);
		
		if (exponent == 0 || fabs(c) < EPSILON)
		{
			recent_ptr = head_ptr;
			tail_ptr = head_ptr;
			current_degree = 0;
		}
		
		else
		{
			head_ptr->set_coef(0);
			tail_ptr = new polynode(c, exponent, NULL, head_ptr);
			head_ptr->set_fore(tail_ptr);
			recent_ptr = tail_ptr;
			current_degree = tail_ptr->exponent();
		}
		//cout << "Tanya's polynomial is " << *this << endl;
    }

    polynomial& polynomial::operator=(const polynomial& source)
    {
		//cout << "***********  running my operator=  ***********" << endl;
		EPSILON = std::numeric_limits<double>::epsilon();
		if (this == &source) 
			return *this;
		if(head_ptr != NULL)
			clear();
		delete head_ptr;
		head_ptr = NULL;
		tail_ptr = NULL;
		recent_ptr = NULL;
		
		if (source.head_ptr != NULL)
		{
			head_ptr = new polynode(source.head_ptr->coef(), source.head_ptr->exponent());;
			tail_ptr = head_ptr;;
			recent_ptr = head_ptr;
			current_degree = 0;
			for(unsigned int exp = source.next_term(0); exp!=0; exp = source.next_term(exp))
				assign_coef(source.coefficient(exp), exp);
		}
		return *this;
	}
	
    polynomial::polynomial(const polynomial& source)
    {
		//cout << "***********  running my copy constructor  ***********" << endl;
		EPSILON = std::numeric_limits<double>::epsilon();
		head_ptr = new polynode();
		tail_ptr = head_ptr;
		recent_ptr = tail_ptr;
		current_degree = tail_ptr->exponent(); //was 0
		head_ptr->set_fore(NULL);
		head_ptr->set_back(NULL);
		polynode* sourceNode;
		
		for (sourceNode = source.head_ptr; sourceNode != NULL;
				sourceNode = sourceNode->fore())
		{
			assign_coef(sourceNode->coef(), sourceNode->exponent());
		}
		//~ head_ptr = NULL;
		//~ *this = source;
    }

    polynomial::~polynomial()
    {
		//cout << "***********  running ~  ***********" << endl;
		clear();
		delete head_ptr;
		head_ptr = NULL;
    }

    void polynomial::clear()
    // (Uses the delete operator to reclaim storage!)
    {
		//cout << "***********  running clear  ***********" << endl;
		polynode* handle; 
		while (head_ptr->fore()!=NULL)
		{
			handle = head_ptr->fore();
			delete head_ptr;
			head_ptr = handle;
		}
		head_ptr->set_coef(0.0);
		head_ptr->set_exponent(0);
		tail_ptr = head_ptr;
		recent_ptr = tail_ptr;
		current_degree = 0;
		head_ptr->set_fore(NULL);
		head_ptr->set_back(NULL);
    }
    
    double polynomial::coefficient(unsigned int exponent) const
    {
		//cout << "***********  running coefficient  ***********" << endl;
		set_recent(exponent); 
		if (recent_ptr->exponent() == exponent)
			return recent_ptr->coef();
		else
			return 0;
    }

    void polynomial::add_to_coef(double amount, unsigned int exponent)
    {
		//cout << "***********  running add_to_coef  ***********" << endl;
		set_recent(exponent);
		
		// if amount < 0, return
		if (fabs(amount) < EPSILON)
		{
			return;
		}
		// if the exponents are the same
		else if (recent_ptr->exponent() == exponent)
		{
			// add the coefficient and the amount
			recent_ptr->set_coef(recent_ptr->coef() + amount);	
			// if the new coefficient is 0
			if (fabs(recent_ptr->coef()) < EPSILON)
			{
				// if the 0 term is head_ptr, return
				if (head_ptr->exponent() == exponent)
				{
					current_degree = tail_ptr->exponent();
					return;
				}
				// if the 0 term is tail_ptr, delete the tail
				if (tail_ptr->exponent() == exponent)
				{
					tail_ptr = tail_ptr->back();
					recent_ptr = tail_ptr;
					delete tail_ptr->fore();
					tail_ptr->set_fore(NULL);
					current_degree = tail_ptr->exponent();
				}
				// if the 0 term is in the middle, delete the term
				else
				{
					polynode* tempNode = recent_ptr;
					recent_ptr = recent_ptr->back();
					recent_ptr->set_fore(tempNode->fore());
					tempNode->fore()->set_back(tempNode->back());
					current_degree = tail_ptr->exponent();
					delete tempNode;
				}	
			}
		}
		// else the recent_ptr->exponent() != exponent, create new node
		else
		{
			polynode* p = new polynode(amount, exponent);
			// if new term is between two existing nodes
			if (recent_ptr->exponent() < exponent && tail_ptr->exponent() > exponent)
			{
				recent_ptr->fore()->set_back(p);
				recent_ptr->set_fore(p);
				current_degree = tail_ptr->exponent();
				p->set_back(recent_ptr);
				recent_ptr = p;
			}	
			// else if exponent larger than tail_ptr exponent
			else 
			{
				recent_ptr->set_fore(p);
				tail_ptr = p;
				tail_ptr->set_fore(NULL);
				current_degree = tail_ptr->exponent();	
				p->set_back(recent_ptr);
				recent_ptr = p;	
			}
		}
	}

    void polynomial::assign_coef(double coefficient, unsigned int exponent)
	{
		//cout << "***********  running assign_coef  ***********" << endl;
		set_recent(exponent);
		if (fabs(coefficient) < EPSILON && exponent > current_degree)// 0x^3
		{
			return;
		}
		else if (recent_ptr->exponent() < exponent) // x^2 < x^3
		{
			polynode* tempNode = new polynode(coefficient, exponent, recent_ptr->fore(), recent_ptr); //good
			if (recent_ptr->fore() != NULL)
			{
				recent_ptr->fore()->set_back(tempNode);
				recent_ptr->set_fore(tempNode);
				current_degree = tail_ptr->exponent();
				recent_ptr = tempNode;
			}	
			else
			{
				recent_ptr->set_fore(tempNode);
				tail_ptr = tempNode;
				tail_ptr->set_fore(NULL);
				current_degree = tail_ptr->exponent();	
				recent_ptr = tempNode;
			}
		}
		else if (fabs(coefficient) > EPSILON || exponent == 0)
		{
			recent_ptr->set_coef(coefficient);
			if (exponent > current_degree)
			{
				current_degree = exponent;
			}
		}
		else if (exponent == current_degree)
		{
			tail_ptr = tail_ptr->back();
			recent_ptr = tail_ptr;
			delete tail_ptr->fore();
			tail_ptr->set_fore(NULL);
			current_degree = tail_ptr->exponent();
		}
		else 
		{
			if (exponent == recent_ptr->exponent())
			{
				polynode* tempNode = recent_ptr;
				recent_ptr = recent_ptr->back();
				recent_ptr->set_fore(tempNode->fore());
				tempNode->fore()->set_back(tempNode->back());
				delete tempNode;
			}
		}
	}
    unsigned int polynomial::next_term(unsigned int exponent) const
    {
		if (exponent >= current_degree)
		{
			return 0;
		}
		set_recent(exponent);
		if (recent_ptr->fore() == NULL)
		{
			return 0;
		}
		else 
		{
			return recent_ptr->fore()->exponent();
		}
    }

	unsigned int polynomial::previous_term(unsigned int exponent) const
    {
		if (exponent == 0)
			return UINT_MAX;
		do
		{
			if (exponent > degree())
				return degree();
			exponent--;
			if (coefficient(exponent) != 0.0)
			return exponent;
		} while(exponent>0);
	    
		return UINT_MAX;
	}

    void polynomial::set_recent(unsigned int exponent) const
    {
		if (exponent == 0)
			recent_ptr = head_ptr;
		else if (exponent >= current_degree)
			recent_ptr = tail_ptr;
		else if (exponent < recent_ptr->exponent())
		{
			while (recent_ptr->back() != NULL && exponent < recent_ptr->exponent())
				recent_ptr = recent_ptr->back();
		}				
		else 
		{
			while (recent_ptr->fore() != NULL && exponent > recent_ptr->exponent())
			recent_ptr = recent_ptr->fore();
			// I think we need to check this to not go past the thing we want
			if (recent_ptr->exponent() > exponent) 
				recent_ptr = recent_ptr->back();
		}
	}
    
	double polynomial::eval(double x) const
	{
		double total = 0;
		unsigned int i = 0;

		do
		{
			total += coefficient(i) * pow((long double)x, (int)i);
			i = next_term(i);
		} while(i!=0);

		return total;
	}

    polynomial polynomial::derivative() const
    {
		polynomial p_prime;
		unsigned int exp = next_term(0);
		do
		{
			p_prime.assign_coef(exp * coefficient(exp), exp-1);
			exp = next_term(exp);
		} while (exp !=0);

		return p_prime;
    }
    
    polynomial operator+(const polynomial& p1, const polynomial& p2)
    {
	    polynomial p = p1;
	    unsigned int i = 0;

	    do
	    {
			p.assign_coef(p.coefficient(i) + p2.coefficient(i), i);
			i = p2.next_term(i);
	    } while(i != 0);

	    return p;
	  }
    
    polynomial operator-(const polynomial& p1, const polynomial& p2)
	{
	    polynomial p = p1;
	    unsigned int i = 0;
	  
	    do
	    {
			p.assign_coef(p.coefficient(i) - p2.coefficient(i), i);
			i = p2.next_term(i);
	    }while(i!=0);
		
	    return p;
	}
    
    polynomial operator*(const polynomial& p1, const polynomial& p2)
	{
	    polynomial p;

	    unsigned int i = 0;  
	    unsigned int k =0;   

	    do
	    {
			do
			{
				p.assign_coef(p1.coefficient(i) * p2.coefficient(k) +
					 p.coefficient(i+k), i+k);
				k = p2.next_term(k);
		    
			}while (k!=0);
			i = p1.next_term(i);
		
	    }while(i != 0);

	    return p;
	}    
   
    ostream& operator << (ostream& out, const polynomial& p)
    {
		unsigned int exp = 0;
		do
		{
			out << p.coefficient(exp) << "x^" << exp;
			exp = p.next_term(exp);
			if (exp!=0) out<<" + ";
		} while (exp !=0);
		return out;
    }
    
    void polynomial::find_root(
	double& answer,
	bool& success,
	unsigned int& iterations,
	double guess,
	unsigned int maximum_iterations,
	double epsilon) const
    {
		success = false;
		
		for (iterations = 0; iterations < maximum_iterations && success == false; ++iterations)
		{
			double fx = eval(guess);
			double fx_prime = derivative().eval(guess);

			if (fabs(fx) < EPSILON)
			{
				success = true;
				answer = guess;
			}
			if (fabs(fx_prime) < EPSILON)
			{
				break;
			}
			if (iterations == maximum_iterations && !success)
			{
				answer = guess;
				success = false;
			}
			guess -= fx/fx_prime;
			answer = guess;
		}
		if (answer > EPSILON)
		{
				success = true;
				answer = guess;
		}
		
	}
}
