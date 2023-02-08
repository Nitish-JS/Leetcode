class Solution {
    public String convert(String s, int numRows) {
        //Define StringBuilders
        StringBuilder[] sbs = new StringBuilder[numRows];
        for(int i = 0; i < numRows; i++)
        {
            sbs[i] = new StringBuilder();
        }

        //Define Variables
        char[] arr = s.toCharArray();
        int n = arr.length;
        int index = 0;

        //Tranverse zig-zag
        while(index < n)
        {
            //Go down
            for(int j = 0; j < numRows && index < n; j++)
            {
                sbs[j].append(arr[index++]);
            }
            //Go up Before Start
            for(int j = numRows - 2; j > 0 && index < n; j--)
            {
                sbs[j].append(arr[index++]);
            }
        }

        //Combine all stringbuilders into one
        StringBuilder res = sbs[0];
        for(int i = 1; i < numRows; i++)
        {
            res.append(sbs[i].toString());
        }
        return res.toString();
    }
}