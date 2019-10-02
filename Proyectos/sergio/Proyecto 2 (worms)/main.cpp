#include <bits/stdc++.h>
using namespace std;
#include "gfx.h"
#include "util.h"
#include "point.h"
#include "color.h"
#include "worm.h"

int main(int argc, char * argv[]) {
  if (argc < 2) {
    cout << "Bad usage: please add number of worms" << endl;
    return 0;
  }
  int n = stoi(argv[1]);
  int wormSize = 50;
  int screenW = 500, screenH = 500;
  gfx_open(screenW, screenH, "Worms");
  vector<Worm> worms;
  for (int i = 0; i < n; i++) {
    worms.emplace_back(wormSize, screenW, screenH);
  }

  while (true) {
    gfx_clear();
    for (auto &worm : worms) {
      Color color = worm.getColor();
      gfx_color(color.R(), color.G(), color.B());
      for (auto &point : worm.getPoints()) {
        gfx_point(point.X(), point.Y());
      }
      gfx_flush();
      worm.move();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  return 0;
}