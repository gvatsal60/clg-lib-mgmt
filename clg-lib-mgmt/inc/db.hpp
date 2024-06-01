#pragma once
#ifndef DB_HPP
#define DB_HPP

#include <glog/logging.h>
#include <mysql/mysql.h>

#include <memory>

class Database {
 public:
  static Database* getInstance() {
    if (instance == nullptr) {
      instance = new Database();
    }

    return instance;
  }

  MYSQL* getConnection() {
    return connection.get();
  }

  ~Database() {
    mysql_close(connection.get());
  }

 private:
  Database();

  std::unique_ptr<MYSQL> connection;
  static Database* instance;
};

#endif