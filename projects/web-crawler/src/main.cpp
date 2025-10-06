#include "Crawler.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <start_url>\n";
        return 1;
    }
    
    Crawler crawler(argv[1], 4, 100); // 4 threads, max 100 URLs
    crawler.start();
    crawler.stop();
    return 0;
}
