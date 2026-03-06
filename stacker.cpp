/*
    stacker.cpp
    Group Name: The Lions
    Group Members: Brandon Daniel and Cameron O'Dell
    Course: CSCI325
    Description: Implements the Stacker class for reading, stacking,
    and writing ASCII PPM (P3) images.
*/
#include "stacker.h"


Stacker::Stacker() {
    magic_number = "";
    width = 0;
    height = 0;
    max_color = 0;
}

bool Stacker::readImage(const string& filename) {
    ifstream fin(filename);

    if (!fin) {
        return false;
    }

    fin >> magic_number;
    fin >> width >> height;
    fin >> max_color;

    if (magic_number != "P3") {
        fin.close();
        return false;
    }

    pixels.clear();

    Pixel temp;
    int totalPixels = width * height;

    for (int i = 0; i < totalPixels; i++) {
        fin >> temp.red >> temp.green >> temp.blue;
        pixels.push_back(temp);
    }

    fin.close();
    return true;
}

bool Stacker::stackImages(const string& imageName, int count) {
    if (count <= 0) {
        return false;
    }

    vector<long long> redSums;
    vector<long long> greenSums;
    vector<long long> blueSums;

    for (int i = 1; i <= count; i++) {
        ostringstream filename;
        filename << imageName << "/" << imageName << "_";

        if (i < 10) {
            filename << "00" << i;
        } else if (i < 100) {
            filename << "0" << i;
        } else {
            filename << i;
        }

        filename << ".ppm";

        cout << "     " << filename.str() << endl;

        ifstream fin(filename.str());
        if (!fin) {
            return false;
        }

        string currentMagic;
        int currentWidth, currentHeight, currentMax;

        fin >> currentMagic;
        fin >> currentWidth >> currentHeight;
        fin >> currentMax;

        if (currentMagic != "P3") {
            fin.close();
            return false;
        }

        if (i == 1) {
            magic_number = currentMagic;
            width = currentWidth;
            height = currentHeight;
            max_color = currentMax;

            int totalPixels = width * height;
            redSums.resize(totalPixels, 0);
            greenSums.resize(totalPixels, 0);
            blueSums.resize(totalPixels, 0);
        } else {
            if (currentWidth != width || currentHeight != height || currentMax != max_color) {
                fin.close();
                return false;
            }
        }

        int totalPixels = width * height;

        for (int p = 0; p < totalPixels; p++) {
            int r, g, b;
            fin >> r >> g >> b;

            redSums[p] += r;
            greenSums[p] += g;
            blueSums[p] += b;
        }

        fin.close();
    }

    pixels.clear();
    int totalPixels = width * height;

    for (int i = 0; i < totalPixels; i++) {
        Pixel temp;
        temp.red = static_cast<int>(redSums[i] / count);
        temp.green = static_cast<int>(greenSums[i] / count);
        temp.blue = static_cast<int>(blueSums[i] / count);
        pixels.push_back(temp);
    }

    return true;
}

bool Stacker::writeImage(const string& filename) const {
    ofstream fout(filename);

    if (!fout) {
        return false;
    }

    fout << magic_number << endl;
    fout << width << " " << height << endl;
    fout << max_color << endl;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int index = row * width + col;
            fout << pixels[index].red << " "
                 << pixels[index].green << " "
                 << pixels[index].blue;

            if (col < width - 1) {
                fout << "   ";
            }
        }
        fout << endl;
    }

    fout.close();
    return true;
}