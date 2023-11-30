#include "eightPuzz.hpp"



//Print Function
void printPuzz(vector<vector<int>> puzzle){
    for(int i = 0; i<length; i++){
        std::cout << "Row#"<< i+1 << " ";
        for(int j = 0; j<length; j++){
             std::cout << puzzle[i][j];
        }
        std:: cout << std::endl;
    }
}
/*
Four functions that will swap the values in 
the puzzle in the specified directions
*/

vector<vector<int>> swapUp(vector<vector<int>> puzzle){
    int x = 0;
    int y = 0;
    for(int i = 0; i<length; i++){
        for(int j = 0; j<length; j++){
            if(puzzle[i][j]==0){
                x = i;
                y = j;
            }
        }
    }
    if(x > 0){
        int temp = puzzle[x-1][y];
        puzzle[x][y] = temp;
        puzzle[x-1][y] = 0;
    }
    return puzzle;

}
vector<vector<int>> swapDown(vector<vector<int>> puzzle){
    int x = 0;
    int y = 0;
    for(int i = 0; i<length; i++){
        for(int j = 0; j<length; j++){
            if(puzzle[i][j]==0){
                x = i;
                y = j;
            }
        }
    }
    if(x < 2){
        int temp = puzzle[x+1][y];
        puzzle[x][y] = temp;
        puzzle[x+1][y] = 0;
    }
    return puzzle;

}
vector<vector<int>> swapLeft(vector<vector<int>> puzzle){
    int x = 0;
    int y = 0;
    for(int i = 0; i<length; i++){
        for(int j = 0; j<length; j++){
            if(puzzle[i][j]==0){
                x = i;
                y = j;
            }
        }
    }
    if(y > 0){
        int temp = puzzle[x][y-1];
        puzzle[x][y] = temp;
        puzzle[x][y-1] = 0;
    }
    return puzzle;
}

vector<vector<int>> swapRight(vector<vector<int>> puzz){
    int x = 0;
    int y = 0;
    for(int i = 0; i<length; i++){
        for(int j = 0; j<length; j++){
            if(puzz[i][j]==0){
                x = i;
                y = j;
            }
        }
    }
    if(y < 2){
        int temp = puzz[x][y+1];
        puzz[x][y] = temp;
        puzz[x][y+1] = 0;
    }
    //std::cout << "HI";
    return puzz;
}
void copyArray(vector<vector<int>> puzzle, vector<vector<int>> puzz){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            //std::cout << i << " " << j << " " << puzz[i][j] << " " << puzzle[i][j] << std::endl;
            puzzle[i][j] =puzz[i][j];    
        }
    }
}
//Checks if 2 2d arrays are equal

//Checks if this specific configuration has been found above it
bool equalsParents(TreeNode* root){
    TreeNode* temp = root;
    if(temp->parent != NULL){
        temp = temp->parent;
    }else{
        return false;
    }
    while(temp->parent != NULL){
        if(root->puzzle == temp->puzzle){
            return true;
        }
        temp = temp->parent;
    }
    return false;
}
int count = 0;
//3 Search Functions Breadth first, Depth First and Djikstras
//DFS uses a preorder traversal to search for the solved value
bool found = false;
void dfs(TreeNode* root){
    if(found){
        return;
    }
    if(root->puzzle == solved && found == false){
        cout << "Depth First Search(DFS) found at level : " << root->level << endl;
        found = true;
        return;
    } 
    if(root->left != NULL){
        dfs(root->left);
    }
    if(root->up != NULL){
        dfs(root->up);
    }
    if(root->right != NULL){
        dfs(root->right);
    }
    if(root->down != NULL){
        dfs(root->down);
    }
    return;
}
//Searches in a top down order to find a solved part of the tree
void bfs(TreeNode* root){
    queue<TreeNode *> pQueue;
    pQueue.push(root);
    while (pQueue.empty() == false){
        TreeNode* node = pQueue.front();
        if(node->puzzle == solved){
            cout << "Breadth First Search(DFS) found at level : " << node->level << endl;
            return;
        }
        pQueue.pop();
        if(node->left != NULL){
            pQueue.push(node->left);
        }
        if(node->up != NULL){
            pQueue.push(node->up);
        }
        if(node->right != NULL){
            pQueue.push(node->right);
        }
        if(node->down != NULL){
            pQueue.push(node->down);
        }
    }
}
//Similar to BFS but uses path calculations in order to find the shortest path
void Dijkstra(TreeNode* root){
    queue<TreeNode *> pQueue;
    pQueue.push(root);
    while (pQueue.empty() == false){
        TreeNode* node = pQueue.front();
        if(node->puzzle == solved){
            int cost = findPathCost(node);
            cout << "Dijkstra's shortest path cost = " << cost << endl;
            return;
        }
        pQueue.pop();
        if(node->left != NULL){
            pQueue.push(node->left);
        }
        if(node->up != NULL){
            pQueue.push(node->up);
        }
        if(node->right != NULL){
            pQueue.push(node->right);
        }
        if(node->down != NULL){
            pQueue.push(node->down);
        }
    }
 }
//Two functions used to help calculate the shortest path cost
int findPathCost(TreeNode* root){
    int cost = 0;
    int lvl = root->level;
    while(root->parent != NULL){
        lvl--;
        cost += swapCost(root->puzzle, root->parent->puzzle);
        root = root->parent;
    }
    return cost;
}
int swapCost(vector<vector<int>> puzzle, vector<vector<int>> puzz){
    for(int i = 0; i<length; i++){
        for(int j = 0; j<length; j++){
            if(puzzle[i][j]==0){
                return puzz[i][j];
            }
        }
    }
    return 0;
}