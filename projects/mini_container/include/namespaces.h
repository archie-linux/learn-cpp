#ifndef NAMESPACES_H
#define NAMESPACES_H

namespace mini_container {

void setup_namespaces(); // Set up PID and mount namespaces
void setup_filesystem(); // Set up isolated filesystem (basic chroot-like)

} // namespace mini_container

#endif // NAMESPACES_H
