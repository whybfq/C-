int gcd(int x, int y) {
    int t;
    t = x % y;   // Split phase division
    while(t != 0) {
        x = y;
        y = t;
        t = x % y;
    }
    return y;
}
