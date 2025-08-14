class Solution {
public:
    string largestGoodInteger(string num) {

        for (char digit = '9'; digit >= '0'; --digit) {

            string triplet(3, digit);

            if (num.find(triplet) != string::npos) {

                return triplet;
            }
        }

        return "";
    }
};
