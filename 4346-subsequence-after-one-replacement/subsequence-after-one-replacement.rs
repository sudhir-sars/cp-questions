impl Solution {
    pub fn can_make_subsequence(s: String, t: String) -> bool {
        let s = s.as_bytes();
        let n = s.len();

        let mut i = 0; // Next index in s to match (no replacement)
        let mut j = 0; // Next index in s to match (at most one replacement)

        for ch in t.bytes() {
            if j < n && s[j] == ch {
                j += 1;
            }

            if i < n && s[i] == ch {
                i += 1;
            } else {
                j = j.max(i + 1);
            }

            if i == n || j == n {
                return true;
            }
        }

        false
    }
}