# Web Crawler

A multi-threaded web crawler implemented in C++ that respects robots.txt, extracts links, and generates a sitemap visualization.

## Features

- **Concurrent Crawling**: Uses multiple threads to crawl web pages efficiently.
- **Politeness**: Respects robots.txt rules to avoid banned paths.
- **Data Parsing**: Extracts links from HTML content.
- **Visualization**: Generates a sitemap in Graphviz DOT format.

## Prerequisites

- C++17 compatible compiler
- libcurl library
- CMake 3.10 or higher

## Build Instructions

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

```bash
./web_crawler https://example.com
```

## Output

- `data/crawled_urls.txt`: List of crawled URLs.
- `data/sitemap.dot`: Graphviz DOT file for sitemap visualization.

## Visualization

Use Graphviz to visualize the sitemap:

```bash
dot -Tpng data/sitemap.dot -o sitemap.png
```
