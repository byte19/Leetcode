

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    
    
    int * result = (int *)malloc(matrixSize*(*matrixColSize)*sizeof(int));
    int left = 0, right = *matrixColSize-1, up = 0, down = matrixSize-1, idx = 0;
    while(left <= right && up <= down)
    {
        for(int i=left; i<=right; i++) //left to right
            result[idx++] = matrix[up][i];
        for(int i=up+1; i<=down; i++) //up to down
            result[idx++] = matrix[i][right]; 
        for(int i=right-1; i>left && up != down; i--) //right to left
            result[idx++] = matrix[down][i];
        for(int i=down; i>up && left != right; i--) //down to up
            result[idx++] = matrix[i][left];
        up++; down--; left++; right--;
    }
    *returnSize = idx;
    return result;
    
}