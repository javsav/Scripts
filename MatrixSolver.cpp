#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>

class MatrixSolver {

  private:

  int rows = 3;
  int cols = 4;
  double divisor = 0;
  int pivotRow = 0;
  int currentColumn = 0;
  int currentRow = 0;

  public:

  void printMatrix(std::vector<std::vector<double>> matrix) {
    std::cout << "\n";
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
      std::cout << std::setw(12) << matrix[i][j] << std::setw(12);
    }
    std::cout << "\n";
  }
  }

 
  
  std::vector<std::vector<double>>& solveMatrix(std::vector<std::vector<double>>& matrix) {
    rows = matrix.size();
    cols = matrix[0].size();
    
    while (currentRow < rows - 1) {
      for (int row = currentRow; row < rows; row++) {
        if (matrix[row][currentColumn]) {
          pivotRow = row;
          
          if (pivotRow != currentRow) {
            std::vector<double> tempRow = matrix[row];
            std::vector<double> tempUpperRow = matrix[currentRow];
            
            matrix[currentRow] = tempRow;
            matrix[row] = tempUpperRow;
            
        }
          break;
        } 


      }

      divisor = matrix[currentRow][currentColumn];

      if (divisor == 0) {
        currentColumn++;
        continue;
      }

      if (divisor != 1) {
        for (auto i = matrix[currentRow].begin(); i != matrix[currentRow].end(); ++i) {
          *i /= divisor;

        }
      }


      for (int row = 0; row < rows; row++) {
        if (row == currentRow) {
          continue;
        }
        if (matrix[row][currentColumn]) {
          double cellValue = matrix[row][currentColumn];
          for (int column = currentColumn; column < cols; column++) {
            matrix[row][column] = matrix[row][column] - (cellValue * matrix[currentRow][column]);
          }
        } 

      }
      currentRow++;
      currentColumn++;
    }
    
    return matrix;

  }


};

int main() {
  std::vector<std::vector<double>> matrix = {{1,3,0,1,8,3},{1,8,0,14,9,6},{2,6,0,2,16,6}, {3,4,0,3,7,6}};
  MatrixSolver solver;

 solver.solveMatrix(matrix);
 solver.printMatrix(matrix);
  
}