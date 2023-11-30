#ifndef EIGHTPUZZ_H
#define EIGHTPUZZ_H
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> solved = {{1,2,3},{8,0,4},{7,6,5}};

#define length 3 //Size of puzzle
struct TreeNode{
    vector<vector<int>> puzzle;
    int level;
    struct TreeNode *left;
    struct TreeNode *up;
    struct TreeNode *right;
    struct TreeNode *down;
    struct TreeNode *parent;
    
};

/*
Four Functions to swap values in the tree
*/
vector<vector<int>> swapUp(vector<vector<int>> puzz);
vector<vector<int>> swapDown(vector<vector<int>> puzz);
vector<vector<int>> swapLeft(vector<vector<int>> puzz);
vector<vector<int>> swapRight(vector<vector<int>> puzz);

//Utility Functions not needed but maks it easier/more efficient
void copyArray(vector<vector<int>> puzzle, vector<vector<int>> puzz);
void printPuzz(vector<vector<int>> puzzle);
bool areEqual(vector<vector<int>> puzzle, vector<vector<int>> puzz);
bool equalsParents(TreeNode* root);

//Creates the tree that will be traversed
TreeNode* buildTree(TreeNode* root, int depth);

//The search functions to find the solution
void dfs(TreeNode* root);
void bfs(TreeNode* root);

//Dijkstras search and the required functions for it
void Dijkstra(TreeNode* root);
int findPathCost(TreeNode* root);
int swapCost(vector<vector<int>> puzzle, vector<vector<int>> puzz);


#endif 