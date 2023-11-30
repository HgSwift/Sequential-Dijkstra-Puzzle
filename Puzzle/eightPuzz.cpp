#include <limits.h>
#include <list>
#include <set>
#include <algorithm>
#include <fstream>
#include "eightPuzz.hpp"


const int maxDepth =  24;
TreeNode* newNode(vector<vector<int>> data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
    // Assign data to this node 
    node->level = 0;
    node->puzzle = data;
    // Initialize children as NULL 
    node->left = NULL; 
    node->right = NULL; 
    node->up = NULL; 
    node->down = NULL; 
    node->parent = NULL;
    return(node); 
} 
/**
 * Process: Checks if the maximim allowed depth has been reached
 * then creates a temporary node with a directionally swapped puzzle
 * then checks if the puzzle is solved, if so stops it from continuing
 * by setting the depth to its maximum value
 * then checks if the new node is similar to any of the nodes above it in the 
 * chain, if they are not it increases the depth and recurs
 * repeated with each direction.
*/
TreeNode* buildTree(TreeNode* root, int depth){

    if(depth < maxDepth){ //Will not go deeper than the maximum depth value
        TreeNode* tempUp = newNode(swapUp(root->puzzle));
        tempUp->parent = root;
        if(tempUp->puzzle == solved){
            //cout << "*";
            tempUp->level = depth;
            depth = maxDepth;
        }
        if(!equalsParents(tempUp)){
            root->up = tempUp;
            buildTree(tempUp, depth + 1);
        }
    }

    if(depth < maxDepth){ //Will not go deeper than the maximum depth value
        TreeNode* tempDown = newNode(swapDown(root->puzzle));
        tempDown->parent = root;
        if(tempDown->puzzle == solved){
            //cout << "*";
            tempDown->level = depth;
            depth = maxDepth;
        }
        if(!equalsParents(tempDown)){
            root->down = tempDown;
            buildTree(tempDown, depth + 1);
        }
    }

    if(depth < maxDepth){ //Will not go deeper than the maximum depth value
        
        TreeNode* tempRight = newNode(swapRight(root->puzzle));
        tempRight->parent = root;
        if(tempRight->puzzle == solved){
            //cout << "*";
            tempRight->level = depth;
            depth = maxDepth;
        }
        if(!equalsParents(tempRight)){
            root->right = tempRight;
            buildTree(tempRight, depth + 1);
        }
    }

    if(depth < maxDepth){ //Will not go deeper than the maximum depth value
        
        TreeNode* tempLeft = newNode(swapLeft(root->puzzle));
        tempLeft->parent = root;
        if(tempLeft->puzzle == solved){
            //cout << "*";
            tempLeft->level = depth;
            depth = maxDepth;
        }
        if(!equalsParents(tempLeft)){
            root->left = tempLeft;
            buildTree(tempLeft, depth + 1);
        }
    }
    return root;
}

/**WIP MAIN FUNCTION
 * Creates a massive tree then uses BFS DFS and Dijkstra  to 
 * find the solution of the puzzle.
*/
int main(){
    ifstream file;
    file.open("Unsolved.txt");
    if(file.is_open()){
        vector<int> frames;
        vector<vector<int>> startPuzzle;
        char c;
        int count;
        while (file >> c) {    
            count++;
            frames.push_back(c - '0');
            if(count%3 == 0){
                startPuzzle.push_back(frames);
                frames.pop_back();
                frames.pop_back();
                frames.pop_back();
            }
        
        }

        TreeNode *EightPuzz = newNode(startPuzzle);
        int depth = 1;
        buildTree(EightPuzz, depth);
        dfs(EightPuzz);
        bfs(EightPuzz);
        Dijkstra(EightPuzz);//*/
    }else{
        cout << "File failed to open make sure it is named Unsolved.txt" << endl;
    }
    return 0;
}


