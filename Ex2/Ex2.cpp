#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Quadtree
{
private:
    char val;
    Quadtree *quad1;
    Quadtree *quad2;
    Quadtree *quad3;
    Quadtree *quad4;

public:
    // Constructor to create a new Quadtree
    Quadtree(char v){
        val = v;
        quad1 = NULL;
        quad2 = NULL;
        quad3 = NULL;
        quad4 = NULL;
        
    }

    // Function to build a quadtree from a preorder traversal string
    static Quadtree *buildTreeFromString(const string &s, int &idx)
    {
        if (s[idx] == 'b' || s[idx] == 'w')
        {
            return new Quadtree(s[idx]);
        }

        Quadtree *node = new Quadtree('p');
        node->quad1 = buildTreeFromString(s, ++idx);
        node->quad2 = buildTreeFromString(s, ++idx);
        node->quad3 = buildTreeFromString(s, ++idx);
        node->quad4 = buildTreeFromString(s, ++idx);

        return node;
    }

    // Display the preorder traversal of the quadtree
    void preorderTraversal()
    {
        cout << val;
        if (quad1)
            quad1->preorderTraversal();
        if (quad2)
            quad2->preorderTraversal();
        if (quad3)
            quad3->preorderTraversal();
        if (quad4)
            quad4->preorderTraversal();
    }

    // Display the preorder traversal of the quadtree with levels indicated by dashes
    void preorderTraversalLevels(int level)
    {
        for (int i = 0; i < level; i++)
            cout << "-";
        cout << val << endl;

        // Proceed to display recursively from the sons too
        if (quad1)
            quad1->preorderTraversalLevels(level + 1); 
        if (quad2)
            quad2->preorderTraversalLevels(level + 1);
        if (quad3)
            quad3->preorderTraversalLevels(level + 1);
        if (quad4)
            quad4->preorderTraversalLevels(level + 1);
    }

    // Calculate the number of black pixels in the quadtree
    void calculatePixels(int level, int &sum)
    {
        if (this == nullptr)
        {
            return;
        }
        if (val == 'b')
        {
            sum = sum + 1024 / (pow(4, level)); // because each black pixel represents 1/4 of the amount of pixels its parent has and the root has 1024 pixels
        }
        this->quad1->calculatePixels(level + 1, sum);
        this->quad2->calculatePixels(level + 1, sum);
        this->quad3->calculatePixels(level + 1, sum);
        this->quad4->calculatePixels(level + 1, sum);
    }

    // Merge two quadtrees into a single quadtree
    static Quadtree *mergeQuadTrees(Quadtree *node1, Quadtree *node2)
    {
        if (!node1 && !node2)
        {
            return nullptr;
        }
        if (node1 && !node2)
        {
            return new Quadtree(node1->val);
        }
        if (!node1 && node2)
        {
            return new Quadtree(node2->val);
        }
        if (node1->val == 'w' && node2->val == 'w')
        {
            return new Quadtree('w');
        }
        if (node1->val == 'b' || node2->val == 'b')
        {
            return new Quadtree('b');
        }

        Quadtree *node = new Quadtree('p');
        node->quad1 = mergeQuadTrees(node1->quad1, node2->quad1);
        node->quad2 = mergeQuadTrees(node1->quad2, node2->quad2);
        node->quad3 = mergeQuadTrees(node1->quad3, node2->quad3);
        node->quad4 = mergeQuadTrees(node1->quad4, node2->quad4);
        return node;
    }
};

void displayImage(Quadtree *node) // function that displays the chosen node in either preorder representation with levels or without
{
    int choice;
    cout << "\n '1': preorder representation;\n"
         << " '2': preorder representation by levels;\n";
    cin >> choice;
    if (choice == 1)
    {
        cout << "\nThe preorder representation is: ";
        node->preorderTraversal();
        cout << endl;
    }
    else if (choice == 2)
    {
        cout << "\nThe preorder representation with levels is: \n";
        node->preorderTraversalLevels(0);
        cout << endl;
    }
    else
    {
        return;
    }
}

int main()
{
    string s1, s2;
    Quadtree *root1, *root2, *merged;
    char input;
    do // the "menu" interface loop that doesnt stop the program until we get 'e' as the input
    {
        cout << " Based on your following input different functions will happen, for: \n"
             << " '1' : read two strings, one for the first image and one for the second one and generates two QuadTrees for them;\n"
             << " '2' : displays the QuadTree preorder representation and preorder per level representation for the chosen tree;\n"
             << " '3' : merges the two given QuadTrees into the final image;\n"
             << " '4' : counts the black pixels in the chosen image;\n"
             << " 'e' : to exit the program;\n\n"
             << " Your choice: ";

        cin >> input; // reading the input

        if (input == '1')
        {
            cout << "\nGive the preorder representation for the first image:\n";
            cin >> s1;
            cout << "\nGive the preorder representation for the second image:\n";
            cin >> s2;
            int idx1 = 0;
            int idx2 = 0;
            root1 = root1->buildTreeFromString(s1, idx1);
            root2 = root2->buildTreeFromString(s2, idx2);
        }
        else if (input == '2')
        {
            char choice;
            cout << "\n\n Which image do you want to display?\n"
                 << " '1' : the first image;\n"
                 << " '2' : the second image;\n"
                 << " '3' : the final image;\n"
                 << " Your choice: ";
            cin >> choice;

            if (choice == '1')
                displayImage(root1);
            else if (choice == '2')
                displayImage(root2);
            else if (choice == '3')
                displayImage(merged);
        }
        else if (input == '3')
        {
            merged = merged->mergeQuadTrees(root1, root2);
        }
        else if (input == '4')
        {
            char choice;
            int sum = 0;
            cout << "\n\n Which image do you want to calculate the black pixels from?\n"
                 << " '1' : the first image;\n"
                 << " '2' : the second image;\n"
                 << " '3' : the final image;\n"
                 << " Your choice: ";
            cin >> choice;

            if (choice == '1')
            {
                root1->calculatePixels(0,sum);
                cout << "\nThe total number of black pixels in image 1 is : " << sum << endl;
            }
            else if (choice == '2')
            {
                root2->calculatePixels(0,sum);
                cout << "\nThe total number of black pixels in image 2 is : " << sum << endl;
            }
            else if (choice == '3')
            {
                merged->calculatePixels(0,sum);
                cout << "\nThe total number of black pixels in the final image is : " << sum << endl;
            }
        }
        cout << "\n";
    } while (input != 'e');

    return 0;
}