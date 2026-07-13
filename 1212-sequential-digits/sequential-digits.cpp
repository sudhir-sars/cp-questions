class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int length = 2; length <= 9; length++) {
            for (int startDigit = 1; startDigit + length <= 10; startDigit++) {

                int currentNumber = 0;

                for (int digit = startDigit; digit < startDigit + length; digit++) {
                    currentNumber = currentNumber * 10 + digit;
                }

                if (currentNumber >= low && currentNumber <= high) {
                    ans.push_back(currentNumber);
                }
            }
        }

        return ans;
    }
};