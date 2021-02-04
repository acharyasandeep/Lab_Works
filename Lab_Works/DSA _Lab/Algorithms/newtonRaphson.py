'''
calculating square root using newton raphson method.

    f(x)=x^2-a(given number)
    f'(x)=2x

we make a guess x then update the guess if f(x)!=0
update logic:
    x=x-f(x)/f'(x)

'''

def improve(update, close, guess = 1):
    while not close(guess):
        guess = update(guess)

    return guess
#basically x is guess here
def approx_eq(x,y,tol=1e-15):
    return abs(x-y)<tol

def newton_update(f,df):
    def update(x):
        return x - f(x)/df(x)
    return update

def find_zero(f,df):
    def close_zero(x):
        return approx_eq(f(x),0)

    return improve(newton_update(f,df),close_zero)



def square_root_newton(a):
    def f(x):
        return x*x - a
    def df(x):
        return 2*x 
    return find_zero(f,df)



print(square_root_newton(256))
