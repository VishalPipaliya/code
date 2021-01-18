public class MinimumCostToMakeTwoStringsIdentical {
    public static void main(String[] args) {

    }
    static int LCS(String st, String string) {
        int n = st.length(), m = string.length();
        int[][] arr = new int[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0)
                    arr[i][j] = 0;
                else if (i != j && st.charAt(i - 1) == string.charAt(j - 1))
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                else
                    arr[i][j] = Math.max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
        return arr[n][m];
    }
}
