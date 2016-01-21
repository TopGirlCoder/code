
def fibonacci_iterative(n)
	first = 1 
	second = 1
	counter = n - 2	

	# check base cases
	return 0 if n == 0
	return 1 if n < 3 	  

	# iterate to find the solution
	counter.times do
		# the solution is the last two numbers summed to get the final number
		# here we sum numbers, move to the next numbers to sum, until we get 
		# to the last two numbers to sum. We sum them and return them as the 
		# final number. 
		third = first + second  # the next time we have new third = second + third and so on.
		first = second
		second = third
	end	
	second				
end

def fibonacci_recursive(n)
	# check base case
	return 0 if n == 0	

	# recurse to find solution
	n < 3 ? 1 : fibonacci_iterative(n-1) + fibonacci_iterative(n-2)
	
end
