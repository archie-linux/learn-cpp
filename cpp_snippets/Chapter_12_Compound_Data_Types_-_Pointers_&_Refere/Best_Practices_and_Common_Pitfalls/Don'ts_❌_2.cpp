int x = 5, y = 10;
int& ref = x;
ref = y;        // ❌ This assigns y's VALUE to x, doesn't rebind!
