Documentation


Program 1: Topological Ordering of Words

The program is a C++ program that reads a list of words from a file named "index.in.txt", and processes them to generate a topological ordering of their characters. The resulting ordering is then written to a file named "index.out.txt".
Input

The input is a list of words stored in the "index.in.txt" file. The words must be separated by white spaces and end with a period character '.'.
Output

The output is the topological ordering of the characters in the input words, which is stored in the "index.out.txt" file.
How it works

    1.The program includes the necessary header files: <iostream>, <string>, and <fstream>.
    2.It opens the input and output files using the ifstream and ofstream classes.
    3.The program uses an array of strings, 'a', to store the words read from the input file until the period character is found. The number of words read is stored in the integer variable 'numberwords'.
    4.The program then finds the unique characters present in the words by iterating through each word and checking each character in it. A string variable named 'unique' is used to store the unique characters. The unique characters are sorted in alphabetical order using a simple selection sort algorithm.
    5.The program then builds an adjacency matrix for the graph associated with the unique characters. The matrix is initialized with zeros and then filled by iterating through each pair of adjacent words and comparing their characters. If two characters are different, an edge is added to the adjacency matrix from the first character to the second character.
    6.The program then performs a topological sort on the graph represented by the adjacency matrix using a stack-based algorithm.
    7.The resulting topological ordering of the characters is then written to the output file named "index.out.txt".

How to run

To run the program, ensure that the "index.in.txt" file is in the same directory as the program file and compile and execute the program.


Program 2: Quadtree Image Representation

The program defines a class called "Quadtree" which can be used to represent an image. It has private member variables "val" which stores a character value representing the color of a pixel, and "quad1", "quad2", "quad3", and "quad4" which store pointers to four other "Quadtree" objects that represent the four quadrants of the current image.
How it works

    1.The program defines a "Quadtree" class which has several member functions.
    2.The constructor initializes the "val" variable to a given character value, and initializes the "quad1", "quad2", "quad3", and "quad4" pointers to NULL.
    3.The buildTreeFromString function builds a "Quadtree" object from a given string that represents a preorder traversal of a quadtree. It returns a pointer to the root of the quadtree.
    4.The preorderTraversal function performs a preorder traversal of the quadtree and prints out the "val" variable for each node visited.
    5.The preorderTraversalLevels function performs a preorder traversal of the quadtree and prints out the "val" variable for each node visited, along with a number of dashes indicating the depth of each node.
    6.The calculatePixels function calculates the number of black pixels in the quadtree and stores the result in a given "sum" variable.
    7.The mergeQuadTrees function merges two "Quadtree" objects into a single "Quadtree" object.
    8.The displayImage function takes a "Quadtree" pointer as input and displays the preorder representation of the quadtree, either with or without levels, depending on user input.

To use the program, the user can perform several actions through the menu interface loop in the main function:

    Read two strings representing QuadTrees, build QuadTrees for them, and store the roots of the QuadTrees in "root1" and "root2".
    Display the preorder representation of the QuadTree for a chosen root, either with or without levels.
    Merge "root1" and "root2" into a single QuadTree and store the root in "merged".
    Calculate the number of black pixels in "root1" and "root2", and display the results.
    Exit the program.

The Quadtree class is a useful data structure for representing and manipulating images. The program's member functions provide flexibility and ease of use for building, manipulating, and analyzing Quadtree objects. The program's menu interface loop allows users to interact with the Quadtree objects and perform various operations on them.