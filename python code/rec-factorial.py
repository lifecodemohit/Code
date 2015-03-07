def factorial(number):
    if number <= 1 :
        return 1
    else:
        return number*factorial(number - 1)
user_input =input("Enter a number for factorial:")
factorial_of_input = factorial(user_input)
print factorial_of_input