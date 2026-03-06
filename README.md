# Image-Stacker-The-Lions
PPM Image Stacker
Author: Brandon Daniel and Cameron O'Dell (The Lions)

Description:
This program reads multiple ASCII PPM (P3) image files of the same object,
averages the RGB values of corresponding pixels, and writes a new stacked
image to reduce noise.

Design Decisions:
- I used a Stacker class to store the image metadata and the final stacked pixels.
- I used a Pixel struct with red, green, and blue integer fields.
- I used a vector<Pixel> to store the final image pixels as required.
- During stacking, I used three temporary vectors of long long values to
  hold running sums for red, green, and blue. After all images were read,
  I divided each sum by the number of images to get the average pixel value.

How to Compile:
make

How to Run:
./stacker_program

Example:
Please enter the image you wish to stack: orion
Please enter the number of images: 10

Output:
The program reads:
orion/orion_001.ppm
orion/orion_002.ppm
...
orion/orion_010.ppm

Then writes:
orion.ppm

Assumptions:
- All input files are valid P3 PPM files.
- All images in a stack have the same width, height, and max color value.
- Images follow the required naming pattern:
  folderName/folderName_001.ppm
  folderName/folderName_002.ppm
  etc.

Challenges:
- One challenge was making sure the file naming format matched the sample data.
- Another challenge was averaging the pixels correctly while keeping the code organized.

Work Split:
- If working with a partner, list how the work was shared here.
- Example:
  One partner implemented file reading and writing.
  The other partner implemented stacking logic and testing.