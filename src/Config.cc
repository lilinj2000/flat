// Copyright (c) 2010
// All rights reserved.

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>

#include "Config.hh"
#include "Log.hh"
#include "flyer/TraderService.hh"

namespace flat {

Options::Options():
    config_options_("FlatConfigOptions") {
  namespace po = boost::program_options;

  config_options_.add_options()
      ("flat.instrument_id", po::value<std::string>(&instrument_id),
       "instrument id")
      ("flat.price", po::value<double>(&price),
       "price")
      ("flat.volume", po::value<int>(&volume),
       "volume")
      ("flat.is_buy", po::value<bool>(&is_buy),
       "is buy")
      ("flat.order_counter", po::value<int>(&order_counter),
       "order counter")
      ("flat.order_interval", po::value<int>(&order_interval),
       "order interval")
      ("flat.log_cfg", po::value<std::string>(&log_cfg),
       "log config file")

      ("flat.timestamp_file", po::value<std::string>(&timestamp_file),
       "timestamp file");

  return;
}

Options::~Options() {
}

po::options_description* Options::configOptions() {
  return &config_options_;
}

Config::Config(int argc, char* argv[]) {
  options_.reset(new Options());
  flyer_trader_options_.reset(
      flyer::TraderService::createOptions());

  std::unique_ptr<soil::Config> config(soil::Config::create());
  config->registerOptions(options_.get());
  config->registerOptions(flyer_trader_options_.get());

  config->configFile() = "flat.cfg";
  config->loadConfig(argc, argv);

  // init the log
  FLAT_LOG_INIT(options_->log_cfg);

  return;
}

Config::~Config() {
}

}  // namespace flat
