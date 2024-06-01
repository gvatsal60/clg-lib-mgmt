#include "db.hpp"

int main() {
  google::InitGoogleLogging("LibraryManagement");
  FLAGS_logtostderr = 0;  // Disable logging to stderr (optional)

  // Use the library object as before

  google::ShutdownGoogleLogging();

  return 0;
}
