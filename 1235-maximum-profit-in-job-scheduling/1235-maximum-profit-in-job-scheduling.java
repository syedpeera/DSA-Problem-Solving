import java.util.Arrays;
import java.util.Comparator;

public class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];

        for (int i = 0; i < n; i++) {
            jobs[i] = new int[]{startTime[i], endTime[i], profit[i]};
        }

        // Sort the jobs array based on end times
        Arrays.sort(jobs, Comparator.comparingInt(a -> a[1]));

        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            int include = jobs[i][2];
            int nextJob = binarySearch(jobs, jobs[i][0], i);
            if (nextJob != -1) {
                include += dp[nextJob];
            }

            dp[i] = Math.max(include, i > 0 ? dp[i - 1] : 0);
        }

        return dp[n - 1];
    }

    private int binarySearch(int[][] jobs, int target, int end) {
        int left = 0, right = end;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid][1] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return (right >= 0) ? right : -1;
    }
}
