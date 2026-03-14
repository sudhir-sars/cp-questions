impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let n = num_rows as usize;
        let mut res: Vec<Vec<i32>>=Vec::with_capacity(n);
        for i in 0..n{
            let mut row_vec=vec![1;i+1];
            for j in 1..i{
                row_vec[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push(row_vec);
        }
        res
    }
}