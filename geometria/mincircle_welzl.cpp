class Welzl { // Finds min enclosing circle of N points in O(N)
    vector<pt> P, R;
    circle mec(int n, int b){
        if(           b == 3) return circle(R[0], R[1], R[2]); // Build circle from three points
        if(n == 1 and b == 0) return circle(P[0], 0);          // Build empty circle
        if(n == 0 and b == 2) return circle(R[0], R[1]);       // Build circle from two points
        if(n == 1 and b == 1) return circle(P[0], R[0]);

        circle D = mec(n-1, b);
        if(not D.has(P[n-1])){
            R[b] = P[n-1];
            D = mec(n-1, b+1);
        }
        return D;
    }
public:
    Welzl(vector<pt>& points) : P(points), R(points.size()) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(P.begin(), P.end(), rng);
    }
    circle minEnclosingCircle(){ return mec(P.size(), 0); }
};
