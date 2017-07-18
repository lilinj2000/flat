// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include "Config.hh"
#include "Server.hh"

int main(int argc, char* argv[]) {
  std::unique_ptr<flat::Config> config;
  config.reset(new flat::Config(argc, argv));

  flat::Options* options = config->options();

  std::unique_ptr<flat::Server> server;
  server.reset(new flat::Server(options, config->flyerTraderOptions()));

  server->run();

  return 0;
}
