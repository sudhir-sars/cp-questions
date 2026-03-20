impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        if matrix.is_empty() || matrix[0].is_empty() {
            return;
        }

        let mut first_row_zero = false;
        let mut first_col_zero = false;

        let num_rows = matrix.len();
        let num_cols = matrix[0].len();

        for j in 0..num_cols {
            if matrix[0][j] == 0 {
                first_row_zero = true;
                break;
            }
        }

        for i in 0..num_rows {
            if matrix[i][0] == 0 {
                first_col_zero = true;
                break;
            }
        }

        for i in 1..num_rows {
            for j in 1..num_cols {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for i in 1..num_rows {
            for j in 1..num_cols {
                if matrix[i][0] == 0 || matrix[0][j] == 0 {
                    matrix[i][j] = 0;
                }
            }
        }

        if first_row_zero {
            for j in 0..num_cols {
                matrix[0][j] = 0;
            }
        }

        if first_col_zero {
            for i in 0..num_rows {
                matrix[i][0] = 0;
            }
        }
    }
}