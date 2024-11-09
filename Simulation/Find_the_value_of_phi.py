import random

def estimate_pi(num_points):
    inside_circle = 0
    for _ in range(num_points):
        # Generate random x, y points between -1 and 1
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        
        # Check if the point is inside the unit circle
        if x**2 + y**2 <= 1:
            inside_circle += 1
    
    # Area ratio of circle to square is π/4, so π ≈ 4 * (inside_circle / num_points)
    pi_estimate = 4 * (inside_circle / num_points)
    return pi_estimate

# Test the function with a large number of points for higher accuracy
num_points = 100000
pi_value = estimate_pi(num_points)
print(f"Estimated value of π using Monte Carlo simulation: {pi_value}")
