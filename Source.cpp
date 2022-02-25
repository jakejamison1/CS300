//============================================================================
// Name        : FINAL PROJECT
// Author      : Jacob Jamison
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Course structure

struct Course {

    string courseNumber;

    string name;

    vector<string> prerequisites;

};

// Function to split string to list of strings

vector<string> tokenize(string s, string del = " ") {

    vector<string> stringArray;

    int start = 0;

    int end = s.find(del);

    while (end != -1) {

        stringArray.push_back(s.substr(start, end - start));

        start = end + del.size();

        end = s.find(del, start);

    }

    stringArray.push_back(s.substr(start, end - start));

    return stringArray;

}

// Function to load file

vector<Course> LoadDataStructure() {

    // Class to open file

    ifstream fin("abcu.txt", ios::in);

    vector<Course> courses;

    string line;

    // While loop

    while (1) {

        getline(fin, line);
        
        // If end is reached break the loop

        if (line == "-1")

            break;

        Course course;

        // Getting tokenized info.

        vector<string> tokenizedInformation = tokenize(line, ",");

        // Storing info.

        course.courseNumber = tokenizedInformation[0];

        course.name = tokenizedInformation[1];

        // For prerequisites storage

        for (int i = 2; i < tokenizedInformation.size(); i++) {

            course.prerequisites.push_back(tokenizedInformation[i]);

        }

        // Append courses

        courses.push_back(course);

    }

    // Close file

    fin.close();

    // Return list of courses

    return courses;

}

void printCourse(Course course) {

    string courseNumber = course.courseNumber;

    string name = course.name;

    vector<string> prerequisites = course.prerequisites;

    // Printing course info.

    cout << "Course Number: " << courseNumber << endl;

    cout << "Course Name: " << name << endl;

    cout << "Prerequisites: ";

    for (int i = 0; i < prerequisites.size(); i++) {

        cout << prerequisites[i] << " ";

    }

    // Print new line for readability

    cout << "\n";
}

// Printing course list info.

void printCourseList(vector<Course> courses) {

    int n = courses.size();

    // Using bubble sort to sort the list

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (courses[j].courseNumber > courses[j + 1].courseNumber) {

                swap(courses[j + 1], courses[j]);

            }

        }

    }

    // Traversing list to print

    for (int i = 0; i < n; i++) {

        printCourse(courses[i]);

    }

}

// Search courses for prerequisites

void searchCourse(vector<Course> courses) {

    int n = courses.size();
    
    string courseNumber;
    
    int f = 0;

    cout << "Enter course number: ";

    cin >> courseNumber;

    // Allows user input of lowercase or uppercase 

    transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);

    for (int i = 0; i < n; i++) {

        // If found

        if (courses[i].courseNumber == courseNumber) {
            
            f = 1;

            // Print course

            printCourse(courses[i]);

            break;

        }

    }

    // If not found

    if (f == 0) {

        //Print error message

        cout << "Course not found!\n";

    }

}

// The one and only main!

int main(int argc, char** argv) {

    vector<Course> courses;

    // Print menu

    cout << "1.Load Data Structure\n";

    cout << "2.Print Course List\n";

    cout << "3.Print Course\n";

    cout << "9.Exit\n";

    int choice;

    // Loop breaks when 9 is pressed

    do {

        // Print for user input

        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {

        case 1: courses = LoadDataStructure(); 
            break;

        case 2: printCourseList(courses); 
            break;

        case 3: searchCourse(courses); 
            break;

        case 4: cout << "Exit\n"; 
            break;

        // Print invalid choice

        cout << "Invalid Choice\n";

        }

    } 
    
    while (choice != 9);

    cout << "Thank you for using the course planner!" << endl;

    return 0;

}