#pragma once
#ifndef CLG_LIB_HPP
#define CLG_LIB_HPP

#include "db.hpp"

class Library {
 public:
  Library() {
    connection = Database::getInstance()->getConnection();
  }

 private:
  MYSQL* connection;
  // Rest of the Library class methods remain the same
};

#endif