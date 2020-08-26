#include "crow_all.h"
#include "static_handler.h"
#include <unistd.h>

int main (int argc, char ** argv) {
  crow::SimpleApp app;
  hellocrow::StaticHandler static_handler;

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

  CROW_ROUTE(app, "/")
  ([static_handler] (crow::request const & req, crow::response & res) {
    static_handler.send_html(res, "index");
  });

  char * port = getenv("PORT");
  uint16_t i_port = static_cast<uint16_t> (nullptr != port ? std::stoi(port): 18080);
  std::cout << "PORT : " << i_port << std::endl;
  app.port(i_port).multithreaded().run();
  return 0;
}
