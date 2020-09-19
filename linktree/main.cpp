#include "crow_all.h"
#include "static_handler.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <boost/filesystem.hpp>
#include <unistd.h>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

int main (int argc, char ** argv) {
  crow::SimpleApp app;
  mongocxx::instance inst{};
  std::string mongo_uri = std::string(getenv("MONGODB_URI"));
  lk::StaticHandler static_handler;

  mongocxx::client conn{mongocxx::uri{mongo_uri}};
  auto collection = conn["contactlist"]["contacts"];

  char * port = getenv("PORT");
  uint16_t i_port = static_cast<uint16_t> (nullptr != port ? std::stoi(port): 18080);
  std::cout << "PORT : " << i_port << std::endl;

  CROW_ROUTE(app, "/styles/<string>")
  ([static_handler] (crow::request const & req, crow::response & res, std::string filename) {
    static_handler.send_style(res, std::move(filename));
  });

  CROW_ROUTE(app, "/images/<string>")
  ([static_handler] (crow::request const & req, crow::response & res, std::string filename) {
    static_handler.send_image(res, std::move(filename));
  });

  CROW_ROUTE(app, "/scripts/<string>")
  ([static_handler] (crow::request const & req, crow::response & res, std::string filename) {
    static_handler.send_script(res, std::move(filename));
  });

  CROW_ROUTE(app, "/about")
  ([static_handler] (crow::request const & req, crow::response & res) {
    static_handler.send_html(res, "about");
  });

  CROW_ROUTE(app, "/api/contacts") 
  ([&collection](void) {
     mongocxx::options::find opts;
     opts.skip(9);
     opts.limit(10);
     auto docs = collection.find({}, opts);
     std::ostringstream os;
     for (auto && doc : docs) {
        os << bsoncxx::to_json(doc) << "\n";
     }
     return crow::response(os.str());
   });

  /*
  CROW_ROUTE(app, "/<string>")
  ([static_handler] (crow::request const & req, crow::response & res, std::string uri) {
    res.redirect("/");
    res.end();
  });
  */

  CROW_ROUTE(app, "/")
  ([static_handler] (crow::request const & req, crow::response & res) {
    static_handler.send_html(res, "index");
  });

  app.port(i_port).multithreaded().run();
  return 0;
}
