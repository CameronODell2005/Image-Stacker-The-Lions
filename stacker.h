/*
    stacker.cpp
    Group Name: The Lions
    Group Members: Brandon Daniel and Cameron O'Dell
    Course: CSCI325
    Description: 
    Declares the Stacker class used to read multiple PPM images,
    average their pixel values, and write the final stacked image.
*/
#ifndef STACKER_H
#define STACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Stacker {
private:
    /*
     * Struct: Pixel
     * Description:
     *    Stores one pixel's RGB color values.
     */
    struct Pixel {
        int red;
        int green;
        int blue;
    };

    string magic_number;
    int width;
    int height;
    int max_color;
    vector<Pixel> pixels;

public:
    /*
     * Default constructor.
     * Initializes an empty image.
     */
    Stacker();

    /*
     * Reads a PPM image from the given filename.
     * Returns true if successful, false otherwise.
     */
    bool readImage(const string& filename);

    /*
     * Stacks multiple PPM images using the folder/image naming scheme.
     * Example:
     *    imageName = "orion", count = 10
     * reads:
     *    orion/orion_001.ppm through orion/orion_010.ppm
     *
     * Returns true if all images are successfully stacked.
     */
    bool stackImages(const string& imageName, int count);

    /*
     * Writes the stacked image to the given filename.
     * Returns true if successful, false otherwise.
     */
    bool writeImage(const string& filename) const;
};

#endif