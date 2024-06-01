#include "db.hpp"

Database* Database::instance = nullptr;

Database::Database() {
  connection.reset(mysql_init(nullptr));
  if (connection == nullptr) {
    LOG(ERROR) << "mysql_init() failed";
    exit(1);
  }

  if (!mysql_real_connect(connection.get(), "localhost", "username", "password", "library_db", 0, nullptr, 0)) {
    LOG(ERROR) << "mysql_real_connect() failed: " << mysql_error(connection.get());
    mysql_close(connection.get());
    exit(1);
  }
}