def factorial(number):
    product = 1
    for i in range(number):
        product  = product * ( i + 1 )
    return product
user_input = input("Find factorial of:")
factorial_of_input = factorial(user_input)
print factorial_of_input