def prime_check(n):
    for i in range(2, n):
        if n % i == 0:
            return 0
    return 1
print is_prime(91)