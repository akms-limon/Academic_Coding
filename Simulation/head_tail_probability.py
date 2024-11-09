import random

def func(Number_of_test) :
    count_one = 0
    count_zero = 0
    for _ in range (Number_of_test) :
        x = random.randrange(0, 2)
        if x == 1 :
            count_one += 1
        else :
            count_zero += 1
        ans = count_one / (count_one + count_zero)
        print(ans)
    return ans

Number_of_test = 1000000
ans = func(Number_of_test)
print(ans)
