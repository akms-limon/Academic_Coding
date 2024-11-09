import random

def find_phi(Number_of_points):
    points_in_circle = 0
    for _ in range (Number_of_points) :
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        if x ** 2 + y ** 2 <= 1:
            points_in_circle += 1
    estimated_pi = 4 * (points_in_circle / Number_of_points)
    return estimated_pi

Number_of_points = 100000
value_of_phi = find_phi(Number_of_points)

print("the value of phi is equal to :", value_of_phi)
