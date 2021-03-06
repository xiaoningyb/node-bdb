// Copyright 2011 Mark Cavage <mcavage@gmail.com> All rights reserved.
#ifndef BDB_OBJECT_H_
#define BDB_OBJECT_H_

#include <node.h>
#include <v8.h>

class Db;
class DbEnv;

class DbObject: public node::ObjectWrap {
 public:
  DbObject();
  virtual ~DbObject();

 protected:
  static int EIO_After_ReturnStatus(eio_req *req);

 private:
  DbObject(DbObject &);
  DbObject &operator=(DbObject &);

  friend class Db;
  friend class DbEnv;
};


class EIOBaton {
 public:
  explicit EIOBaton(DbObject *obj);
  virtual ~EIOBaton();

  // make these public to save on typing
  DbObject *object;
  int flags;
  int status;
  v8::Persistent<v8::Function> cb;

 private:
  EIOBaton();
  EIOBaton(const EIOBaton &);
  EIOBaton &operator=(EIOBaton &);
};

#endif  // BDB_OBJECT_H_
