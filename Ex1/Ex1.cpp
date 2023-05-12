#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream f("index.in.txt");
ofstream g("index.out.txt");

int main()
{
    string a[1000];
    string x;
    int i = 0;
    while (f >> x && x != ".") // while we can read strings from the input stream
    {
        a[i] = x; // save the string in a string vector
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        cout << a[j] << " "; // display the string vector in the terminal (for debugging only)
    }
    cout << endl;
    int numberwords = i;
    string y;

    // find the unique characters from the vector of strings a
    string unique = "";
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < a[j].length(); k++)
        {
            if (unique.find(a[j][k]) == string::npos) // checks if the found character exists in the 'unique' vector by comparing the value of unique.find with string::npos which returns that the value was not found
                unique += a[j][k];                    // if it wasnt found then it adds it to the 'unique' vector
        }
    }

    // sort the unique characters
    for (int j = 0; j < unique.length() - 1; j++)
    {
        for (int k = j + 1; k < unique.length(); k++)
        {
            if (unique[j] > unique[k])
            {
                char aux = unique[j];
                unique[j] = unique[k];
                unique[k] = aux;
            }
        }
    }

    cout << unique << endl;
    // get the legth of the unique characters
    int n = unique.length();
    int mat[n][n];
    // initialize the matrix with 0
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            mat[j][k] = 0;

    // build the matrix associated to the graph (adjacency matrix)
    for (int j = 0; j < numberwords; j++)
    {
        x = a[j];
        y = a[j + 1];
        int leng;
        if (x.length() > y.length())
            leng = y.length();
        else
            leng = x.length();
        for (int k = 0; k < leng; k++)
        {
            if (x[k] != y[k])
            {
                mat[unique.find(x[k])][unique.find(y[k])] = 1;
                // cout << x[k] << " " << y[k] << endl;
                break;
            }
        }
    }

    cout << endl;

    // print the matrix
    cout << "  ";
    for (int j = 0; j < n; j++)
        cout << unique[j] << " ";
    cout << endl;
    for (int j = 0; j < n; j++)
    {
        cout << unique[j] << " ";
        for (int k = 0; k < n; k++)
            cout << mat[j][k] << " ";
        cout << endl;
    }

    cout << endl;
    // topological sort algorithm
    int viz[n];
    for (int j = 0; j < n; j++)
        viz[j] = 0;
    int stiva[n];
    int k = 0;
    string rez = "";
    for (int j = 0; j < n; j++)
    {
        if (viz[j] == 0)
        {
            viz[j] = 1;
            stiva[k] = j;
            k++;
            while (k > 0)
            {
                int ok = 0;
                for (int l = 0; l < n; l++)
                {
                    if (mat[stiva[k - 1]][l] == 1 && viz[l] == 0)
                    {
                        viz[l] = 1;
                        stiva[k] = l;
                        k++;
                        ok = 1;
                        break;
                    }
                }
                if (ok == 0)
                {
                    // cout << unique[stiva[k - 1]] << " ";
                    rez += unique[stiva[k - 1]];
                    k--;
                }
            }
        }
    }

    // reverse rez
    string aux = "";
    for (int j = rez.length() - 1; j >= 0; j--)
        aux += rez[j];
    rez = aux;
    g << rez << endl;

    return 0;
}