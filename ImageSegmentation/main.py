from PIL import Image
import joblib
import numpy as np

# Load the trained SVM model and scaler
svm_model = joblib.load('svm_model.pkl')
scaler = joblib.load('scaler.pkl')

def rgb_of_pixel(im, x, y):
    r, g, b = im.getpixel((x, y))
    return (r, g, b)

def average_rgb_in_circle(im, center_x, center_y, radius):
    rgb_values = []
    
    for x in range(center_x - radius, center_x + radius + 1):
        for y in range(center_y - radius, center_y + radius + 1):
            if (x - center_x) ** 2 + (y - center_y) ** 2 <= radius ** 2:
                rgb_values.append(rgb_of_pixel(im, x, y))
    
    # Calculate the average RGB values
    if rgb_values:
        avg_rgb = np.mean(rgb_values, axis=0)
        return avg_rgb
    else:
        return (0, 0, 0)  # Return black if no pixels are in the circle (shouldn't happen with valid input)


def get_center_coordinates(width, height):
    center_width = width // 2
    center_height = height // 2
    face_edge_distance = min(width, height) // 3
    
    centers = [
        (center_width - face_edge_distance, center_height - face_edge_distance),
        (center_width, center_height - face_edge_distance),
        (center_width + face_edge_distance, center_height - face_edge_distance),
        (center_width - face_edge_distance, center_height),
        (center_width, center_height),
        (center_width + face_edge_distance, center_height),
        (center_width - face_edge_distance, center_height + face_edge_distance),
        (center_width, center_height + face_edge_distance),
        (center_width + face_edge_distance, center_height + face_edge_distance)
    ]
    
    return centers

def classify_color(rgb):
    # Convert RGB to numpy array and scale it
    rgb_array = np.array([rgb])
    scaled_rgb = scaler.transform(rgb_array)
    
    # Predict using the SVM model
    predicted_label = svm_model.predict(scaled_rgb)
    return predicted_label[0]

# Example usage
import json
final = []
string_to_char = {
    "white": 'w',
    "green": 'g',
    "red": 'r',
    "blue": 'b',
    "yellow": 'y',
    "orange": 'o'
}

for i in range(6):
    img_path = "./Images/"+str(i) + ".jpeg"
    im = Image.open(img_path).convert('RGB')
    centers = get_center_coordinates(im.width, im.height)
    face_edge_distance = min(im.width, im.height) // 7
    colors = [classify_color(average_rgb_in_circle(im, x, y,face_edge_distance)) for x, y in centers]
    # Write cube data to a text file
    while(True):
        print(colors)
        print("is this correct?")
        flag = input()
        flag = flag.lower()
        if(flag=="yes"):
            break
        else:
            print("pls specify the position[0-8] and color of error")
            pos,col = input().split()
            pos = int(pos)
            colors[pos] = col
    ans = ""
    for color in colors:
        ans+=string_to_char[color]
    # ans += '$'
    final.append(ans)

with open("cube_data.txt", "w") as file:
    # Iterate through the list and write each element followed by a newline
    for element in final:
        file.write(element + "\n")
# print("Colors of Centers:", colors)

print("Cube data written to cube_data.txt")


import subprocess
# Run the C++ solver
result = subprocess.run(["../Solver.exe", "cube_data.txt"], capture_output=True, text=True)

# Check if the C++ solver ran successfully
if result.returncode == 0:
    print("C++ solver ran successfully.")
    print(result.stdout)
else:
    print("C++ solver encountered an error.")
    print(result.stderr)