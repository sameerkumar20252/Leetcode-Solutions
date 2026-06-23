/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int left = 0, right = (*matrixColSize) - 1;
    int top = 0, bottom = matrixSize - 1;

    int totalElements = matrixSize * (*matrixColSize);
    *returnSize = totalElements;
    int* result = (int*)malloc(totalElements * sizeof(int));
    int index = 0;

    while (left <= right && top <= bottom) {
        // Traverse top row
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;

}