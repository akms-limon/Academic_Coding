import random
import matplotlib.pyplot as plt

def find_phi(Number_of_points):
    points_in_circle = 0
    x_inside, y_inside = [], []
    x_outside, y_outside = [], [] 
    for _ in range (Number_of_points) :
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        if x ** 2 + y ** 2 <= 1:
            points_in_circle += 1
            x_inside.append(x)
            y_inside.append(y)
        else:
            x_outside.append(x)
            y_outside.append(y)
    estimated_pi = 4 * (points_in_circle / Number_of_points)

    plt.figure(figsize=(6, 6))
    plt.scatter(x_inside, y_inside, color='blue', s=1, label="Inside Circle")
    plt.scatter(x_outside, y_outside, color='red', s=1, label="Outside Circle")
    circle = plt.Circle((0, 0), 1, color='black', fill=False)

    plt.gca().add_patch(circle)
    plt.xlim(-1, 1)
    plt.ylim(-1, 1)
    plt.pause(.1)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.legend()
    plt.title(f"Monte Carlo Simulation to Estimate π\nEstimated π ≈ {pi_estimate}")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.show()
    return estimated_pi

Number_of_points = 100000
value_of_phi = find_phi(Number_of_points)
print("the value of phi is equal to :", value_of_phi)