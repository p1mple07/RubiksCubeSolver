# Rubik's Cube Solver

This project uses computer vision to recognize the colors of a Rubik's Cube from images and then calculates the steps to solve it.

## How it works

The project has two main parts:

1.  **Image Segmentation**: A Python script using `Pillow` and `scikit-learn` identifies the colors of the cube's faces from six different images. It uses a trained Support Vector Machine (SVM) model to classify the colors. The recognized color data is then saved to a `cube_data.txt` file.

2.  **Solver**: A C++ program reads the `cube_data.txt` file and uses a solving algorithm to find the sequence of moves to solve the cube. The final solution is printed to the console.

## Getting Started

### Prerequisites

* Python 3
* C++ compiler
* Pillow, joblib, and numpy libraries for Python

### Installation

1.  Clone the repository:
    ```bash
    git clone [https://github.com/j-uday-8207/rubikscubesolver.git](https://github.com/j-uday-8207/rubikscubesolver.git)
    ```
2.  Install the required Python libraries:
    ```bash
    pip install -r requirements.txt
    ```
3.  Compile the C++ solver:
    ```bash
    g++ -o Solver Solver.cpp
    ```

### Usage

1.  Place the six images of the Rubik's Cube faces (named `0.jpeg` to `5.jpeg`) in the `ImageSegmentation/Images` directory.

2.  Run the Python script to process the images:
    ```bash
    python ImageSegmentation/main.py
    ```
    The script will display the recognized colors and ask for confirmation. If there are any errors, you can correct them manually.

3.  The script will then automatically run the C++ solver with the `cube_data.txt` file. The solution will be printed to the console.

## Files

* `Solver.cpp`: The main C++ file that solves the Rubik's Cube.
* `ImageSegmentation/main.py`: The Python script for image processing and color recognition.
* `ImageSegmentation/svm_model.pkl`: The trained SVM model for color classification.
* `ImageSegmentation/scaler.pkl`: The scaler used to preprocess the color data.
