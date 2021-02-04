'''
This is a program to calculate the golden ration(phi) that is near to 1.6 and 
appears frequently in nature, art and architecture.

One property of golden ratio is that it can be calculated by repeatedly summinig
the inverse of any positive number with 1. Also it is one less than it's square.

'''
#this function updates the guess variale
def guess_update(guess):
    guess = 1/guess + 1
    return guess

#this function checks if two numbers are equal with certain tolerance
def approx_equal(x,y,tol=1e-15):
    return abs(x-y) < tol

#this function check the second property of phi. i.e if guess is one less than
#it's square
def close_to_square(guess):
    return approx_equal(guess*guess, guess+1)

#main function to improve the guess
#first default guess of 1
def improve(update,close,guess=1):
    while not close(guess):
        guess = update(guess)
    return guess

print(improve(guess_update,close_to_square))



