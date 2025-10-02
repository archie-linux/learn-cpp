// Repetitive and error-prone!
int max(int x, int y) { return (x < y) ? y : x; }
double max(double x, double y) { return (x < y) ? y : x; }
float max(float x, float y) { return (x < y) ? y : x; }
long max(long x, long y) { return (x < y) ? y : x; }
// ... and so on for every type!
