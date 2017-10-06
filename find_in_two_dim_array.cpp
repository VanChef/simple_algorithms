
/*
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

解题思路：从二维数组的右上角的元素开始判断，因为此元素是它所在行的最大数，是它所在的列的最小数。如果它等于要查找的数字，则查找过程结束。如果它大于要查找的数字，则可以排除它所在的列。如果它小于要查找的数字，则可排除它所在的行。这样如果要查找的数字不在数组的右上角，则每次判断都可以排除一行或一列以缩小查找范围，直到找到要查找的数字，或者查找范围为空。

*/

// 二维数组matrix
// 每一行都从左到右递增排序
// 每一列都从上到下递增排序
bool Find(int *matrix, int rows, int columns, int number)
{
    bool found = false;

    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;

        while(row < rows && column >=0)
        {
            if(matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if(matrix[row * columns + column] > number)
                --column;
            else
                ++row;
        }
    }

    return found;
}
