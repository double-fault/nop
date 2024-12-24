import json
import matplotlib.pyplot as plt
from collections import defaultdict
import re

# Load the JSON file
with open('benchmarks.json', 'r') as file:
    data = json.load(file)

# Group the data by the base name
benchmarks = data['benchmarks']
grouped_data = defaultdict(list)

FREQ = 4.5

for benchmark in benchmarks:
    # Split into base name and number
    name_parts = benchmark['name'].split('/')
    base_name = name_parts[0] 
    divisor = 2**(int(name_parts[1]) + 10)

    adjusted_time = benchmark['real_time'] / divisor
    adjusted_time *= FREQ

    grouped_data[base_name].append(adjusted_time)  # Group main benchmark data

adjusted_data = {}

for name, real_times in grouped_data.items():
    adjusted_data[name] = real_times

# Plot the adjusted data
plt.figure(figsize=(10, 6))

for name, real_times in adjusted_data.items():
    x_values = range(10, 10 + len(real_times))
    plt.plot(
        x_values,
        real_times, 
        label=name, 
        marker='o',  # Add a marker for each point
        markersize=5  # Adjust marker size for visibility
    )

# Add labels, title, and legend
plt.xlabel('Number of nops (log base 2)')
plt.ylabel('Clock cycles per nop')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()

