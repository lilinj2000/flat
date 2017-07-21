// Copyright (c) 2010
// All rights reserved.

#ifndef FLAT_SERVER_HH
#define FLAT_SERVER_HH

#include <map>
#include <string>
#include "flyer/TraderService.hh"
#include "Config.hh"
#include "air/TimeStampDataFile.hh"

namespace flat {

typedef std::map<int, air::TimeStampData*> TimeStampRecords;

class Server :
      public flyer::TraderServiceCallback {
 public:
  Server(Options* options,
         soil::Options* trader_options);

  virtual ~Server();

  virtual void onRspError(int errord_id, const std::string& error_msg);

  virtual void onRspOrderInsert(int order_ref);

  virtual void onRtnOrder(
      int order_ref,
      int error_id,
      const std::string& err_msg);

  virtual void onRtnTrade(
      int order_ref,
      double price, int volume);

  void run();

 private:
  Options* options_;
  std::unique_ptr<flyer::TraderService> trader_service_;
  TimeStampRecords records_;
  std::unique_ptr<air::TimeStampDataFile> timestamp_file_;
};

}  // namespace flat

#endif
