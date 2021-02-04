'''
Calculating Square root using bisection method.
Initially we guess x is the sqrt of a. 
If it's a wrong guess calculate average of x, a/x and check and so on

'''
#improve guess by checking correctness of guess and updating guess if needed
def improve(update,close,guess=1):
    while not close(guess):
        guess = update(guess)
    return guess
    
#calculate average
def average(x,y):
    return (x+y)/2

#calculate equality of  two  numbers with tolerance
def approx_eq(x,y,tol=1e-15):
    return abs(x-y)<tol

#main function for calculating square root
def sqrt(a):
    #how close is a with square of x
    def sqrt_close(x):
        return approx_eq(a,x*x)
    
    #update the guess by calculating average of x and a/x
    def sqrt_update(x):
        return average(x,a/x)

    return improve(sqrt_update,sqrt_close)

print(sqrt(16))

