#include "crow_all.h"

namespace hellocrow {

enum StatusCodes {
  NOT_FOUND = 404
};

class StaticHandler {

public:
    void send_file(crow::response & res, std::string && filename, std::string && content_type) const {
        std::ifstream in("../public/" + filename, std::ifstream::in);
        if (in) {
          std::ostringstream contents;
          contents << in.rdbuf();
          in.close();
          res.set_header("Content-Type", content_type); 
          res.write(contents.str());
        } else {
          res.code = NOT_FOUND;
          res.write("Not Found!!");
        }
        res.end();
    }

    void send_html(crow::response & res, std::string && filename) const {
        send_file(res, filename + ".html", "text/html");
    }

    void send_image(crow::response & res, std::string && filename) const {
        send_file(res, "images/" + filename, "image/jpeg");
    }

    void send_script(crow::response & res, std::string && filename) const {
        send_file(res, "scripts/" + filename, "text/javascript");
    }

    void send_style(crow::response & res, std::string && filename) const {
        send_file(res, "styles/" + filename, "text/css");
    }
};

}
