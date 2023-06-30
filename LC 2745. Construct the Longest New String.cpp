class Solution {
public:
    int longestString(int x, int y, int z) {
        // aa, bb, ab
        // aa: front: bb, ab, back: bb;
        // bb: front: aa, back: aa, ab
        // ab: front: ab, bb, back: ab, aa
        int mini = min(x, y);
        return min(2*(x+y+z), 2*(z+mini*2+1));
        
    }
};
