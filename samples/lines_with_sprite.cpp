#include <iostream>

#include <pixel/pixel.hpp>
using namespace pixel;

int main() {
  Application app({.size = vu2d(500, 500), .name = "Lines", .clearbuffer = false,
  .on_launch = [] (Application& app) mutable -> pixel::rcode {
    app.CreateSprite("samples/test.png");

    return pixel::ok;
  },
  .on_update = [] (Application& app) mutable -> pixel::rcode {
    for (uint8_t i = 0; i < 50; i++) {
      app.DrawLine(
				vu2d(rand() % app.ScreenSize().x, rand() % app.ScreenSize().y),
				vu2d(rand() % app.ScreenSize().x, rand() % app.ScreenSize().y),
				RandPixel()
      );
    }

    app.DrawPartialSprite(app.MousePos(), vu2d(16, 16), vu2d(16, 16), 0);
    //app.DrawSprite(app.MousePos(), 0);

    if(app.Key(Key::ESCAPE).pressed) {
			app.Close();
		}

    return pixel::ok;
  }});

  app.Launch();

  return 0;
}
