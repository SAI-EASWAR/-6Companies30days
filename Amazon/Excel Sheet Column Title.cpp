class Solution {
public:
    string convertToTitle(int columnNumber) {

        string result = "";

        while(columnNumber > 0){
            int num = (columnNumber - 1) % 26;
            char x = 'A' + num;
            columnNumber = (columnNumber - 1) / 26;
            result = x + result;
        }

        return result;
    }
};