/*
    main.cpp
    Group Name: The Lions
    Group Members: Brandon Daniel and Cameron O'Dell
    Course: CSCI325
    Description: 

*/

 #include <iostream>
 #include <sstream>
 #include <iomanip>
 #include "stacker.h"

 using namespace std;

 int main() {
    string name;  //image directory/name
    int num;      //number of images to stack

    //ask user for base image name
    cout << "Please enter the image you wish to stack: ";
    cin >> name;

    //ask user for number of images
    cout << "Please enter the number of images: ";
    cin >> num;

    Stacker stacker; //create stacker object

    cout << "Stacking images:\n";

    //loop through all images
    for (int i = 1; i <= num; i++) {
        stringstream ss;

        //build filename like: orion/orion_001.ppm
        ss << name << "/" << name << "_"
           << setw(3) << setfill('0') << i
           << ".ppm";
        
        string filename = ss.str();

        cout << "     " << filename << endl;

        //first image initializes pixel vector
        if (i == 1)
            stacker.loadImage(filename);
        else
            stacker.addImage(filename);
    }

    //compute average pixel values
    stacker.averagePixels(num);

    //output filename
    string output = name + ".ppm";

    cout << "\nStacking succeeded.\n";
    cout << "Output written to: " << output << endl;

    return 0;
 }