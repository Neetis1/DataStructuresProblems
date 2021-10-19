        int maxConsecutiveOnes = 0;
        int count = 0;
        for (int i = 0; i <= nums.size(); i++) {
            if (i < nums.size() && nums[i] == 1) {
                count++;
            } else {
                maxConsecutiveOnes = max(maxConsecutiveOnes, count);
                count = 0;
            }
        }
        return maxConsecutiveOnes;
    }
