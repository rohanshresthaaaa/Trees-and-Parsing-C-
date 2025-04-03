//Rohan Shrestha
//CS2235
#include "BinHeap.h"
#include <vector>
#include <string>
#include <cctype>


void reverseVectorIterative(std::vector<int>& vec)
{
    int start=0; //start begins at first index
    int end=vec.size()-1; //end begins at last index
    int temp = 0;//creating temporary variable for swapping

    while(start<end) {
        temp=vec[start];// swapping elements at start and end positions
        vec[start]=vec[end];
        vec[end]=temp;

        start++;
        end--;
    }
}

void reverseHelper(std::vector<int>& vec, int start, int end) //using helper function to reverse a vector using recursion
{
    if (start >= end) return; //stopping when start index is greater than or equal to the end index
    std::swap(vec[start], vec[end]); //swapping the elements at start and end indices
    reverseHelper(vec, start + 1, end - 1);
}

void reverseVectorRecursive(std::vector<int>& vec)//initializing the recursion by calling helper function
{
    reverseHelper(vec, 0, vec.size() - 1);
}

std::vector<std::string> tokenizeString(const std::string& str) {
    std::vector<std::string> tokens;
    size_t i = 0;
    while (i < str.length()) {
        if (std::isspace(str[i])) //if the character is a space it will be skipped and move to next character
            {
            i++;
        } else if (std::isdigit(str[i])) //if the character is digt, it will start number token
            {
            size_t start = i;
            while (i < str.length() && std::isdigit(str[i])) {
                i++;
            }
            tokens.push_back(str.substr(start, i - start));
        } else {
            //if the character is not a space or digit , it is a single character token
            tokens.push_back(std::string(1, str[i]));
            i++;
        }
    }
    return tokens;
}

void binheapSort(std::vector<int>& vec) {
    BinHeap heap; //The total time complexity of this heap sort algorithm is nlogn.
heap.buildheap(vec);
    for(int i=0; i < vec.size(); i++) {
        vec[i]=heap.delMin();
    }
    
}