    for(int i=n; i >= 0 && V > 0; i--) {
        if (V >= coins[i]) {
            ans += V / coins[i];
            V = V % coins[i];
        }
    }