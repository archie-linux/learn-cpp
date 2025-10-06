#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>

namespace mini_container {

class Container {
public:
    Container(const std::string& command);
    void run();  // Run the command in a containerized environment
private:
    std::string command_;
};

} // namespace mini_container

#endif // CONTAINER_H
