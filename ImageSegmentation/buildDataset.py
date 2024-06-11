from PIL import Image
import pandas as pd

# Load your image
img_path = "B.png"
im = Image.open(img_path).convert('RGB')


# Initialize a list to hold the RGB values
rgb_values = []

# Iterate over the specified pixel range and extract RGB values
for x in range(70, 200):
    for y in range(70, 200):
        r, g, b = im.getpixel((x, y))
        rgb_values.append((r, g, b))

# Convert the list to a DataFrame
rgb_df1 = pd.DataFrame(rgb_values, columns=['R', 'G', 'B'])

# Add a 'Label' column with the label 'white'
rgb_df1['label'] = 'white'

# Display the DataFrame
print(rgb_df1)


# Load your image
img_path = "D.png"
im = Image.open(img_path).convert('RGB')

# Initialize a list to hold the RGB values
rgb_values_orange = []

# Iterate over the specified pixel range and extract RGB values
for x in range(30, 236):
    for y in range(30, 236):
        r, g, b = im.getpixel((x, y))
        rgb_values_orange.append((r, g, b))

# Convert the list to a DataFrame
rgb_df2 = pd.DataFrame(rgb_values_orange, columns=['R', 'G', 'B'])

# Add a 'Label' column with the label 'white'
rgb_df2['label'] = 'orange'

# Display the DataFrame
print(rgb_df2)


# Load your image
img_path = "F.png"
im = Image.open(img_path).convert('RGB')

# Initialize a list to hold the RGB values
rgb_values_blue = []

# Iterate over the specified pixel range and extract RGB values
for x in range(30, 236):
    for y in range(30, 236):
        r, g, b = im.getpixel((x, y))
        rgb_values_blue.append((r, g, b))

# Convert the list to a DataFrame
rgb_df3 = pd.DataFrame(rgb_values_blue, columns=['R', 'G', 'B'])

# Add a 'Label' column with the label 'white'
rgb_df3['label'] = 'blue'

# Display the DataFrame
print(rgb_df3)






# Load your image
img_path = "F.png"
im = Image.open(img_path).convert('RGB')

# Initialize a list to hold the RGB values
rgb_values_yellow = []

# Iterate over the specified pixel range and extract RGB values
for x in range(540, 755):
    for y in range(300, 500):
        r, g, b = im.getpixel((x, y))
        rgb_values_yellow.append((r, g, b))

# Convert the list to a DataFrame
rgb_df4 = pd.DataFrame(rgb_values_yellow, columns=['R', 'G', 'B'])

# Add a 'Label' column with the label 'white'
rgb_df4['label'] = 'yellow'

# Display the DataFrame
print(rgb_df4)





# Load your image
img_path = "D.png"
im = Image.open(img_path).convert('RGB')

# Initialize a list to hold the RGB values
rgb_values_red = []

# Iterate over the specified pixel range and extract RGB values
for x in range(30, 230):
    for y in range(530, 730):
        r, g, b = im.getpixel((x, y))
        rgb_values_red.append((r, g, b))

# Convert the list to a DataFrame
rgb_df5 = pd.DataFrame(rgb_values_red, columns=['R', 'G', 'B'])

# Add a 'Label' column with the label 'white'
rgb_df5['label'] = 'red'

# Display the DataFrame
print(rgb_df5)


# Load your image
img_path = "D.png"
im = Image.open(img_path).convert('RGB')

# Initialize a list to hold the RGB values
rgb_values_green = []

# Iterate over the specified pixel range and extract RGB values
for x in range(535, 757):
    for y in range(33, 245):
        r, g, b = im.getpixel((x, y))
        rgb_values_green.append((r, g, b))

# Convert the list to a DataFrame
rgb_df6 = pd.DataFrame(rgb_values_green, columns=['R', 'G', 'B'])

# Add a 'Label' column with the label 'white'
rgb_df6['label'] = 'green'

# Display the DataFrame
print(rgb_df6)

merged_df = pd.concat([rgb_df1, rgb_df2, rgb_df3, rgb_df4, rgb_df5, rgb_df6], ignore_index=True)
print(merged_df)

merged_df.to_csv("merged_dataset.csv", index=False)